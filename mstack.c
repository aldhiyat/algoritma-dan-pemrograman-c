#include <stdio.h>
#include "stack.h"
#define Max 20

int main()
{
    Stack S;
    int N,i,j;
    long simpan1,simpan2,hasil;
    char operasi[Max];
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s",operasi);
        CreateEmpty(&S,Max);
        for(j=0;operasi[j]!='\0';j++){
            if (operasi[j]=='-' || operasi[j]=='+' || operasi[j]=='*' || operasi[j]=='%' || operasi[j]=='/'){
                    if (operasi[j]=='-'){
                    Pop(&S,&simpan2);
                    Pop(&S,&simpan1);
                    hasil = simpan1 - simpan2;
                    Push(&S,hasil);
                }
                else if (operasi[j]=='+'){
                    Pop(&S,&simpan2);
                    Pop(&S,&simpan1);
                    hasil = simpan1 + simpan2;
                    Push(&S,hasil);
                }
                else if (operasi[j]=='*'){
                    Pop(&S,&simpan2);
                    Pop(&S,&simpan1);
                    hasil = simpan1 * simpan2;
                    Push(&S,hasil);

                }
                else if (operasi[j]=='%'){
                    Pop(&S,&simpan2);
                    Pop(&S,&simpan1);
                    hasil = simpan1 % simpan2;
                    Push(&S,hasil);
                }
                else if (operasi[j]=='/'){
                    Pop(&S,&simpan2);
                    Pop(&S,&simpan1);
                    hasil = simpan1 / simpan2;
                    Push(&S,hasil);
                }
            }
            else{
               Push(&S,operasi[j]-48);
            }
        }
        printf("%d\n",InfoTop(S));
    }
    return 0;
}
