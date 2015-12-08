#include "segiempat.h"
#include <stdio.h>


int main()
{
    SEGIEMPAT SG;
    float dX, dY, luas;
    int pilih;

    BacaSEGIEMPAT(&SG);
    TulisSEGIEMPAT(SG);


    do{
        scanf("%d", &pilih);
        if(pilih == 1){
            scanf("%f %f",&dX, &dY);
            TranslasiSEGIEMPAT(&SG, dX, dY);
            TulisSEGIEMPAT(SG);
        }else if(pilih == 2){
            DobelSEGIEMPAT(&SG);
            TulisSEGIEMPAT(SG);
        }else if(pilih == 3){
            MirrorSEGIEMPAT(&SG, true, false);
            TulisSEGIEMPAT(SG);
        }else if(pilih == 4){
            MirrorSEGIEMPAT(&SG, false, true);
            TulisSEGIEMPAT(SG);
        }else if(pilih > 4){
            printf("Kode operasi salah\n");
        }
    }while(pilih != 0);
    printf("Luas = %d", LuasSEGIEMPAT(SG));

    return 0;
}
