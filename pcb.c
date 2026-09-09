#include <stdio.h>
#include <stdlib.h>
#include "pcb.h"

PCB *criar_pcb(int pid, int prioridade, int tempo_total) {
    PCB *novo = malloc(sizeof(PCB));

    if (novo == NULL) {
        printf("Erro ao alocar memoria para o processo\n");
        exit(1);
    }

    novo->pid = pid;
    novo->prioridade = prioridade;
    novo->tempo_total = tempo_total;
    novo->tempo_restante = tempo_total;
    novo->estado = PRONTO;
    novo->prox = NULL;

    return novo;
}

void liberar_pcb(PCB *processo) {
    free(processo);
}