#ifndef STACK_TREE_H
#define STACK_TREE_H

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Top(S)  ((S).top)

#include<stdio.h>
#include<stdlib.h>
#include "bintree.h"

typedef BinTree infotypeF;
typedef struct tElmF *addressF;
typedef struct tElmF{
    infotypeF info;
    addressF next;
}elmStackF;
typedef struct{
    addressF top;
}stackTree;


int isEmptyF(stackTree S);
/* Mengembalikan nilai boolean true jika stack kosong */
/* I.S   : S terdefinisi */
/* F.S   : S diketahui kosong atau tidaknya */

void createStackF(stackTree *S);
/* Membuat sebuah stack kosong */
/* I.S   : S tidak ada sebelumnya */
/* F.S   : Menghasilkan stack kosong jika alokasi berhasil */

addressF alokasiF(infotypeF X);
/* Menghasilkan address hasil alokasi */
/* I.S   : X belum dialokasi */
/* F.S   : Menghasilkan address X yang sudah dialokasi */

void dealokasiF(addressF P);
/* Membebaskan address P */
/* I.S   : P pasti ada */
/* F.S   : P berhasil didealokasi */

int findElmAddrsF(stackTree S, addressF P);
/* Mengembalikan address dari elemen yang dicari */
/* I.S   : S pasti ada */
/* F.S   : Menghasilkan address P */

void pushStackF(stackTree *S, infotypeF X);
/* Memasukkan elemen ke dalam stack */
/* I.S   : S terdefinisi */
/* F.S   : Elemen X ditambahkan ke dalam stack S */ 

void popStackF(stackTree *S, infotypeF X);
/* Menghapus elemen dari dalam stack */
/* I.S   : X merupakan elemen S */
/* F.S   : Elemen X dihapuskan dari stack S */ 

void deleteAllF(stackTree *S);
/* Menghapus semua elemen dari dalam stack */
/* I.S   : S pasti ada */
/* F.S   : Semua elemen dihapuskan dari stack S */ 

void printAllInfoF(stackTree S);
/* Menempilkan semua elemen stack */
/* I.S   : S pasti ada */
/* F.S   : Semua elemen stack S ditampilkan */

#endif
