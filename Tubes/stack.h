#ifndef STACK_H
#define STACK_h

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Top(S)  ((S).top)

#include <stdio.h>
#include <stdlib.h>

typedef char infotype;
typedef struct tElmtStack *adrStack;
typedef struct tElmtStack{
	infotype info;
	adrStack next;
}elementstack;

typedef struct{
	adrStack top;
}stack;


void createStack(stack *s);
//prosedur untuk membuat stack kosong dengan S.top diset ke nil

adrStack alokasiStack(infotype x);
//fungsi untuk mengalokasikan elemen stack

int isEmpty(stack S);
//fungsi untuk mengecek apakah stack tersebut dalam keadaan kosong

void pushStack(stack *s, infotype x);
//prosedur untuk menambahkan satu elemen

void popStack(stack *S, infotype *x);
//prosedur untuk mengambil satu elemen teratas dari sebuah stack

void printstack(stack s);
//prosedur untuk mencetak karakter pada stack

void dealokasiStack(adrStack p);
/* Membebaskan address P */

#endif
