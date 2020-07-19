#ifndef POST_TREE_H
#define POST_TREE_H

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Top(S)  ((S).top)

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

typedef BinTree infotypetree;
typedef struct tElmtStack *adrStackTree;
typedef struct tElmtStackTree{
	infotypetree info;
	adrStackTree next;
}elementstacktree;

typedef struct{
	adrStackTree top;
}stacktree;


void createStacktree(stacktree *s);
//prosedur untuk membuat stack kosong dengan S.top diset ke nil

int isEmptytree(stacktree s);
//fungsi untuk mengecek apakah stack tersebut dalam keadaan kosong

adrStackTree alokasiStacktree(infotypetree x);
//fungsi untuk mengalokasikan elemen stack

void pushStacktree(stacktree *s, infotypetree x);
//prosedur untuk menambahkan satu elemen

void popStacktree(stacktree *s, infotypetree x);
//prosedur untuk mengambil satu elemen teratas dari sebuah stack

void printstacktree(stacktree s);
//prosedur untuk mencetak karakter pada stack

void dealokasiStacktree (adrStackTree p);
/* Membebaskan address P */

boolean isOperator(char c); 
#endif
