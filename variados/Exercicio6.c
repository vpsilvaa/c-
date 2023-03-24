#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sub(char s[],char s1[],int a); // assinatura da função

int main()
{
    char str[51],str1[51];
    int a,b;
    while(gets(str) && gets(str1)){ // loop infinito
        a = strlen(str);
        b = strlen(str1);
        if(a >= b){
            sub(str,str1,a); //chama função passando parâmetros
        }else {
            sub(str1,str,b); //chama função passando parâmetros
        }
    }
}

void sub(char s[],char s1[],int a){
    int i,j,big = 0,c,b,m,n;
    b = strlen(s1);
    for(j=0;j<b;j++){
        for(i=0;i<a;i++){
            c=0;
            for(m=i,n=j;s1[n]==s[m];m++,n++){
                if(n==b || m==a){
                    break;
                }else{
                c++;
                }
            }
            if(c>big){
                big=c;
            }
        }
    }
    printf("%d\n",big);
}

