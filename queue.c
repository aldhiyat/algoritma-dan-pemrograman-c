
#include "queue.h"
#include <stdio.h>

/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
boolean IsEmpty (Queue Q)
{
/* Mengirim true jika Q kosong: lihat definisi di atas */
return (Head(Q)==Nil && Tail(Q)==Nil);
}
boolean IsFull(Queue Q)
{
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
return (NBElmt(Q)==MaxEl(Q));
}
int NBElmt(Queue Q)
{
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
if(Head(Q)>Tail(Q))
{
    return (MaxEl(Q)-((Head(Q)-Tail(Q))-1));
}
else if(Tail(Q)>Head(Q))
{
    return ((Tail(Q)-Head(Q))+1);
}
else if((Head(Q)==Tail(Q)) && !IsEmpty(Q))
{
    return 1;
}
else
{
    return 0;
}
}

/*** Konstruktor/Kreator ***/
void CreateEmpty(Queue *Q, int Max)
{
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dengan MaxEl = 0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
MaxEl(*Q)=Max;
Tail(*Q)=Nil;
Head(*Q)=Nil;
(*Q).T = (float*)malloc(sizeof(float)*Max);
}

/*** Destruktor ***/
void DeAlokasi(Queue *Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
MaxEl(*Q)=0;
Tail(*Q)=Nil;
Head(*Q)=Nil;
free((*Q).T);
}

/*** Primitif Add/Delete ***/
void Add (Queue * Q, float X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
/* Jika Tail(Q)=MaxEl maka Tail(Q) diset ke-0  */
    if(!IsFull(*Q)){
        if(IsEmpty(*Q)){
            Head(*Q)=0;
            Tail(*Q)=0;
        }
        else if(Tail(*Q)==MaxEl(*Q)){
            Tail(*Q)=0;
        }
        else{
            Tail(*Q)++;
        }
        (*Q).T[Tail(*Q)]=X;
    }
}
void Del (Queue * Q, float *X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.,HEAD "maju"; Q mungkin kosong */
    if(!IsEmpty(*Q)){
        if(NBElmt(*Q)==1){
            *X=(*Q).T[Head(*Q)];
            Tail(*Q)=Nil;
            Head(*Q)=Nil;
        }
        else{
            *X=(*Q).T[Head(*Q)];
            Head(*Q)++;
        }
    }
}

/*** Iterate isi Queue ***/
float peek (Queue Q, int i){
/* Prekondisi: Q tidak kosong */
/* Menghasilkan nilai Q pada indeks ke-i tanpa mengubah state dari Queue */
    return ((Q).T[i]);
}
void iterate(Queue Q){
/* menuliskan isi Q dari Head ke Tail menggunakan peek */
/* tidak menuliskan apa pun jika S kosong */
/* I.S.: Q terdefinisi */
/* F.S. Isi Q tertulis ke layar dari Head ke Tail dengan dua digit di belakang koma.
        Setiap elemen dituliskan sebagai satu baris. */
    int i;
    if(Head(Q)<Tail(Q)){
        for(i=Head(Q);i<=Tail(Q);i++){
            printf("%0.2f\n",peek(Q,i));
        }
    }
    else if((Head(Q)==Tail(Q)) && !IsEmpty(Q)){
        printf("%0.2f\n",peek(Q,Head(Q)));
    }
    else if(Head(Q)>Tail(Q)){
        i=Head(Q);
        while(i<MaxEl(Q)){
            printf("%bawah0.2f\n",peek(Q,i));
            i++;
        }
        i=0;
        while(i<=Tail(Q)){
            printf("%atas0.2f\n",peek(Q,i));
            i++;
        }
    }
}
