#include"queue.h"

float AvgElmt (Queue Q)
{
    int i;
    float total=0;
    if(!IsEmpty(Q))
    {
        if(Tail(Q)>Head(Q))
        {
            for(i=Head(Q);i<=Tail(Q);i++)
            {
                total=total+(Q).T[i];
            }
        }
        else if(Tail(Q)<Head(Q))
        {
            for(i=Head(Q);i<MaxEl(Q);i++)
            {
                total=total+(Q).T[i];
            }
            for(i=0;i<=Tail(Q);i++)
            {
                total=total+(Q).T[i];
            }
        }
        else if(Tail(Q)==Head(Q))
        {
            total=(Q).T[Head(Q)];
        }
        return (total/NBElmt(Q));
    }
}
int main()
{
    Queue Q;
    int panjang_que, kode_operasi;
    float p_waktu,X;
    scanf("%d",&panjang_que);
    CreateEmpty(&Q,panjang_que);
    do{
        scanf("%d",&kode_operasi);
        if(kode_operasi!=0){
            if(kode_operasi==1){
                scanf("%f",&p_waktu);
                if(!IsFull(Q)){
                    Add(&Q,p_waktu);
                }
            }
            else if(kode_operasi==2){
                if(!IsEmpty(Q)){
                    Del(&Q,&X);
                }
            }
        }
    }while(kode_operasi!=0);
    printf("%d\n",NBElmt(Q));
    if(IsEmpty(Q)){
        printf("Tidak bisa dihitung\n");
    }
    else{
        printf("%0.2f\n",AvgElmt(Q));
    }
        return 0;
}
