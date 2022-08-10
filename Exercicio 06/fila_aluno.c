#include "fila_aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filaAluno{
    PilhaAluno* p1;
    PilhaAluno* p2;

    int max;
};

FilaAluno* inicializaFilaAluno (int max){
    FilaAluno* fila;
    fila= malloc(sizeof(FilaAluno));
    fila->p1=InicializaPilhaA(max);
    fila->p2=InicializaPilhaA(max);
    fila->max=max;
}

void entraNaFila (Aluno* aluno, FilaAluno* fila){
    int result;

    ViraPilha(fila->p1,fila->p2);
    result=PushPilhaA(aluno,fila->p2);
    ViraPilha(fila->p2,fila->p1);
}

Aluno* saiDaFila (FilaAluno* fila){
    Aluno* aluno;
    aluno=PopPilhaA(fila->p1);
    return aluno;
}

void destroiFila (FilaAluno* fila){
    DestroiPilhaA(fila->p1);
    DestroiPilhaA(fila->p2);
    free(fila);
}

void imprimeFila (FilaAluno* fila){
    
    ImprimePilhaA(fila->p1,"FILA");
}