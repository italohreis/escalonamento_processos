#ifndef ESCALONADOR_H
#define ESCALONADOR_H

#include "fila.h"

#define NUM_FILAS 4

typedef struct {
    Fila filas[NUM_FILAS];
    int tempo_atual;
} Escalonador;

void inicializar_escalonador(Escalonador *escalonador);
void adicionar_processo(Escalonador *escalonador, PCB *processo);
void exibir_escalonador(Escalonador *escalonador);
void executar_escalonador(Escalonador *escalonador);

#endif