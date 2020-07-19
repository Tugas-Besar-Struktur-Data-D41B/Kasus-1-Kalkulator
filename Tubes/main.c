/* File     : Main.c 					*/
/* Desk     : Main program Kalkulator 	*/
/* Oleh     : -Nabil Putra Hadiyani		*/
/*			  -Titis Sampurno			*/
/* Tgl	    : 12 / 07 / 2020	  		*/

#include "bintree.h"
#include "posttree.h"


BinTree constructTree(char *postfix) { 
	stacktree st;
	BinTree t, t1, t2;
	infotypetree temp;
	int i;
 	
 	createStacktree(&st);
 	
	for (i=0; i<strlen(postfix); i++) 
	{ 
		if (!isOperator(postfix[i]) && postfix[i]!=' ') 
		{
			newNode(&t, postfix[i]);  
			pushStacktree(&st, t);

		} 
		else if(postfix[i]!=' ')
		{ 
			newNode(&t, postfix[i]);
			
			t1 = Info(Top(st));
			popStacktree(&st, temp);
							 
			t2 = Info(Top(st));
			popStacktree(&st, temp);
			
			MakeTree(postfix[i], t2, t1, &t);
			
			pushStacktree(&st, t); 
		} 
	} 

	t = Info(Top(st)); 
	
	popStacktree(&st, t); 

	return t; 
} 

int toInt(char X){
	return ((int)X-48);
}

float eval(BinTree P, int arraynegatif[], int size)  {
	int j,i;
	float hasil=1.0,temp,temp2;

    if (P==Nil)  
        return 0;  
   
    if (Left(P)==Nil && Right(P)==Nil)
        return toInt(Info(P));  

	 	
    float left = eval(Left(P), arraynegatif, size);  
    float right = eval(Right(P), arraynegatif, size);  

    temp = left;
    temp2 = right;
	for(j=0;j<size;j++){
		if (temp==arraynegatif[j]){
			left=temp*(-1);
			arraynegatif[j]=0;
		}else if(temp2==arraynegatif[j]){
			right=temp2*(-1);
			arraynegatif[j]=0;
		}
	}	

    if (Info(P)=='+')  
        return left+right;  
  
    if (Info(P)=='-')  
        return left-right;  
  
    if (Info(P)=='*')  
        return left*right;  
        
  	if (Info(P)=='/')
  		return left/right;
  	
  	for(i=0; i<right; i++){
  		hasil *= left;
	}
	return hasil;
}  
  

int main(){
	char negatif[20];
	int AngkaNegatif[20];
	char input[50];
    char *tpostfix;
    float hasil;
    int i, j=0, num;
    BinTree ex;
    
    scanf(" %s",input);
    tpostfix=Convert(&input);
    int size=strlen(input);
    for(i=0; i<size; i++){
    	if (i==0 && input[0]=='-'){
    		negatif[j]=input[i+1];
    		j++;
		}else if (input[i]=='-'&&input[i-1]=='('){
			negatif[j]=input[i+1];
			j++;
		}
	}
	int oke=strlen(negatif);
    for(i=0; i<oke; i++){
    	printf ("Negatif %d = %c\n", i+1,negatif[i]);
	}
	printf("\n\n%d\n\n",oke);
	for (i=0;i<oke;i++){
		AngkaNegatif[i]=toInt(negatif[i]);
	}
	printf("%s", tpostfix);
	printf("\n");
	printf("\n");
	
	ex = constructTree(tpostfix);
	PrintInfo(ex);
	hasil = eval(ex,AngkaNegatif,oke);
	printf("%.2f", hasil);
	
	return 0;
}
