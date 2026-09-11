#include <stdio.h>
#include "escalonador.h"

void inicializar_escalonador(Escalonador *escalonador) {
    inicializar_fila(&escalonador->filas[0], 0, 2);
    inicializar_fila(&escalonador->filas[1], 1, 4);
    inicializar_fila(&escalonador->filas[2], 2, 6);
    inicializar_fila(&escalonador->filas[3], 3, 8);

    escalonador->tempo_atual = 0;
}

void adicionar_processo(Escalonador *escalonador, PCB *processo) {
    if (processo->prioridade < 0 || processo->prioridade >= NUM_FILAS) {
        printf("Prioridade invalida para o processo P%d\n", processo->pid);
        return;
    }

    inserir_fila(&escalonador->filas[processo->prioridade], processo);
}

void exibir_escalonador(Escalonador *escalonador) {
    printf("\nFILAS DO ESCALONADOR\n\n");

    for (int i = 0; i < NUM_FILAS; i++)
        exibir_fila(&escalonador->filas[i]);

    printf("\n");
}

static int escalonador_vazio(Escalonador *escalonador) {
    for (int i = 0; i < NUM_FILAS; i++) {
        if (!fila_vazia(&escalonador->filas[i]))
            return 0;
    }

    return 1;
}

static Fila *buscar_fila_maior_prioridade(Escalonador *escalonador) {
    for (int i = 0; i < NUM_FILAS; i++) {
        if (!fila_vazia(&escalonador->filas[i])) {
            return &escalonador->filas[i];
        }
    }

    return NULL;
}

static int executar_processo(PCB *processo, int quantum) {
    processo->estado = EXECUTANDO;

    int tempo_execucao;

    if (processo->tempo_restante < quantum) {
        tempo_execucao = processo->tempo_restante;
    } else {
        tempo_execucao = quantum;
    }

    processo->tempo_restante -= tempo_execucao;

    if (processo->tempo_restante == 0) {
        processo->estado = FINALIZADO;
    } else {
        processo->estado = PRONTO;
    }

    return tempo_execucao;
}

void executar_escalonador(Escalonador *escalonador) {
    printf("\nINICIO DO ESCALONAMENTO\n\n");

    while (!escalonador_vazio(escalonador)) {
        Fila *fila = buscar_fila_maior_prioridade(escalonador);
        PCB *processo = remover_fila(fila);

        int inicio = escalonador->tempo_atual;
        int tempo_execucao = executar_processo(processo, fila->quantum);

        escalonador->tempo_atual += tempo_execucao;

        printf("[T=%d -> T=%d] P%d | prioridade: %d | executou: %d | restante: %d\n",
               inicio, escalonador->tempo_atual, processo->pid,
               processo->prioridade, tempo_execucao, processo->tempo_restante);

        if (processo->estado == FINALIZADO) {
            printf("P%d finalizado no tempo %d.\n\n", processo->pid, escalonador->tempo_atual);
            liberar_pcb(processo);
        } else {
            inserir_fila(fila, processo);
        }

        // exibir_escalonador(escalonador);
    }

    printf("\nTODOS OS PROCESSOS FORAM FINALIZADOS\n");
    printf("Tempo total de CPU: %d\n", escalonador->tempo_atual);
}