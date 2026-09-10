#include <stdio.h>
#include "escalonador.h"

void inicializar_escalonador(Escalonador *escalonador) {
    inicializar_fila(&escalonador->filas[0], 0, 2);
    inicializar_fila(&escalonador->filas[1], 1, 4);
    inicializar_fila(&escalonador->filas[2], 2, 6);
    inicializar_fila(&escalonador->filas[3], 3, 8);
}

void adicionar_processo(Escalonador *escalonador, PCB *processo) {
    if (processo->prioridade < 0 || processo->prioridade >= NUM_FILAS) {
        printf("Prioridade invalida para o processo P%d\n", processo->pid);
        return;
    }

    inserir_fila(&escalonador->filas[processo->prioridade], processo);
}

void exibir_escalonador(Escalonador *escalonador) {
    printf("\nFilas do Escalonador:\n");

    for (int i = 0; i < NUM_FILAS; i++)
        exibir_fila(&escalonador->filas[i]);

    printf("\n");
}