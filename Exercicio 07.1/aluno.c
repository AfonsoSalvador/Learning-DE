#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char* nome;
    int matric;
};

Aluno* inicializaAluno (char* nome, int matric){
    Aluno* aluno;

    aluno=malloc(sizeof(Aluno));

    
    aluno->nome=strdup(nome);

    aluno->matric=matric;

    return aluno;
}

int recuperaMatric (Aluno* aluno){
    return aluno->matric;
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

int ehMesmaMatric(Aluno* aluno, int matric){
    if(aluno->matric==matric){
        return 1;
    }
    else return 0;
}

void imprimeAluno(Aluno* aluno){
    if(aluno==NULL){
        printf("aluno nulo\n");
        return;
    }
    printf("\tNome:%s\n\tMatricula:%d\n\n",aluno->nome,aluno->matric);
}