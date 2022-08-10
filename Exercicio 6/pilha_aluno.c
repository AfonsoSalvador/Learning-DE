#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha_aluno.h"


struct pilhaAluno{
    int max;
    int top;
    Aluno** alunos;
};

PilhaAluno* InicializaPilhaA(int max){
    PilhaAluno* pilhaAluno;
    pilhaAluno= malloc(sizeof(PilhaAluno));

    pilhaAluno->alunos=malloc(sizeof(Aluno*)*max);

    pilhaAluno->max=max;

    pilhaAluno->top=0;

    return pilhaAluno;
}

void FPVaziaPilhaA (PilhaAluno *pilhaAluno){
    Aluno* p;
    int tam;
    
    if(pilhaAluno->top==NULL|| pilhaAluno->top==0){
        return;
    }

    for(;TamanhoPilha(pilhaAluno)!=0;){
        p=PopPilha(pilhaAluno);
        DestroiItem(p);
    }

    return;

}

int EhVaziaPilhaA (PilhaAluno* pilhaAluno){
    if(TamanhoPilha(pilhaAluno)==0){
        return 1;
    }
    else return 0;
}

int PushPilhaA (Aluno* item,PilhaAluno* pilhaAluno ){
    if(!pilhaAluno || pilhaAluno->top==pilhaAluno->max){
        printf("ERRO: PILHA JA ESTA CHEIA");
        return 0;
    }

    if(!pilhaAluno->top){
        pilhaAluno->top=0;
    }

    pilhaAluno->alunos[pilhaAluno->top]=item;
    pilhaAluno->top++;

    return 1;
}

Aluno* PopPilhaA (PilhaAluno* pilhaAluno){
    Aluno* item;

    if(!pilhaAluno || pilhaAluno->top==0 || !pilhaAluno->top || !pilhaAluno->top==0){
        printf("ERRO: PILHA ESTA VAZIA");
        return;
    }

    item=pilhaAluno->alunos[pilhaAluno->top-1];
    pilhaAluno->alunos[pilhaAluno->top-1]=NULL;
    pilhaAluno->top--;

    return item;
}

int TamanhoPilhaA (PilhaAluno* pilhaAluno){
    if(!pilhaAluno->top||pilhaAluno->top==0){
        return 0;
    }
    else return pilhaAluno->top-1;
}

void ImprimePilhaA (PilhaAluno* pilhaAluno, char* nome){
    Aluno* p;
    int aux=0;
    
    if(!pilhaAluno->top||pilhaAluno->top==0){
        printf("----------%s VAZIA----------\n",nome);
        return;
    }

    prinft("----------------- INICIO DA %s -----------------\n",nome);
    for(p=pilhaAluno->alunos[aux];  aux<pilhaAluno->top  ;aux++,p=pilhaAluno->alunos[aux]){
        printf("\n\n");
        ImprimeItem(p);
        printf("\n\n");
    }
    prinft("------------------ FIM DA %s -------------------\n",nome);


}

void DestroiPilha (PilhaAluno* pilhaAluno){
    FPVaziaPilha(pilhaAluno);
    free(pilhaAluno->alunos);
    free(pilhaAluno);
}

void ViraPilha (PilhaAluno* p1, PilhaAluno* p2){
    Aluno* p;
    Aluno* trans;
    int aux; int result;

    result=FPVaziaPilha(p2);
    for(p=p1->alunos[aux] ;  aux<p1->top ;aux++ ,p=p1->alunos[aux]){
        trans=PopPilhaA(p1);
        result= PushPilhaA(trans,p2);
    }

}
