#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int avalia(const char *expr);

typedef struct pilha Pilha;
typedef struct pilha_no PilhaNo;
struct pilha_no {
    int item;
    PilhaNo *prox;
};

PilhaNo *
pilha_no_novo(int item, PilhaNo *prox) {
    PilhaNo *no = malloc(sizeof(PilhaNo));
    no->item = item;
    no->prox = prox;
    return no;
}

struct pilha {
    PilhaNo *topo;
};

Pilha *
pilha_nova(void) {
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void
pilha_empilha(Pilha *pilha, int item) {
    pilha->topo = pilha_no_novo(item, pilha->topo);
}

int
pilha_topo(Pilha *pilha) {
    assert(pilha->topo != NULL);
    return pilha->topo->item;
}

int
pilha_desempilha(Pilha *pilha) {
    assert(pilha->topo != NULL);
    PilhaNo *temp = pilha->topo;
    pilha->topo = temp->prox;
    int item = temp->item;
    free(temp);
    return item;
}

bool
pilha_esta_vazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

void
pilha_libera(Pilha *pilha) {
    while (!pilha_esta_vazia(pilha)){
        pilha_desempilha(pilha);
    }
    free(pilha);
}

int
avalia(const char *expr){
    int aux1, int aux2, int res;
    Pilha *pilha = pilha_nova();
    while(expr != NULL){
        if(expr != '+' && expr != '*' && expr != '/' && expr != '-'){
            pilha_empilha(pilha, expr);
        }
        else if(expr == '+'){
            aux1 = pilha_desempilha(pilha);
            aux2 = pilha_desempilha(pilha);
            res = aux2 + aux1;
            pilha_empilha(pilha,res);
        }
        else if(expr == '-'){
            aux1 = pilha_desempilha(pilha);
            aux2 = pilha_desempilha(pilha);
            res = aux2 - aux1;
            pilha_empilha(pilha,res);
        }
        else if(expr == '*'){
            aux1 = pilha_desempilha(pilha);
            aux2 = pilha_desempilha(pilha);
            res = aux2 * aux1;
            pilha_empilha(pilha,res);
        }
        else if(expr == '/'){
            aux1 = pilha_desempilha(pilha);
            aux2 = pilha_desempilha(pilha);
            res = aux2 / aux1;
            pilha_empilha(pilha,res);
        }
    }
}
