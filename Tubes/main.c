#include "bintree.h"
#include "posttree.h"
#include<stdio.h>
#include<math.h>
#include <conio.h>
#include <stdlib.h>

void rumus(){
	printf ("Rumus Penjumlahan dan Pengurangan Trigonometri\n");
	printf (" Sin(a+b) = Sin a . Cos b + Cos a . Sin b\n");
	printf (" Sin(a-b) = Sin a . Cos b - Cos a . Sin b\n");
	printf (" Cos(a+b) = Cos a . Cos b - Sin a . Sin b\n");
	printf (" Cos(a-b) = Cos a . Cos b + Sin a . Sin b\n");
	printf (" Tan(a+b) = (Tan a + Tan b)/(1-Tan a Tan b)\n");
	printf (" Tan(a-b) = (Tan a - Tan b)/(1-Tan a Tan b)\n");
	printf (" Sin a + Sin b = 2 Sin((a+b)/2) Cos ((a-b)/2)\n");	
	printf (" Sin a - Sin b = 2 Cos((a+b)/2) Sin ((a-b)/2)\n");
	printf (" Cos a + Cos b = 2 Cos((a+b)/2) Cos ((a-b)/2)\n");
	printf (" Cos a - Cos b = -2 Sin((a+b)/2) Sin ((a-b)/2)\n");
	getch();
	system("cls");
}

void input(){
	int y;
	printf ("Masukan besar sudut : ");
	scanf("%d", &y);
	printf ("SIN %d = %f\n", y, sin(y/57.2958));
	printf ("COS %d = %f\n", y, cos(y/57.2958));
	printf ("TAN %d = %f\n", y, sin(y/57.2958)/cos(y/57.2958));
	getch();
	system("cls");
}

void tabeltrigonometri(){
	int x;
    printf("		TABEL TRIGONOMETRI\n\n");
    printf("x	 | SIN(x)	| COS(x)	|TAN(x)	\n");
    for(x=0; x<=360; x+=15){
        printf("%d	 | %f	| %f	| %f	\n",x,sin(x/57.2958),cos(x/57.2958), sin(x/57.2958)/cos(x/57.2958));
    }
    getch();
    system("cls");
}

void menu(){
	int pilihan;
	printf("KAMUS TRIGONOMETRI\n");
	printf("1. TABEL TRIGONOMETERI\n");
	printf("2. INPUT SUDUT\n");
	printf("3. RUMUS\n");
	printf("4. EXIT TRIGONOMETRI\n");
	printf("Masukan Pilihan: ");
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1: 
			system("cls");
			tabeltrigonometri();
			menu();
			break;
		case 2:
			system("cls");
			input();
			menu();		
			break;
		case 3:
			system("cls");
			rumus();
			menu();
			break;
		case 4:
			system("cls");
			main();
			break;
	}
}

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

float eval(BinTree P, int arraynegatif[], int size, int arraypuluhan[])  {
	int j,i;
	float hasil=1.0,temp,temp2,puluhan;

    if (P==Nil)  
        return 0;  
    
    if (Left(P)==Nil && Right(P)==Nil){
    	if(Info(P)=='a'){
    		for(j=0;j<size;j++){
				if(arraypuluhan[j]!=0){
					puluhan = arraypuluhan[j];
					arraypuluhan[j] = 0;
					return puluhan;
				}
			}
		}else{
			return toInt(Info(P));
		}
 	}
          
	 	
    float left = eval(Left(P), arraynegatif, size, arraypuluhan);  
    float right = eval(Right(P), arraynegatif, size, arraypuluhan);  
	
	//Mengubah menjadi negatif
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
	//Selesai mengubah menjadi negatif	

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
	char negatif[20],puluhan[10];
	int AngkaNegatif[20],AngkaPuluhan[10];
	char input[50];
    char *tpostfix;
    float hasil;
    int i, j=0, num, pilihan,k;
    BinTree ex;
    
    printf("KALKULATOR\n");
    printf("1. KALKULATOR\n");
    printf("2. KAMUS TRIGONOMETRI\n");
    printf("3. EXIT\n");
    printf("Masukan Pilihan: ");
    scanf("%d", &pilihan);
    switch (pilihan){
    	case 1:
    		system("cls");
    		printf("Keterangan : Angka negatif ditengah menggunakan tanda kurung\n\n");
    		printf("Masukan String = ");
    		scanf(" %s",input);
		    tpostfix=Convert(&input);
		    int size=strlen(input);
			//cari input puluhan
			j=0,k=0;
			for(i=0;i<10;i++){
				AngkaPuluhan[i]=0;
			}
			for(i=0; i<size; i++){
				if (isAngka(input[i+1])|| isAngka(input[i-1])){
			    	if(!isOperator(input[i])){
			    		puluhan[j]=input[i];
			    		j++;
			    		puluhan[j]='\0';
			    		if(isOperator(input[i+1]) || i+1==size){
			    			j=0;
			    			AngkaPuluhan[k] = atoi(puluhan);
			    			k++;
						}
					}
				}
			}
		
			//selesai cari input puluhan		    
			//cari input negatif
			j=0,k=0;
		    for(i=0; i<size; i++){
		    	if (i==0 && input[0]=='-'){
		    		negatif[j]=input[i+1];
		    		j++;
				}else if (input[i]=='-'&&input[i-1]=='('){
					negatif[j]=input[i+1];
					j++;
				}
			}
			int jumlahN=strlen(negatif);
			for (i=0;i<jumlahN;i++){
				AngkaNegatif[i]=toInt(negatif[i]);
			}
			//selesai cari input negatif
			
			printf("\n");
			printf("\n");
			

			ex = constructTree(tpostfix);
			hasil = eval(ex,AngkaNegatif,jumlahN,AngkaPuluhan);
			printf("%.2f", hasil);
			getch();
			system ("cls");
			main();
			break;
		
		case 2:
			system("cls");
			menu();
			break; 
			
		case 3:
			break;
	}
    
    
}
