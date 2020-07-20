#include "posttree.h"

void createStacktree(stacktree *s){
	Top(*s)=Nil;
}

int isEmptytree (stacktree s){
	return (Top(s)==Nil)?1:0;
}

adrStackTree alokasiStacktree(infotypetree x){
	adrStackTree p;
	
	p = (adrStackTree) malloc(sizeof(elementstack));
    if(p!=Nil){
        Info(p)=x;
        Next(p)=Nil;
    }
	return p;
}

void pushStacktree (stacktree *s, infotypetree x){
	adrStackTree p;
	
	p = alokasiStacktree(x);
	Next(p)=Top(*s);
	Top(*s)=p;
	
}

void popStacktree (stacktree *s, infotypetree x){
	adrStackTree p;
    
    if(!isEmptytree(*s)){
        p=Top(*s);
        if(Next(p)!=Nil){
	        Top(*s)=Next(p);
		}
		else{
			Top(*s)=Nil;
		}    
        x=Info(p);
        dealokasiStacktree(p);
    }else{
        printf("stackTree kosong\n");
    }
}

void dealokasiStacktree(adrStackTree p){
    free(p);
}

void printStacktree(stacktree s){
	adrStackTree p;
	isEmptytree;
    if(!isEmptytree(s)){
        p=Top(s);
        while(p!=Nil){
            printf("%.2f ",Info(p));
            p=Next(p);       
        }
        printf("\n");
    }else{
        printf("stackTree kosong\n");
    }
}

boolean isOperator(char c) 
{ 
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
		return true; 
	}
	return false; 
} 

boolean isKurung(char c){
	if (c == '(' || c == ')'){
		return true;
	}
	return false;
}




