# Escalonamento de Processos por Filas de Prioridade

Implementação em C de um escalonador baseado em filas de prioridades e Round Robin

## Funcionamento

- Possui 4 filas com prioridades de `0` a `3`.
- Cada fila utiliza uma lista circular de PCBs.
- Os quantum são estáticos
- A fila de menor número de prioridade é executada primeiro. (Quanto menor, maior prioridade)
- Ao terminar o quantum, o processo volta ao fim da sua fila se ainda possuir tempo de execução.
- O programa exibe as filas, cada execução e o tempo total de CPU.

## Estrutura

- `pcb.c` e `pcb.h`: criação, estados e liberação dos PCBs.
- `fila.c` e `fila.h`: implementação das filas circulares.
- `escalonador.c` e `escalonador.h`: gerenciamento e execução do escalonador.
- `main.c`: criação dos processos e execução da simulação.

## Compilação e execução

```bash
gcc main.c pcb.c fila.c escalonador.c -o escalonador
./escalonador
```
