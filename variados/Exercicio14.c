#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,i;
    float s,m,somaTotal,media,M[12][12];
    float soma1,soma2,soma3,soma4,soma5,u;
    char O;
    scanf("%s",&O);
    for(x=0;x<12;x++){ // preenche a matriz toda
        for(i=0;i<12;i++){
            scanf("%f",&M[x][i]);
        }
    }
    if(O == 's'){ // soma os elementos da matriz
        u=M[0][1];
        for(i=2;i<11;i++){
            soma1=u+M[0][i];
            u=soma1;
        }
        u=M[1][2];
        for(i=3;i<10;i++){
            soma2=u+M[1][i];
            u=soma2;
        }
        u=M[2][3];
        for(i=4;i<9;i++){
            soma3=u+M[2][i];
            u=soma3;
        }
        u=M[3][4];
        for(i=5;i<8;i++){
            soma4=u+M[3][i];
            u=soma4;
        }
        u=M[4][5];
        for(i=6;i<7;i++){
            soma5=u+M[4][i];
            u=soma5;
        }
        somaTotal=soma1+soma2+soma3+soma4+soma5;
        printf("%.1f",somaTotal);
    }
    if(O == 'm'){ // soma os elementos da matriz, depois tira a média
        u=M[0][1];
        for(i=2;i<11;i++){
            soma1=u+M[0][i];
            u=soma1;
        }
        u=M[1][2];
        for(i=3;i<10;i++){
            soma2=u+M[1][i];
            u=soma2;
        }
        u=M[2][3];
        for(i=4;i<9;i++){
            soma3=u+M[2][i];
            u=soma3;
        }
        u=M[3][4];
        for(i=5;i<8;i++){
            soma4=u+M[3][i];
            u=soma4;
        }
        u=M[4][5];
        for(i=6;i<7;i++){
            soma5=u+M[4][i];
            u=soma5;
        }
        somaTotal=soma1+soma2+soma3+soma4+soma5;
        media = somaTotal/30;
        printf("%.1f",media);
    }
    return 0;
}
