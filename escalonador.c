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

static void executar_processo(PCB *processo, int quantum) {
    processo->estado = EXECUTANDO;

    int tempo_execucao;

    if (processo->tempo_restante < quantum) {
        tempo_execucao = processo->tempo_restante;
    } else {
        tempo_execucao = quantum; 
    }

    printf("Executando P%d | prioridade: %d | quantum: %d | restante: %d",
           processo->pid, processo->prioridade, quantum, processo->tempo_restante);

    processo->tempo_restante -= tempo_execucao;

    printf(" -> %d\n", processo->tempo_restante);

    if (processo->tempo_restante == 0) {
        processo->estado = FINALIZADO;
    }
    else {
        processo->estado = PRONTO;
    }
}

void executar_escalonador(Escalonador *escalonador) {
    printf("\n--- INICIO DO ESCALONAMENTO ---\n\n");

    while (!escalonador_vazio(escalonador)) {
        Fila *fila = buscar_fila_maior_prioridade(escalonador);

        PCB *processo = remover_fila(fila);

        executar_processo(processo, fila->quantum);

        if (processo->estado == FINALIZADO) {
            printf("P%d finalizado.\n\n", processo->pid);
            liberar_pcb(processo);
        } else {
            inserir_fila(fila, processo);
        }
    }

    printf("--- TODOS OS PROCESSOS FORAM FINALIZADOS ---\n");
}