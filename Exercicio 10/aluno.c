#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char* nome;
    int matric;
    float CR;
};

Aluno* inicializaAluno (char* nome, int matric, float cr){
    Aluno* aluno;

    aluno=malloc(sizeof(Aluno));

    
    aluno->nome=strdup(nome);

    aluno->matric=matric;

    aluno->CR=cr;

    return aluno;
}

int recuperaMatric (Aluno* aluno){
    return aluno->matric;
}

float recuperaCr (Aluno* aluno){
    return aluno->CR;
}

char* recuperaNome(Aluno* aluno){
    return aluno->nome;
}

void destroiAluno(Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}

int ehMesmoNome(Aluno* aluno, char* nome){
    int result;
    result=strcmp(nome,aluno->nome);
    if(result==0){
        return 1;
    }
    else return 0;
}

int ehMesmaMatric(void* aluno, void* matric){
    Aluno* alunoc = (Aluno*)aluno;
    int* matricc = (int*) matric;
    int matricula = *matricc;
    if(alunoc->matric==matricula){ 
        return 1;
    }
    else return 0;
}
