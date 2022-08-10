#include "listaGen.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

typedef struct celulagen CelulaGen;

struct celulagen{
    CelulaGen* prox;
    void* elem;
};

struct listagen{
    CelulaGen* prim;
    CelulaGen* ult;
};

ListaGen* criaLista(void){
    ListaGen* nova;
    nova = malloc(sizeof(ListaGen));
    nova->prim=NULL;
    nova->ult=NULL;
    return nova;
}

ListaGen* insereLista(ListaGen* lista, void* elem){
    CelulaGen* novacel;
    novacel = malloc(sizeof(CelulaGen));
    novacel->elem=elem;
    if(lista->prim==NULL){
        lista->ult=novacel;
        lista->prim=novacel;
        novacel->prox=NULL;
    }
    else{
        novacel->prox=lista->prim;
        lista->prim=novacel;
    }
    return lista;

}

ListaGen* retiraLista(ListaGen* lista, int (*cb)(void*,void*),void* chave){
    CelulaGen* p;
    CelulaGen* aux;
    int nremov=1;
    
    if(lista->prim==NULL&&lista->ult==NULL){
        printf("\nLISTA VAZIA\n");
        return lista;
    }

    if(cb(lista->prim->elem,chave)){
        nremov=0;
        //caso seja o primeiro de uma lista com mais de uma célula
        if(lista->prim!=lista->ult){
            p=lista->prim;
            lista->prim=p->prox;
            free(p);
        }
        //caso seja o unico da lista
        else{
            free(lista->prim);
            lista->prim=NULL;
            lista->ult=NULL;
        }
    }
    else{

        for(aux=lista->prim,p=lista->prim->prox;p!=NULL;p=p->prox, aux=aux->prox){
            //caso seja no meio
            if(cb(p->elem,chave)){
                nremov=0;
                aux->prox=p->prox;
                //caso seja o ultimo
                if(p->prox==NULL){
                    lista->ult=aux;
                }
                free(p);
                break;
            }
        } 
        
    }
    if(nremov){
        printf("\nELEMENTO NAO ENCONTRADO\n");
    }
    else{
        printf("\nELEMENTO REMOVIDO\n");
    }
    return lista;
}

int percorreLista(ListaGen* lista, int(*cb)(void*, void*),void* dado){
    CelulaGen* p;
    for(p=lista->prim;p!=NULL;p=p->prox){
        cb(p->elem,NULL);
    }
    return 0;
}

void liberaLista(ListaGen* lista){
    CelulaGen* aux;
    CelulaGen* p;

    if(lista->prim!=lista->ult){
        for(aux=lista->prim,p=lista->prim->prox;p!=NULL;aux=p,p=p->prox){
            free(aux);
        }
        free(aux);
    }
    else{
        if(lista->prim!=NULL){
            p=lista->prim;
            free(p);
        }
    }
    free(lista);
    
}