#ifndef PCB_H
#define PCB_H

typedef struct PCB {
    int pid;
    int prioridade;
    int tempo_total;
    int tempo_restante;
    EstadoProcesso estado;
    struct PCB *prox;
} PCB;

typedef enum {
    PRONTO,
    EXECUTANDO,
    FINALIZADO
} EstadoProcesso;

PCB *criar_pcb(int pid, int prioridade, int tempo_total);
void liberar_pcb(PCB *pcb);

#endif