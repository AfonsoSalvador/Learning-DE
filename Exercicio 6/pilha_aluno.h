#ifndef PILHAALUNO_H
#define PILHAALUNO_H
#include "aluno.h"

typedef struct pilhaAluno PilhaAluno;

PilhaAluno* InicializaPilhaA(int max);

void FPVaziaPilhaA (PilhaAluno *PilhaAluno);

int EhVaziaPilhaA (PilhaAluno* PilhaAluno);

int PushPilhaA (Aluno* aluno,PilhaAluno* PilhaAluno );

Aluno* PopPilhaA (PilhaAluno* PilhaAluno);

int TamanhoPilhaA (PilhaAluno* PilhaAluno);

void DestroiPilhaA (PilhaAluno* PilhaAluno);

void ImprimePilhaA (PilhaAluno* pilhaAluno, char* nome);

void ViraPilha (PilhaAluno* p1, PilhaAluno* p2);

#endif