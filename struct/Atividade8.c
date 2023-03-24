#include <stdlib.h>
#include <stdlib.h>

#define WHITESPACES " \t\n\r"
#define IS_WHITESPACE(x) strchr(WHITESPACES, (x))
#ifdef NDEBUG
#define debug printf
#else
#define debug(...)
#endif

typedef struct {
    char *nome;
    char *id;
    char *id_pai;
    double saldo;
} Conta;

typedef struct arvore NoArvore;
struct arvore {
    void *dados;
    NoArvore *filho, *irmao;
};

char *
str_copia(const char *str) {
    char *result = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(result, str);
    return result;
}

int
str_separa_n(char *str, char *sep, char **tokens, size_t n) {
    int i = 1;
    *tokens = str;
    for (char *cur = str; *cur && i < n; cur++) {
        if (strchr(sep, *cur)) {
            *cur = '\0';
            tokens[i++] = cur + 1;
        }
    }
    return i;
}

void str_trim(char *destino, const char *origem) {
    while (IS_WHITESPACE(*origem))
        origem++;
    char *last_valid_char = destino - 1;
    for (; *origem; origem++, destino++) {
        if (!IS_WHITESPACE(*origem))
            last_valid_char = destino;
        *destino = *origem;
    }
    *(last_valid_char + 1) = '\0';
}

Conta *
conta_nova(const char *nome, const char *id, const char *id_pai, double saldo);

Conta *
conta_le(char *buffer);

void
conta_libera(Conta *conta);

Conta *
conta_nova(const char *nome, const char *id, const char *id_pai, double saldo) {
    Conta *conta = malloc(sizeof(Conta));
    conta->nome = str_copia(nome);
    conta->id = str_copia(id);
    conta->id_pai = str_copia(id_pai);
    conta->saldo = saldo;
    return conta;
}

Conta *
conta_le(char *buffer) {
    char *partes[4];
    str_trim(buffer, buffer);
    str_separa_n(buffer, ";", partes, 4);
    return conta_nova(partes[0], partes[1], partes[2], strtod(partes[3], NULL));
}

void
conta_libera(Conta *conta) {
    free(conta->nome);
    free(conta->id);
    free(conta->id_pai);
    free(conta);
}

NoArvore *
carrega_contas(Conta *entrada) {
    char x[256];
    NoArvore *raiz = NULL;
    while (fgets(x, 255, entrada)) {
        Conta *conta = conta_le(x);
        debug("%s %s %s %.2lf\n", conta->nome, conta->id, conta->id_pai, conta->saldo);
    }
    return raiz;
}

