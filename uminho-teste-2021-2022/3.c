#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo *esq, *dir;
} *ABin;

LInt caminho(ABin a, int x) {
    if (a == NULL) // Verifica se a árvore é nula 
        return NULL;

    if (a->valor == x) { // Verifica se o valor atual é igual a x
        LInt novo = malloc(sizeof(struct LInt_nodo));
        novo->valor = x;
        novo->prox = NULL;
        return novo;
    }

    LInt resultado;
    if (a->valor > x)
        resultado = caminho(a->esq, x); // Chamada recursiva para a subárvore esquerda
    elsea->valor > x
        resultado = caminho(a->dir, x); // Caso em que (a->valor < x)

    if (resultado == NULL) // Caso não encontre caminho para o x
        return NULL;

    LInt novo = malloc(sizeof(struct LInt_nodo));
    novo->valor = a->valor;
    novo->prox = resultado; // Em busca de mais valores para a lista
    return novo;
}

void imprimirLista(LInt lista) {
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

// Função auxiliar para criar um novo nó de árvore binária
ABin novoNo(int valor) {
    ABin novo = malloc(sizeof(struct ABin_nodo));
    novo->valor = valor;
    novo->esq = novo->dir = NULL;
    return novo;
}

int main() {
    // Construção de uma árvore de exemplo
    ABin raiz = novoNo(5);
    raiz->esq = novoNo(3);
    raiz->dir = novoNo(7);
    raiz->esq->esq = novoNo(2);
    raiz->esq->dir = novoNo(4);
    raiz->dir->esq = novoNo(6);
    raiz->dir->dir = novoNo(8);

    int valorProcurado = 8;
    printf("Caminho até %d: ", valorProcurado);
    LInt resultado = caminho(raiz, valorProcurado);
    imprimirLista(resultado);

    return 0;
}
