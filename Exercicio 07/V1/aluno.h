#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* inicializaAluno (char* nome, int matric);

int recuperaMatric (Aluno* aluno);

char* recuperaNome(Aluno* aluno);

void destroiAluno(Aluno* aluno);

int ehMesmoNome(Aluno* aluno, char* nome);

int ehMesmaMatric(Aluno* aluno, int matric);

void imprimeAluno(Aluno* aluno);

#endif