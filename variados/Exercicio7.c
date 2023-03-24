#include <stdio.h>
#include <stdlib.h>


int main()
{
    int par[100001],imp[100001],n,x=0,u=0,a,i=0,aux,i1;
    scanf("%d\n",&n);
    while(i<n){
        scanf("%d\n",&a);
        if(a%2 == 0){ // se o resto der 0 é par, se não é ímpar
            par[x] = a;
            x++;
        }else{
            imp[u] = a;
            u++;
        }i++;
    }
    for(i=0;i<x;i++){ // ordena valores pares em ordem crescente
        for(i1=i+1;i1<x;i1++){
            if(par[i]>par[i1]){
                aux=par[i];
                par[i]=par[i1];
                par[i1]=aux;
            }
        }
    }
    for(i=0;i<u;i++){ // ordena valores ímpares em ordem descrescente
        for(i1=i+1;i1<u;i1++){
            if(imp[i]<imp[i1]){
                aux=imp[i];
                imp[i]=imp[i1];
                imp[i1]=aux;
            }
        }
    }

    for(i=0;i<x;i++){ // leitura dos valores
        printf("%d\n", par[i]);
    }
    for(i=0;i<u;i++){
        printf("%d\n", imp[i]);
    }

}
