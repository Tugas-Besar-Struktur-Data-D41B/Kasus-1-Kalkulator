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

float eval(BinTree P)  {
	int i;
	float tmp=1.0;
	  
    if (P==Nil)  
        return 0;  
   
    if (Left(P)==Nil && Right(P)==Nil)  
        return toInt(Info(P));  
  
  
    float left = eval(Left(P));  
    float right = eval(Right(P));  
    
    if (Info(P)=='+')  
        return left+right;  
  
    if (Info(P)=='-')  
        return left-right;  
  
    if (Info(P)=='*')  
        return left*right;  
        
  	if (Info(P)=='/')
  		return left/right;
  	
  	for(i=0; i<right; i++){
  		tmp *= left;
	}
	return tmp;
}  
  

int main(){
	char input[50];
    char *tpostfix, temp[20];
    float hasil;
    int i, j=0, num;
    BinTree ex;
    
    scanf(" %s",input);
    tpostfix=Convert(&input);
	printf("%s", tpostfix);
	printf("\n");
	printf("\n");
	
	ex = constructTree(tpostfix);
	PrintInfo(ex);
	hasil = eval(ex);
	printf("%.2f", hasil);
	
	return 0;
}
