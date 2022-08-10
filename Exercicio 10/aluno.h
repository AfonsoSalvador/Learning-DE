#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* inicializaAluno (char* nome, int matric, float cr);

int recuperaMatric (Aluno* aluno);

char* recuperaNome(Aluno* aluno);

float recuperaCr (Aluno* aluno);

void destroiAluno(Aluno* aluno);

int ehMesmoNome(Aluno* aluno, char* nome);

int ehMesmaMatric(void* aluno, void* matric);

#endif