#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaRec.h"

typedef struct celula Celula;

struct lista{
    Celula* prim;
    Celula* ult;
};

struct celula{
    Aluno* aluno;
    Celula* prox;
};

Lista* inicLista(){
    Lista* lista;
    lista=malloc(sizeof(Lista));
    lista->prim=NULL;
    lista->ult=NULL;
    return lista;
}

void insereAlunoLista(Lista* lista, Aluno* aluno){
    if(lista==NULL){
        printf("LISTA NAO INICIALIZADA\n");
    }
    Celula* novac= malloc(sizeof(Celula));
    novac->aluno=aluno;
    novac->prox=NULL;
    
    //CASO PRIMEIRO DA LISTA
    if(lista->prim==NULL){
        lista->prim=novac;
        lista->ult=novac;

    }else{
    //OUTROS CASOS
    lista->ult->prox=novac;
    lista->ult=novac;
    }

    return;
}

static Celula* retiraAlunoCelula(Celula* c, char* nome, Lista* l){
    if(c==NULL){
        return c;
    }
    if(ehMesmoNome(c->aluno,nome)){
        Celula* prox = c->prox;
        destroiAluno(c->aluno);
        free(c);
        return prox;
    }
    c->prox=retiraAlunoCelula(c->prox,nome,l);
    if(c->prox==NULL){
        l->ult=c;
    }
    return c;

}

void retiraAlunoLista(Lista* lista, char* nome){
    if(lista==NULL||lista->prim==NULL){
        printf("LISTA VAZIA!\n");
        return;
    }

    Celula* c;

    c=retiraAlunoCelula(lista->prim,nome, lista);
    if(c!=lista->prim){
        lista->prim=c;
    }

    return;
}

static void ImprimeCelula(Celula* c){
    if(c==NULL){
        return;
    }
    imprimeAluno(c->aluno);
    ImprimeCelula(c->prox);
    
}

void imprimeLista(Lista* lista){
    if(lista==NULL||lista->prim==NULL){
        printf("LISTA VAZIA!\n");
        return;
    }
    printf("------------LISTA DE ALUNOS------------\n\n");
    Celula* c=lista->prim;

    ImprimeCelula(c);

    printf("\n\n------------FIM DA LISTA------------\n");


    return;
}

static void destroiCelula(Celula* c){
    //CASO SEJA O ULTIMO
    if(c->prox==NULL){
        destroiAluno(c->aluno);
        free(c);
        return;
    }
    //AINDA NAO
    Celula* proximo=c->prox;
    destroiAluno(c->aluno);
    free(c);
    destroiCelula(proximo);
    return;
}

void destroiLista(Lista* lista){
    if(lista==NULL||lista->prim==NULL){
        free(lista);
        return;
    }

    destroiCelula(lista->prim);
    free(lista);
    return;
}