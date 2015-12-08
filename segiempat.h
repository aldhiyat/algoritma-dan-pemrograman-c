/* File : segiempat.h */
/* UTS Praktikum Kamis, 22 Okt 2015 */
/* ADT Segiempat berdasarkan ADT point */

#ifndef _SEGIEMPAT_H
#define _SEGIEMPAT_H

#include "point.h"
#include "boolean.h"

/* *** Definisi ABSTRACT DATA TYPE SEGIEMPAT *** */
typedef struct {
	POINT KiriAtas;    /* titik kiri atas dari sebuah segiempat */
	POINT KananBawah;  /* titik kanan bawah dari sebuah segiempat */
} SEGIEMPAT;

/* *** Selektor SEGIEMPAT *** */
#define PKiriAtas(P) (P).KiriAtas
#define PKananBawa(P) (P).KananBawah
//#define PKananBawa(P) (P).KananBawah

/* *** Validasi Type *** */
boolean IsValidSEGIEMPAT (POINT KA, POINT KB);
/* Menghasilkan true jika KA dan KB dapat membentuk segiempat
   dengan KA sebagai titik kiri atas dan KB sebagai titik kanan bawah */
/* Syarat: titik KA (x1,y1) harus lebih �kiri atas� dibanding titik KB (x2,y2)
   yaitu x1 < x2 dan y1 > y2 */

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
SEGIEMPAT MakeSEGIEMPAT (POINT KA, POINT KB);
/* Membentuk sebuah SEGIEMPAT dari komponen-komponennya,
   KA sebagai titik kiri atas dan KB sebagai titik kanan bawah */
/* Prekondisi: KA dan KB dapat membentuk segiempat */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaSEGIEMPAT (SEGIEMPAT * S);
/* Membaca nilai point kiri atas dan kanan bawah dari keyboard
   dan membentuk SEGIEMPAT P berdasarkan dari kedua point tersebut.
   Point kiri atas dan kanan bawah harus valid. Jika tidak valid,
   maka diberikan pesan "Masukan segiempat tidak valid" (diakhiri enter),
   dan pembacaan diulangi sampai didapatkan point-point yang membentuk segiempat
   dengan valid. */
/* I.S. Sembarang */
/* F.S. S terdefinisi */
void TulisSEGIEMPAT (SEGIEMPAT S);
/* I.S. S terdefinisi */
/* F.S. S (PKA,PKB) tertulis di layar dengan format "((PKA,PKB))"
        tanpa spasi dan enter di kiri atau kanan.
		Setiap point ditulis dengan format (X,Y). */

/* *** Operasi Lain *** */
void MirrorSEGIEMPAT (SEGIEMPAT * S, boolean SbX, boolean SbY);
/* Memindahkan S ke posisi pencerminan S tergantung nilai SbX dan SbY */
/* I.S. S terdefinisi, SbX dan SbY terdefinisi */
/* F.S. S dipindahkan pada posisi pencerminan tergantung nilai SbX dan SbY */
/* Jika SbX bernilai true, maka S dipindahkan ke posisi pencerminannya terhadap sumbu X */
/* Jika SbY bernilai true, maka S dipindahkan ke posisi pencerminannya terhadap sumbu Y */
/* Perhatikan bahwa posisi point pembentuk S harus selalu "kiri atas" dan "kanan bawah" */
int LuasSEGIEMPAT (SEGIEMPAT S);
/* Menghasilkan luas segiempat yaitu perkalian antara panjang dan lebar segimpat */
void DobelSEGIEMPAT (SEGIEMPAT * S);
/* Membentuk segiempat dengan panjang 2x dari panjang semula dan lebar 2x dari lebar semula,
   sehingga luas menjadi 4 kali dari luas semula
   Posisi titik kanan bawah (x2,y2) diubah sehingga panjang dan lebar segiempat menjadi 2 kali lipat
   dari yang sebelumnya.
   Berarti x2 harus digeser ke kanan (sejajar sumbu x) 2 kali lipat,
   sedangkan y2 harus digeser ke bawah (sejajar sumbu y) 2 kali lipat
   sehingga menjadi luas segiempat menjadi 4 kali lipat dari sebelumnya. */
/* I.S. S terdefinisi */
/* F.S. Panjang dan lebar S menjadi 2 kali lipat sebelumnya dengan menggeser titik KananBawah.
        Luas S menjadi 4 kali lipat dari sebelumnya. */
void TranslasiSEGIEMPAT (SEGIEMPAT * S, int deltaX, int deltaY);
/* I.S. S terdefinisi, deltaX dan deltaY terdefinisi */
/* F.S. S digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu y */

#endif
