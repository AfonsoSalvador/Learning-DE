#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula{
    Celula* prox;
    Aluno* aluno;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Lista* inicializaLista(){
    Lista* lista;
    lista=malloc(sizeof(Lista));
    lista->prim=NULL;
    lista->ult=NULL;

    return lista;
}

void insereAluno(Aluno* aluno, Lista* lista){
    Celula* nova;
    nova=malloc(sizeof(Celula));

    nova->aluno=aluno;
    nova->prox=NULL;

    if(lista->prim==NULL){
        lista->prim=nova;
        lista->ult=nova;
    }
    else{
        lista->ult->prox=nova;
        lista->ult=nova;
    }
}

void excluiAluno(Lista* lista, char* nome){
    Celula* p;
    Celula* ant;
    
    if(lista->prim==NULL||lista->ult==NULL){
        return;
    }

    if(ehMesmoNome(recuperaNome(lista->prim->aluno),nome)){
        if(lista->prim!=lista->ult){
            ant=lista->prim;
            p=ant->prox;

            destroiAluno(ant->aluno);
            destroiCelula(ant);
            lista->prim=p;
        }
        else{
            destroiAluno(lista->prim->aluno);
            destroiCelula(lista->prim);
            lista->prim=NULL;
            lista->ult=NULL;
        }
    }
    else{

        for(ant=lista->prim,p=ant->prox;p!=NULL;ant=ant->prox,p=p->prox){
            if(ehMesmoNome(recuperaNome(p->aluno),nome)){
                destroiAluno(p->aluno);
                ant->prox=p->prox;
                destroiCelula(p);
                if(p->prox==NULL){
                    lista->ult=ant;
                }
            }
        }
        
    }
}

void destroiCelula(Celula* celula){
    free(celula);
}

void imprimeLista(Lista* lista){
    Celula* p;

    for(p=lista->prim;p!=NULL;p=p->prox){
        printf("Nome: %s\n Mat:%d\n\n",recuperaNome(p->aluno),recuperaMatric(p->aluno));
    }

}


