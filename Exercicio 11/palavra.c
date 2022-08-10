#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"palavra.h"

struct palavra{
    char* elem;
    Palavra* prox;
    int freq;
};

Palavra* inicPalavra (char* pal){
    Palavra* novap;
    novap=malloc(sizeof(Palavra));
    novap->elem=strdup(pal);
    novap->freq=0;
    novap->prox=NULL;
    return novap;
}

char* getPalavra(Palavra* p){
    return p->elem;
}

void setOcorrencias(Palavra* p){
    p->freq++;
    return;
}

int getOcorrencias(Palavra* p){
    return p->freq;
}

Palavra* buscaPalavra(Palavra* p, char* pal){
    Palavra* aux;
    for(aux=p; aux!=NULL; aux=aux->prox){
        if(!strcmp(pal, aux->elem)){
            return aux;
        }
    }
}

Palavra* inserePalavraLista(Palavra* lista, Palavra* p){
    p->prox=lista;
    return p;
}

int contaPalavrasLista(Palavra* p){
    Palavra* pal;
    int i=0;
    for(pal=p;pal!=NULL;pal=pal->prox){
        i++;
    }
    return i;
}

void imprimeLista(Palavra* p){
    Palavra* aux;

    for(aux = p; aux!=NULL;aux=aux->prox){
        printf("String: %s - Ocorrencia: %d \n",aux->elem,aux->freq);
    }
}

void liberaListaPalavra(Palavra* pal){
    Palavra* aux;
    Palavra* t;

    for(aux=pal;aux!=NULL;aux=t);{
        t = aux->prox;
        free(aux->elem);
        free(aux);
        aux=t;
    }
}
