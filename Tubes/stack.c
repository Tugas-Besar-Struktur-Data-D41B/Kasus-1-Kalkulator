#include "stack.h"

void createStack(stack *s){
	Top(*s)=Nil;
}

adrStack alokasiStack(infotype x){
	adrStack p;
	p = (adrStack) malloc (sizeof (elementstack ));
	if(p!=Nil){
        Info(p)=x;
        Next(p)=Nil;
    }
	return p;
}

int isEmpty(stack S){
    return (Top(S)==Nil)?1:0;
}

void pushStack (stack *s, infotype x){
	adrStack p;
	
	p = alokasiStack(x);
	Next(p)=Top(*s);
    Top(*s)=p;
	
}

void popStack (stack*S, infotype *x){
	adrStack p;
    
    if(!isEmpty(*S)){
        p=Top(*S);
        Top(*S)=Next(p);
        *x=Info(p);
        dealokasiStack(p);
    }else{
        printf("Stack kosong\n");
    }
}

void dealokasiStack(adrStack p){
    free(p);
}

void printStack(stack s){
	adrStack p;
    if(!isEmpty(s)){
        p=Top(s);
        while(p!=Nil){
            printf("%d ",Info(p));
            p=Next(p);       
        }
        printf("\n");
    }else{
        printf("Stack kosong\n");
    }
}





