#include "stackTree.h"

int isEmptyF(stackTree S){
    return (Top(S)==Nil)?1:0;
}

void createStackF(stackTree *S){
    Top(*S)=Nil;
}

addressF alokasiF(infotypeF X){
    addressF p;
    
    p=(addressF)malloc(sizeof(elmStackF));
    if(p!=Nil){
        Info(p)=X;
        Next(p)=Nil;
    }
    return p;
}

void dealokasiF(addressF P){
    free(P);
}

int findElmAddrsF(stackTree S, addressF P){
    addressF Q;
    Q=Top(S);
    while(Q!=Nil&&Q!=P)
        Q=Next(Q);
    return (Q==P);
}

void pushStackF(stackTree *S, infotypeF X){
    addressF p;
    
    p=alokasiF(X);
    Next(p)=Top(*S);
    Top(*S)=p;
}

void popStackF(stackTree *S, infotypeF X){
    addressF p;
    
    if(!isEmptyF(*S)){
        p=Top(*S);
        if(Next(p)!=Nil){
	        Top(*S)=Next(p);
		}
		else{
			Top(*S)=Nil;
		}    
        X=Info(p);
        dealokasiF(p);
    }else{
        printf("kesalahan : stackTree kosong\n");
    }
}

void printAllInfoF(stackTree S){
    addressF p;
    if(!isEmptyF(S)){
        p=Top(S);
        while(p!=Nil){
            printf("%.2f ",Info(p));
            p=Next(p);       
        }
        printf("\n");
    }else{
        printf("stackTree kosong\n");
    }
}

void deleteAllF(stackTree *S){
    infotypeF x;
    while(!isEmptyF(*S)){
        popStackF(S,x);
    }
}

boolean isOperator(char c) 
{ 
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
		return true; 
	}
	return false; 
} 


