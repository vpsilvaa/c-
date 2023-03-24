#include <stdlib.h>
#include <assert.h>

typedef struct ab_no NoArvBin;
struct ab_no {
    int chave;
    NoArvBin *esq, *dir;
};

NoArvBin *
ab_no_novo(int chave) {
    NoArvBin *no = malloc(sizeof(NoArvBin));
    no->chave = chave;
    no->esq = no->dir = NULL;
    return no;
}

NoArvBin *
ab_no_encontra(NoArvBin *raiz, int chave) {
    if (raiz == NULL)
        return NULL;
    if (raiz->chave == chave)
        return raiz;
    NoArvBin *esq = ab_no_encontra(raiz->esq, chave);
    if (esq != NULL)
        return esq;
    return ab_no_encontra(raiz->dir, chave);
}

void
preordem(NoArvBin *raiz){
    if(raiz != NULL){
        printf("%i",raiz->chave);
        if(raiz->esq != NULL){
            printf("(");
            preordem(raiz->esq);
        }
        if(raiz->dir != NULL){
            printf("(");
            preordem(raiz->dir);
        }
        if(raiz->dir == NULL || raiz->esq == NULL){
            printf(")");
        }
        if(raiz->dir){
            printf(")");
        }
    }
}

int
main(void) {
    printf("(");
    NoArvBin *raiz = ab_no_novo(1);
    ab_no_encontra(raiz, 1)->esq = ab_no_novo(2);
    ab_no_encontra(raiz, 1)->dir = ab_no_novo(3);
    ab_no_encontra(raiz, 2)->esq = ab_no_novo(4);
    ab_no_encontra(raiz, 2)->dir = ab_no_novo(5);
    ab_no_encontra(raiz, 3)->dir = ab_no_novo(6);
    ab_no_encontra(raiz, 5)->esq = ab_no_novo(7);
    ab_no_encontra(raiz, 5)->dir = ab_no_novo(8);
    ab_no_encontra(raiz, 6)->esq = ab_no_novo(9);
    preordem(raiz);
}
