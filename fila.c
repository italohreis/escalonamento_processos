#include <stdio.h>
#include "fila.h"

void inicializar_fila(Fila *fila, int prioridade, int quantum) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->prioridade = prioridade;
    fila->quantum = quantum;
    fila->tamanho = 0;
}

int fila_vazia(Fila *fila) {
    return fila->inicio == NULL;
}

void inserir_fila(Fila *fila, PCB *processo) {
    if (fila_vazia(fila)) {
        fila->inicio = processo;
        fila->fim = processo;
        processo->prox = processo;
    } else {
        processo->prox = fila->inicio;
        fila->fim->prox = processo;
        fila->fim = processo;
    }

    fila->tamanho++;
}

PCB *remover_fila(Fila *fila) {
    if (fila_vazia(fila))
        return NULL;

    PCB *processo = fila->inicio;

    if (fila->inicio == fila->fim) {
        fila->inicio = NULL;
        fila->fim = NULL;
    } else {
        fila->inicio = fila->inicio->prox;
        fila->fim->prox = fila->inicio;
    }

    processo->prox = NULL;
    fila->tamanho--;

    return processo;
}

void exibir_fila(Fila *fila) {
    if (fila_vazia(fila)) {
        printf("Fila vazia\n");
        return;
    }

    PCB *atual = fila->inicio;

    printf("Fila prioridade %d: ", fila->prioridade);

    do {
        printf("P%d ", atual->pid);
        atual = atual->prox;
    } while (atual != fila->inicio);

    printf("\n");
}