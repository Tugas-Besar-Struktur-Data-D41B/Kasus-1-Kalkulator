/* File     : bintree.c 					*/
/* Desk     : Body primitif Binary Tree secara rekursif 	*/
/* Oleh     : ANI RAHMANI / 23501007			*/
/* Tgl	    : 21 / 11 / 2001	  			*/
/* Edit     : Nabil Putra Hadiyani */

#include "bintree.h"

/* ****** MANAJEMEN MEMORY ******* */
addressT Alokasi(infotypeT X)
{  /* Menghasilkan addressT hasil alokasi sebuah Node */
   /* Jika alokasi berhasil, maka addressT tidak Nil  */
   /* Info(P)=X, Left(P)=Nil,Rigr(P)=Nil; Count(P)=0 */	
   /* Jika alokasi gagal ; mengembalikan  Nil 	     */
   addressT P;

   P=(addressT)malloc(sizeof(ElmtNode));   
   if(P!=Nil)
   {
	Info(P)=X;
	Left(P)=Nil;
	Right(P)=Nil;	 
	Parent(P)=Nil;
   }
   return P;
}

boolean IsEmpty(BinTree P)
{  /*  Mengembalikan true jika pohon kosong  */
	return (P==Nil);
}

void CreateEmpty(BinTree *P)
{	/* I.S	: Pohon tidak ada.  */
	/* F.S	: Pohon sudah ada, namun masih kosong.  */
	*P = Nil;
}

infotypeT GetAkar(BinTree P)
{ /* Mengirimkan informasi yang tersimpan di Akar pohon biner P */
  /* tidak kosong */
   return Info(P);	
}

BinTree GetParent(BinTree P)
{ /* Mengirimkan parent dari pohon biner P yang tidak kosong */
    return Parent(P); 	
}

BinTree GetLeft(BinTree P)
{ /* Mengirimkan anak kiri dari pohon biner P yang tidak kosong */
    return Left(P); 	
}

BinTree GetRight(BinTree P)
{ /* Mengirimkan anak kanan dari pohon pohon biner P yang tidak kosong */
    return Right(P);
}

/* ***************** KONSTRUKTOR ****************  */

void  newNode(BinTree *P, infotype X) 
{   
	*P=Alokasi(X);
	if(*P!=Nil)
	{   Info(*P)=X;
	    Left(*P)=Right(*P)=Parent(*P)=Nil;
	} 
} 


BinTree Tree(infotypeT X, BinTree L, BinTree R)
{ /* Menghasilkan sebuah pohon Biner dari A, L, dan R jika Alokasi berhasil */
  /* Menghasilkan pohon kosong Nil, jika alokasi gagal 			  */
    addressT P;
    
	P=Alokasi(X);
	if(P!=Nil)
	{   Info(P)=X;
	    Left(P)=L;
        Right(P)=R;	    
        Parent(P)=P;
	}
	return (P);
}

void MakeTree(infotypeT X, BinTree L, BinTree R, BinTree *P)
{  /* I.S   : Sembarang 	*/
   /* F.S   : Menghasilkan sebuah pohon biner P dari A,L,dan R, jika alokasi */
   /*         berhasil; Menghasilkan pohon P yang kosong jika alokasi gagal  */
	*P=Alokasi(X);
       	if(*P!=Nil)
		{  	Info(*P)=X;
	   		Left(*P)=L;
	   		Right(*P)=R;	
        	Parent(*P)=*P;
		}
}

void BuildTree(BinTree *P)
{ 	/* Membentuk sebuah pohon biner P dari pita karakter yang dibaca 	*/
  	/* I.S   : Pita berisi 'kostanta' pohon dalam bentuk prefiks, memory 	*/
  	/*         pasti cukup, alokasi pasti berhasil 			*/
  	/* F.S   : P dibentuk dari Ekspresi dalam Pita   			*/
}


/* ************* TRAVERSAL   ************* */
void Preorder(BinTree P)
{  /* I.S  : P terdefinisi   					       */
   /* F.S  : semua simpul P sudah diproses secara Preorder; akar, kiri */
   /*        kanan (dengan Proses (P)) 				       */
   /* Basis : pohon kosong  : tidak ada yang diproses		       */
   /* Rekurens : Prosees Akar(P); Proses secara Preorder(Left(P));     */	
   /*            Proses secara  Preorder(Right(P)); 		       */ 	
	if(P !=Nil)
	{
		printf("%c ",Info(P));   
		Preorder(Left(P));
		Preorder(Right(P));
    }		   
}

void Inorder(BinTree P)
{  /* I.S  : P terdefinisi   					      */
   /* F.S  : semua simpul P sudah diproses secara Inorder; kiri, akar */
   /*        kanan (dengan Proses (P)) 				      */
	if(P!=Nil)
	{
	     Inorder(Left(P));	
	     printf("%c ",Info(P));
	     Inorder(Right(P));
	}
}

void Postorder(BinTree P)
{  /* I.S  : P terdefinisi   					    */
   /* F.S  : semua simpul P sudah diproses secara Postorder; kiri,  */    
   /* 	     kanan, akar (dengan Proses (P)) 			    */
	if(P!=Nil)
	{
	    Postorder(Left(P));	
	    Postorder(Right(P));
	    printf("%c ",Info(P));
	}
}

