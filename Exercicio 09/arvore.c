#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvore
{
    Arvore* dir;
    Arvore* esq;
    int valor;
};

Arvore* inicArvore(int valor){
    Arvore* nova;
    nova = malloc(sizeof(Arvore));
    nova->valor=valor;
    nova->dir=NULL;
    nova->esq=NULL;
    return nova;
}

Arvore* insereFolha(int valor, Arvore* arv){
    if(arv->valor>valor){
        if(arv->esq==NULL){
            Arvore* nova;
            nova = inicArvore(valor);
            arv->esq = nova;
        }
        else{
            arv->esq=insereFolha(valor,arv->esq);
        }
    }

    else if(arv->valor<valor){
        if(arv->dir==NULL){
            Arvore* nova;
            nova = inicArvore(valor);
            arv->dir = nova;
        }
        else{
            arv->dir=insereFolha(valor,arv->dir);
        }
    }

    return arv;
}

int ehFolha (Arvore* arv){
    if(arv->dir==NULL && arv->esq==NULL){
        return 1;
    }
    else return 0;
}

int buscaValorArvore (Arvore* arv, int chave){
    if(arv->valor>chave){
        if(arv->esq==NULL){
            return 0;
        }
        else{
            return buscaValorArvore(arv->esq, chave);
        }
    }
    else if(arv->valor<chave){
        if(arv->dir==NULL){
            return 0;
        }
        else{
            return buscaValorArvore(arv->dir, chave);
        }
    }
    else{
        return 1;
    }

}

Arvore* buscaArvoreArvore (Arvore* arv, int chave){
    
    if(arv->valor>chave){
        if(arv->esq==NULL){
            return NULL;
        }
        else{
            return arv;
        }
    }
    else if(arv->valor<chave){
        if(arv->dir==NULL){
            return NULL;
        }
        else{
            return arv;
        }
    }
    else{
        return arv;
    }
}

void imprimeCodigo(Arvore* arv){
    printf("\nstrict graph{\n");
    imprimeArvore(arv);
    printf("}\n");
    return;
}

void imprimeArvore (Arvore* arv){
    
    if(arv != NULL){
        if(arv->esq!=NULL){
        printf("%d -- %d\n",arv->valor,arv->esq->valor);
        }
        if(arv->dir!=NULL){
        printf("%d -- %d\n",arv->valor,arv->dir->valor);
        }
        imprimeArvore(arv->esq);
        imprimeArvore(arv->dir);
    }

    
    return;
}

Arvore* retiraValor(Arvore* arv, int valor){
    if(arv==NULL){
        return NULL;
    }
    else if(valor<arv->valor){
        arv->esq = retiraValor(arv->esq, valor);
    }
    else if(valor>arv->valor){
        arv->dir = retiraValor(arv->dir, valor);
    }
    else{
        if(arv->dir==NULL && arv->esq==NULL){
            free(arv);
            arv=NULL;
        }
        else if(arv->esq==NULL){
            Arvore* aux = arv;
            arv = arv->dir;
            free(aux);
        }
        else if(arv->dir==NULL){
            Arvore* aux = arv;
            arv = arv->esq;
            free(aux);
        }
        else{
            Arvore* ant = arv->esq;
            while(ant->dir != NULL){
                ant = ant->dir;
            }
            int valoraux = arv->valor;
            arv->valor=ant->valor;
            ant->valor=valoraux;

            arv->esq = retiraValor(arv->esq,valor);
        }
    }
    return arv;
}

void destroiArvore(Arvore* arv){
    if(ehFolha(arv)){
        destroiNo(arv);
        return;
    }
    if(arv->esq!=NULL){
        destroiArvore(arv->esq);
    }
    if(arv->dir!=NULL){
        destroiArvore(arv->dir);
    }
    destroiNo(arv);
    return;
}

void destroiNo(Arvore* arv){
    free(arv);
    return;
}