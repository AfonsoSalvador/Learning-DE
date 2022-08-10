#ifndef FILAALUNO_H
#define FILAALUNO_H
#include "pilha_aluno.h"

typedef struct filaAluno FilaAluno;

FilaAluno* inicializaFilaAluno (int max);

void entraNaFila (Aluno* aluno, FilaAluno* fila);

Aluno* saiDaFila (FilaAluno* fila);

void destroiFila (FilaAluno* fila);

void imprimeFila (FilaAluno* fila);



#endif