void PrintTree(BinTree P)
{   /* I.S  : P terdefinisi                          	*/
    /* F.S  : semua simpul P sudah ditulis / preorder	*/
	if(P!=Nil)
	{
	    printf("%c ",Info(P));
	    PrintTree(Left(P));
	    PrintTree(Right(P));	
	}
}

void PrintNode(BinTree P)
{	/* Menampilkan info-info dari suatu node pada pohon P */
	/* I.S   : Pohon P pasti ada */
  	/* F.S   : Info-info dari suatu node pada pohon P ditampilkan */  
	BinTree L, R, Px;
	if(P != Nil){
		printf("\nInfo Node\t: %c\n",Info(P));
		if(GetLeft(P)!=Nil){
			L = GetLeft(P);
			printf("Left Son\t: %c\n",Info(L));
		}
		else{
			printf("Left Son\t: null\n");
		}
		if(GetRight(P)!=Nil){
			R = GetRight(P);
			printf("Right Son\t: %c",Info(R));
		}
		else{
			printf("Right Son\t: null");
		}	
		printf("\n");  
	}
}

void PrintInfo(BinTree P)
{	/* Menampilkan info-info dari setiap node pada pohon P */
	/* I.S   : Pohon P pasti ada */
  	/* F.S   : Info-info dari setiap node pada pohon P ditampilkan */  
	BinTree L, R, Px;
	
	if(P != Nil){
		PrintInfo(Left(P)); 
		printf("Info Node\t: %c\n",Info(P));
		if(GetLeft(P)!=Nil){
			L = GetLeft(P);
			printf("Left Son\t: %c\n",Info(L));
		}
		else{
			printf("Left Son\t: null\n");
		}
		if(GetRight(P)!=Nil){
			R = GetRight(P);
			printf("Right Son\t: %c\n",Info(R));
		}
		else{
			printf("Right Son\t: null\n");
		}	
		printf("\n");  
		PrintInfo(Right(P));
	}
}


/* ************ SEARCH **************** */
boolean Search (BinTree P, infotypeT X)
{	/* Mengirimkan true jika ada node dari P yang bernilai X */
	/* I.S   : Pohon P pasti ada */
  	/* F.S   : Node dari P yang bernilai X diketahui keberadaannya. */  
	if (IsEmpty(P)) {
		return false;
	}
	if (X==Info(P)) {
		return true;
	}
	else {
		return (Search(Left(P), X) || Search(Right(P), X));
	}
}

addressT Search2(BinTree T, infotypeT X) 
{	/* Mengembalikan alamat node dari P yang bernilai X */
	/* I.S   : Pohon P pasti ada */
  	/* F.S   : Alamat node dari P yang bernilai X ddikembalikan */ 
    addressT L,R;	
    
    if (T == Nil) {
       return Nil;	    
    } else {
       if (Info(T)!=X) {
          L = Search2(Left(T),X);
 	  if (L == Nil) 
	     return Search2(Right(T),X);
	  else 
	     return L;
       } else {
	  return T;      
       }
    }
}

/* ************ FUNGSI LAIN **************** */
void DestroyTree(BinTree *P)
{   /* Membebaskan memori yang sudah dialokasi oleh P	*/
	/* I.S  : P terdefinisi                          	*/
    /* F.S  : semua simpul P sudah ditulis / preorder	*/
   
   if(!IsEmpty(*P)) {
	 DestroyTree(&(Left(*P)));
	 DestroyTree(&(Right(*P))); 
   	 free(*P);
	 *P=Nil;
   }
}

int Prior(char x)
{
    switch(x)
    {
        case ')': return 0;
        case '(': return 0;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
		case '^': return 3;    
    }
}

int Priority(char a, char b){
    return (Prior(a)>=Prior(b));
}

char *Convert(char *infix){
    int i, index=0, size;
    char *postfix, tmpchar;
    stack tmp;
    
    createStack(&tmp);
    postfix=(char*)malloc(sizeof(char)*100);
    
    size=strlen(infix);
    for(i=0; i<size; i++){
        switch(infix[i]){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                postfix[index]=infix[i];
                index++;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                postfix[index]=' ';
                index++;            
                if(isEmpty(tmp)){
                    pushStack(&tmp,infix[i]);
                }else if(!Priority(Info(Top(tmp)),infix[i])){
                    pushStack(&tmp,infix[i]);
                }else{
                    while(!isEmpty(tmp)&&Priority(Info(Top(tmp)),infix[i])){
                        popStack(&tmp,&tmpchar);
                        postfix[index]=tmpchar;
                        index++;
                    }                
                    pushStack(&tmp,infix[i]);
                }
                break;
            case ')':
                while(!isEmpty(tmp)&&Info(Top(tmp))!='('){
                        popStack(&tmp,&tmpchar);
                        postfix[index]=tmpchar;
                        index++;                    
                }
                popStack(&tmp,&tmpchar);
                break;
            case '(':
                pushStack(&tmp,infix[i]);
                break;
        }
    }
    while(!isEmpty(tmp)){
            popStack(&tmp,&tmpchar);
            postfix[index]=tmpchar;
            index++;                  
    }    
    postfix[index]='\0';
    return postfix;
}
