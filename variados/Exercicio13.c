#include <stdio.h>
#include <stdlib.h>

int main()
{
    int L,x,i;
    float s,m,soma,media,M[12][12],u;
    char T;
    scanf("%d",&L);
    scanf("%s",&T);
    for(x=0;x<12;x++){ // preenche a matriz toda
        for(i=0;i<12;i++){
            scanf("%f",&M[x][i]);
        }
    }
    u=M[L][0];
    if(T == 's'){ // soma os elementos da matriz
        for(i=1;i<12;i++){
            soma=u+M[L][i];
            u=soma;
        }
        printf("%.1f",soma);
    }
    if(T == 'm'){ // media dos elementos da matriz
        for(i=1;i<12;i++){
            soma=u+M[L][i];
            u=soma;
        }
        media = soma/12;
        printf("%.1f",media);
    }
    return 0;
}
