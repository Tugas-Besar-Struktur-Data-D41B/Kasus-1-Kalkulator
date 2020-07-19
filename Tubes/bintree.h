/* File     : bintree.h 	*/
/* Desk     : Deklarasi Binary Tree secara rekursif  	*/
/* Oleh     : ANI RAHMANI / 23501007  			*/
/* Tgl	    : 21 / 11 / 2001	     			*/
/* Edit     : Nabil Putra Hadiyani */

#ifndef BINTREE_H
#define BINTREE_H

#define Nil NULL
#define Info(P) (P)->info
#define Left(P) (P)->left
#define Parent(P) (P)->parent
#define Right(P) (P)->right
#define Next(P) (P)->next

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "boolean.h"

typedef char infotypeT;
typedef struct tElmtNode *addressT;
typedef struct tElmtNode {
			infotypeT info;
			addressT parent;
			addressT left;
			addressT right;
		} ElmtNode;

typedef addressT BinTree;

/* ****** MANAJEMEN MEMORY ******* */
addressT Alokasi(infotypeT X);
/* Menghasilkan  addressT hasil alokasi sebuah  Node 	*/
/* Jika alokasi berhasil, maka  addressT tidak NIl   	*/
/* Info(P)=X, Left(P)=Nil,Right(P)=Nil, dan Count(P)=0 	*/
/* Jika alokasi gagal mengembalikan Nil  		*/

boolean IsEmpty(BinTree P);
/* Mengembalikan true jika pohon kosong */

void CreateEmpty(BinTree *P);
/* Membuat  Tree   kosong  */

BinTree GetParent(BinTree P);
/* Mengirimkan parent dari pohon biner P yang tidak kosong */

BinTree GetLeft(BinTree P);
/* Mengirimkan anak kiri pohon biner P  */

BinTree GetRight(BinTree P);
/* Mengirimkan anak kanan pohon biner P  */

/* ******** KONSTRUKTOR ************ */
BinTree Tree(infotypeT X, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon Biner dari A, L, dan R jika Alokasi berhasil */
/* Menghasilkan pohon kosong Nil, jika alokasi gagal 			  */

void MakeTree(infotypeT Y, BinTree L, BinTree R, BinTree *P);
/* I.S   : Sembarang 	*/
/* F.S   : Menghasilkan sebuah pohon biner P dari A,L,dan R, jika alokasi */
/*         berhasil; Menghasilkan pohon P yang kosong jika alokasi gagal  */

void BuildTree(BinTree *P);
/* Membentuk sebuah pohon biner P dari pita karakter yang dibaca 	*/
/* I.S   : Pita berisi 'kostanta' pohon dalam bentuk prefiks, memory 	*/
/*         pasti cukup, alokasi pasti berhasil 			*/
/* F.S   : P dibentuk dari Ekspresi dalam Pita   			*/

/* ************* TRAVERSAL   ************* */
void Preorder(BinTree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Preorder; akar, kiri */
/*        kanan (dengan Proses (P)) 				    */

void Inorder(BinTree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Inorder; kiri, akar  */
/*        kanan (dengan Proses (P)) 				    */

void Postorder(BinTree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Postorder; kiri,     */    
/* 	  kanan, akar (dengan Proses (P)) 			    */

void PrintTree(BinTree P);
/* I.S  : P terdefinisi, h adalah jarak indentasi	*/
/* F.S  : semua simpul P sudah ditulis 			*/

void PrintNode(BinTree P);
/* Menampilkan info-info dari suatu node pada pohon P */
/* I.S   : Pohon P pasti ada */
/* F.S   : Info-info dari suatu node pada pohon P ditampilkan */  

void PrintInfo(BinTree P);
/* Menampilkan info-info dari setiap node pada pohon P */
/* I.S   : Pohon P pasti ada */
/* F.S   : Info-info dari setiap node pada pohon P ditampilkan */  

/* ************ SEARCH **************** */
boolean Search (BinTree P, infotypeT X);
/* Mengirimkan true jika ada node dari P yang bernilai X */
/* I.S   : Pohon P pasti ada */
/* F.S   : Node dari P yang bernilai X diketahui keberadaannya. */  

addressT Search2(BinTree T, infotypeT X);
/* Mengembalikan alamat node dari P yang bernilai X */
/* I.S   : Pohon P pasti ada */
/* F.S   : Alamat node dari P yang bernilai X ddikembalikan */  

/* ************* FUNGSI LAIN *************** */
int NbElmt(BinTree P);
/* Mengirimkan banyaknya elemen (Node) pohon biner P */

int NbDaun(BinTree P);
/* Mengirimkan banyaknya daun (Node) pohon biner P */

boolean IsSkewLeft (BinTree P);
/* Mengirimkan true jika P adalah pohon condong kiri */

boolean IsSkewRight(BinTree P);
/* Mengirimkan true jika P adalah pohon condong kanan */

int Level(BinTree P, infotypeT X);
/* Mengirinkan level dari Node X yang merupakan salah satu simpul */
/* dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P  tidak */
/* kosong 	*/

void DestroyTree(BinTree *P);
/* Membebaskan memori yang sudah dialokasi oleh P	*/
/* I.S  : P terdefinisi                          	*/
/* F.S  : semua simpul P sudah ditulis / preorder	*/

#endif
