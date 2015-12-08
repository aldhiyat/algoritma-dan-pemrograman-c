/* Tanggal: 24 September 2014 */
/* ADT Point */
/* Berisi definisi type dan primitif untuk POINT */

#ifndef _POINT_h
#define _POINT_h

#include "boolean.h"
#include "math.h"
#include "assert.h"

#define PI 3.14159265

/* *** Definisi ABSTRACT DATA TYPE POINT *** */
typedef struct {
	float X;  /* absis   */
	float Y;  /* ordinat */
} POINT;

/* *** Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P); 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P);
/* I.S. P terdefinisi */
/* F.S. P tertulis di layer dengan format "(X,Y)" */                

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P);
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P);
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P);
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P);
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan Titik Origin, dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
float Jarak0 (POINT P);
/* Menghitung jarak P ke (0,0) */
float Jarak (POINT P1, POINT P2);
/* Menghitung jarak antara 2 POINT */
void Mirror (POINT * P, boolean SbX, boolean SbY);
/* Memindahkan P ke posisi pencerminan P tergantung nilai SbX dan SbY */
/* I.S. P terdefinisi, SbX dan SbY terdefinisi */
/* F.S. P dipindahkan pada posisi pencerminan tergantung nilai SbX dan SbY */
/* Jika SbX bernilai true, maka P dipindahkan ke posisi pencerminannya terhadap sumbu X */
/* Jika SbY bernilai true, maka P dipindahkan ke posisi pencerminannya terhadap sumbu Y */
void Translasi (POINT * P, float deltaX, float deltaY);
/* I.S. P terdefinisi, deltaX dan deltaY terdefinisi */
/* F.S. P digeser sebesar deltaX dan ordinatnya sebesar deltaY */
void Putar (POINT * P, float Sudut);
/* I.S. P terdefinisi dan Sudut terdefinisi */
/* F.S. P diputar sebesar Sudut derajat terhadap Titik Origin searah jarum jam */

#endif


