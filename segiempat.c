/* File : segiempat.h */
/* Praktikum 18, 17 Nov 2015 */
/* ADT Segiempat berdasarkan ADT point */
/* Yudi Ahmad Hambali - 23515023 */
#include "segiempat.h"
#include "point.h"
#include "boolean.h"
#include <stdio.h>

/* *** Validasi Type *** */
boolean IsValidSEGIEMPAT (POINT KA, POINT KB) {
/* Menghasilkan true jika KA dan KB dapat membentuk segiempat
   dengan KA sebagai titik kiri atas dan KB sebagai titik kanan bawah */
/* Syarat: titik KA (x1,y1) harus lebih ?kiri atas? dibanding titik KB (x2,y2)
   yaitu x1 < x2 dan y1 > y2 */
   return ((Absis(KA) < Absis(KB)) && (Ordinat(KA) > Ordinat(KB)));
}
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
SEGIEMPAT MakeSEGIEMPAT (POINT KA, POINT KB) {
/* Membentuk sebuah SEGIEMPAT dari komponen-komponennya,
   KA sebagai titik kiri atas dan KB sebagai titik kanan bawah */
/* Prekondisi: KA dan KB dapat membentuk segiempat */
	SEGIEMPAT S;

	(S).KiriAtas.X = Absis(KA);
	(S).KiriAtas.Y = Ordinat(KA);
    (S).KananBawah.X = Absis(KB);
    (S).KananBawah.Y = Ordinat(KB);
	/*PKiriAtas(S).X = Absis(KA);
	PKiriAtas(S).Y = Ordinat(KA);
	PKananBawa(S).X = Absis(KB);
	PKananBawa(S).Y = Ordinat(KB);*/

	return S;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaSEGIEMPAT (SEGIEMPAT * S) {
/* Membaca nilai point kiri atas dan kanan bawah dari keyboard
   dan membentuk SEGIEMPAT P berdasarkan dari kedua point tersebut.
   Point kiri atas dan kanan bawah harus valid. Jika tidak valid,
   maka diberikan pesan "Masukan segiempat tidak valid" (diakhiri enter),
   dan pembacaan diulangi sampai didapatkan point-point yang membentuk segiempat
   dengan valid. */
/* I.S. Sembarang */
/* F.S. S terdefinisi */
	POINT KA, KB;
	boolean Valid = false;

    do{
        scanf("%f %f", &Absis(KA), &Ordinat(KA));
        scanf("%f %f", &Absis(KB), &Ordinat(KB));
        if(IsValidSEGIEMPAT(KA, KB)){
            Valid = true;

            *S = MakeSEGIEMPAT(KA, KB);
        }else{
            printf("Masukkan segiempat tidak valid\n");
        }
    }while(Valid != true);
}
void TulisSEGIEMPAT (SEGIEMPAT S) {
/* I.S. S terdefinisi */
/* F.S. S (PKA,PKB) tertulis di layar dengan format "((PKA,PKB))"
        tanpa spasi dan enter di kiri atau kanan.
		Setiap point ditulis dengan format (X,Y). */
	printf("((%0.f,%0.f),(%0.f,%0.f))\n", PKiriAtas(S).X, PKiriAtas(S).Y, PKananBawa(S).X, PKananBawa(S).Y);
}
/* *** Operasi Lain *** */
void MirrorSEGIEMPAT (SEGIEMPAT * S, boolean SbX, boolean SbY) {
/* Memindahkan S ke posisi pencerminan S tergantung nilai SbX dan SbY */
/* I.S. S terdefinisi, SbX dan SbY terdefinisi */
/* F.S. S dipindahkan pada posisi pencerminan tergantung nilai SbX dan SbY */
/* Jika SbX bernilai true, maka S dipindahkan ke posisi pencerminannya terhadap sumbu X */
/* Jika SbY bernilai true, maka S dipindahkan ke posisi pencerminannya terhadap sumbu Y */
/* Perhatikan bahwa posisi point pembentuk S harus selalu "kiri atas" dan "kanan bawah" */
	int temp = 0;
	if(SbX) {
		temp = PKiriAtas(*S).Y;
		PKiriAtas(*S).X = PKiriAtas(*S).X;
		PKiriAtas(*S).Y = PKananBawa(*S).Y * (-1);
		PKananBawa(*S).X = PKananBawa(*S).X;
		PKananBawa(*S).Y = temp * (-1);
	} else {
	    temp = PKiriAtas(*S).X;
		PKiriAtas(*S).X = PKananBawa(*S).X * (-1);
		PKiriAtas(*S).Y = PKiriAtas(*S).Y;
		PKananBawa(*S).X = temp * (-1);
		PKananBawa(*S).Y = PKananBawa(*S).Y;
	}
}
int LuasSEGIEMPAT (SEGIEMPAT S) {
/* Menghasilkan luas segiempat yaitu perkalian antara panjang dan lebar segimpat */
	int hasil = 0;
	//hasil = ((S.KananBawah.X - S.KiriAtas.X) * (S.KiriAtas.Y - S.KananBawah.Y));
	hasil = ((PKananBawa(S).X - PKiriAtas(S).X) * (PKiriAtas(S).Y - PKananBawa(S).Y));

	return hasil;
}
void DobelSEGIEMPAT (SEGIEMPAT * S) {
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
	(*S).KananBawah.X = (*S).KananBawah.X +  ((*S).KananBawah.X - (*S).KiriAtas.X);
	(*S).KananBawah.Y = (*S).KananBawah.Y -  ((*S).KiriAtas.Y - (*S).KananBawah.Y);

	//PKananBawa(*S).X = PKananBawa(*S).X + (PKananBawa(S).X - PKiriAtas(S).X);
	//PKananBawa(*S).Y = PKananBawa(*S).Y + (PKiriAtas(S).X - PKananBawa(S).Y);
}

void TranslasiSEGIEMPAT (SEGIEMPAT * S, int deltaX, int deltaY) {
/* I.S. S terdefinisi, deltaX dan deltaY terdefinisi */
/* F.S. S digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu y */
    (*S).KananBawah.X = PKananBawa(*S).X - deltaX;
    (*S).KananBawah.Y = PKananBawa(*S).Y - deltaY;
    (*S).KiriAtas.X = PKiriAtas(*S).X + deltaX;
    (*S).KiriAtas.Y = PKiriAtas(*S).Y + deltaY;
    /*if((*S).KiriAtas.X > 0 && (*S).KiriAtas.Y > 0){
        (*S).KananBawah.X = PKananBawa(*S).X - deltaX;
        (*S).KananBawah.Y = PKananBawa(*S).Y - deltaY;
        (*S).KiriAtas.X = PKiriAtas(*S).X - deltaX;
        (*S).KiriAtas.Y = PKiriAtas(*S).Y - deltaY;
    }else if((*S).KiriAtas.X < 0 && (*S).KiriAtas.Y > 0){
        (*S).KananBawah.X = PKananBawa(*S).X + deltaX;
        (*S).KananBawah.Y = PKananBawa(*S).Y + deltaY;
        (*S).KiriAtas.X = PKiriAtas(*S).X - deltaX;
        (*S).KiriAtas.Y = PKiriAtas(*S).Y - deltaY;
    }else if((*S).KiriAtas.X < 0 && (*S).KiriAtas.Y < 0){
        (*S).KananBawah.X = PKananBawa(*S).X + deltaX;
        (*S).KananBawah.Y = PKananBawa(*S).Y + deltaY;
        (*S).KiriAtas.X = PKiriAtas(*S).X + deltaX;
        (*S).KiriAtas.Y = PKiriAtas(*S).Y + deltaY;
    }else{
        (*S).KananBawah.X = PKananBawa(*S).X - deltaX;
        (*S).KananBawah.Y = PKananBawa(*S).Y - deltaY;
        (*S).KiriAtas.X = PKiriAtas(*S).X + deltaX;
        (*S).KiriAtas.Y = PKiriAtas(*S).Y + deltaY;
    }*/
	/*if(((*S).KiriAtas.X > 0) && ((*S).KiriAtas.Y > 0)) { /* Kuadran 1 */
		/* X dikurangi, Y dikurangi */
		/*(*S).KiriAtas.X = (*S).KiriAtas.X - deltaY;
		(*S).KananBawah.X = (*S).KananBawah.X - deltaY;
		(*S).KiriAtas.Y = (*S).KiriAtas.Y - deltaX;
		(*S).KananBawah.Y = (*S).KananBawah.Y - deltaY;

		/*PKiriAtas(*S).X = PKiriAtas(*S).X - deltaY;
		PKananBawa(*S).X = PKananBawa(*S).X - deltaY;
		PKiriAtas(*S).Y = PKiriAtas(*S).Y - deltaX;
		PKananBawa(*S).Y = PKananBawa(*S).Y - deltaX;*/
	//} else if((PKiriAtas(*S).X < 0) && (PKiriAtas(*S).Y > 0)) { /* Kuadran 2 */
		/* X ditambah, Y dikurangi */
		/*(*S).KiriAtas.X = (*S).KiriAtas.X + deltaY;
		(*S).KananBawah.X = (*S).KananBawah.X + deltaY;
		(*S).KiriAtas.Y = (*S).KiriAtas.Y - deltaX;
		(*S).KananBawah.Y = (*S).KananBawah.Y - deltaY;

		/*PKiriAtas(*S).X = PKiriAtas(*S).X + deltaY;
		PKananBawa(*S).X = PKananBawa(*S).X + deltaY;
		PKiriAtas(*S).Y = PKiriAtas(*S).Y - deltaX;
		PKananBawa(*S).Y = PKananBawa(*S).Y - deltaX;*/
	//} else if((PKiriAtas(*S).X < 0) && (PKiriAtas(*S).Y < 0)) { /* Kuadran 3 */
		/* X ditambah, Y ditambah */

		/*(*S).KiriAtas.X = (*S).KiriAtas.X + deltaY;
		(*S).KananBawah.X = (*S).KananBawah.X + deltaY;
		(*S).KiriAtas.Y = (*S).KiriAtas.Y + deltaX;
		(*S).KananBawah.Y = (*S).KananBawah.Y + deltaY;
		/*
		PKiriAtas(*S).X = PKiriAtas(*S).X + deltaY;
		PKananBawa(*S).X = PKananBawa(*S).X + deltaY;
		PKiriAtas(*S).Y = PKiriAtas(*S).Y + deltaX;
		PKananBawa(*S).Y = PKananBawa(*S).Y + deltaX;*/
	//} else {
		/* X dikurangi, Y ditambah */
		/*(*S).KiriAtas.X = (*S).KiriAtas.X - deltaY;
		(*S).KananBawah.X = (*S).KananBawah.X - deltaY;
		(*S).KiriAtas.Y = (*S).KiriAtas.Y + deltaX;
		(*S).KananBawah.Y = (*S).KananBawah.Y + deltaY;
		/*
		PKiriAtas(*S).X = PKiriAtas(*S).X - deltaY;
		PKananBawa(*S).X = PKananBawa(*S).X - deltaY;
		PKiriAtas(*S).Y = PKiriAtas(*S).Y + deltaX;
		PKananBawa(*S).Y = PKananBawa(*S).Y + deltaX;*/
	//}
}
