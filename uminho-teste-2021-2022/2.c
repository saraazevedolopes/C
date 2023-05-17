#include <stdlib.h>
#include <stdio.h>

typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

LInt removeMaiores(LInt l, int x) {
    // Verificar se a lista está vazia
    if (l == NULL)
        return NULL;

    // Verificar se o primeiro elemento é maior que x
    while (l != NULL && l->valor > x) {
        LInt temp = l;
        l = l->prox;
        free(temp);
    }

    // Percorrer a lista e remover os elementos maiores que x
    LInt curr = l;
    while (curr != NULL && curr->prox != NULL) {
        if (curr->prox->valor > x) {
            LInt temp = curr->prox;
            curr->prox = temp->prox;
            free(temp);
        } else {
            curr = curr->prox;
        }
    }

    return l;
}


void imprimirLista(LInt l) {
    printf("Lista: ");
    while (l != NULL) {
        printf("%d ", l->valor);
        l = l->prox;
    }
    printf("\n");
}

int main() {
    // Criar a lista inicial
    LInt l = malloc(sizeof(struct LInt_nodo));
    l->valor = 2;
    l->prox = malloc(sizeof(struct LInt_nodo));
    l->prox->valor = 4;
    l->prox->prox = malloc(sizeof(struct LInt_nodo));
    l->prox->prox->valor = 6;
    l->prox->prox->prox = malloc(sizeof(struct LInt_nodo));
    l->prox->prox->prox->valor = 8;
    l->prox->prox->prox->prox = NULL;

    // Imprimir lista inicial
    printf("Lista inicial:\n");
    imprimirLista(l);

    // Remover elementos maiores que 5
    int x = 5;
    l = removeMaiores(l, x);

    // Imprimir lista resultante
    printf("\nLista resultante após remover elementos maiores que %d:\n", x);
    imprimirLista(l);

    // Liberar memória
    while (l != NULL) {
        LInt temp = l;
        l = l->prox;
        free(temp);
    }

    return 0;
}


