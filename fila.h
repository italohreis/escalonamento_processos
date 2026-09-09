#ifndef FILA_H
#define FILA_H
#include "pcb.h"

typedef struct Fila {
    PCB *inicio;
    PCB *fim;
    int prioridade;
    int quantum;
    int tamanho;
} Fila;

void inicializar_fila(Fila *fila, int prioridade, int quantum);
int fila_vazia(Fila *fila);
void inserir_fila(Fila *fila, PCB *processo);
PCB *remover_fila(Fila *fila);
void exibir_fila(Fila *fila);

#endif