#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula{
    Celula* prox;
    Aluno* aluno;
    Celula* ant;
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
    nova->ant=NULL;
    

    if(lista->prim==NULL){
        lista->prim=nova;
        lista->ult=nova;
    }
    else{
        nova->ant=lista->ult;
        lista->ult->prox=nova;
        lista->ult=nova;
        
    }
}

void excluiAluno(Lista* lista, char* nome){
    Celula* p;
    int nremov=1;
    
    if(lista->prim==NULL&&lista->ult==NULL){
        printf("\nLISTA VAZIA\n");
        return;
    }

    if(ehMesmoNome(lista->prim->aluno,nome)){
        nremov=0;
        //caso seja o primeiro de uma lista com mais de uma célula
        if(lista->prim!=lista->ult){
            p=lista->prim;
            p->prox->ant=p->ant;
            lista->prim=p->prox;
            destroiAluno(p->aluno);
            destroiCelula(p);
        }
        //caso seja o unico da lista
        else{
            destroiAluno(lista->prim->aluno);
            destroiCelula(lista->prim);
            lista->prim=NULL;
            lista->ult=NULL;
        }
    }
    else{

        for(p=lista->prim;p!=NULL;p=p->prox){
            //caso seja no meio
            if(ehMesmoNome(p->aluno,nome)){
                
                nremov=0;
                destroiAluno(p->aluno);
                p->ant->prox=p->prox;
                //caso nao seja o ultimo
                if(p->prox!=NULL){
                    p->prox->ant=p->ant;
                }
                destroiCelula(p);

                break;
            }
        } 
        
    }
    if(nremov){
        printf("\nALUNO NAO ENCONTRADO\n");
    }
    else{
        printf("\nALUNO %s REMOVIDO\n",nome);
    }
}

void destroiCelula(Celula* celula){
    free(celula);
}

void destroiLista(Lista* lista){
    Celula* p;
    //caso esteja vazia
    if((lista->prim==NULL)&&(lista->ult==NULL)){
        free(lista);
        return;
    }
    //caso possua apenas uma celula
    if(lista->prim==lista->ult){
        p=lista->prim;
        destroiAluno(p->aluno);
        destroiCelula(p);
        free(lista);
        return;
    }
    //duas ou mais celulas
    for(p=lista->prim;p!=NULL;p=p->prox){
        destroiAluno(p->aluno);
        if(p!=lista->prim){
            destroiCelula(p->ant);
        }
        if(p->prox==NULL){
            destroiCelula(p);
            break;
        }
    }
    free(lista);
}

void imprimeLista(Lista* lista, int orient){
    Celula* p;


    if(orient==1){
        printf("----------------------IMPRIMINDO LISTA----------------------\n\n");
        for(p=lista->prim;p!=NULL;p=p->prox){
            printf("Nome: %s\n Mat:%d\n\n",recuperaNome(p->aluno),recuperaMatric(p->aluno));
        }
        printf("------------------------FIM DA LISTA------------------------\n\n");
    }
    else if(orient==2){
        printf("-----------------IMPRIMINDO LISTA INVERTIDA-----------------\n\n");
        for(p=lista->ult;p!=NULL;p=p->ant){
            printf("Nome: %s\n Mat:%d\n\n",recuperaNome(p->aluno),recuperaMatric(p->aluno));
        }
        printf("------------------------FIM DA LISTA------------------------\n\n");
    }

}


