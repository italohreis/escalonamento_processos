#include <stdio.h>
#include "pcb.h"
#include "fila.h"
#include "escalonador.h"

int main() {
    Escalonador escalonador;
    inicializar_escalonador(&escalonador);

    PCB *p1 = criar_pcb(1, 0, 10);
    PCB *p2 = criar_pcb(2, 2, 15);
    PCB *p3 = criar_pcb(3, 1, 8);
    PCB *p4 = criar_pcb(4, 0, 6);
    PCB *p5 = criar_pcb(5, 3, 12);
    PCB *p6 = criar_pcb(6, 1, 5);

    adicionar_processo(&escalonador, p1);
    adicionar_processo(&escalonador, p2);
    adicionar_processo(&escalonador, p3);
    adicionar_processo(&escalonador, p4);
    adicionar_processo(&escalonador, p5);
    adicionar_processo(&escalonador, p6);

    exibir_escalonador(&escalonador);

    executar_escalonador(&escalonador);

    return 0;
}