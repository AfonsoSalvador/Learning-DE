#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "abb_matheus.h"

typedef struct arv Arv;

struct arv {
    Aluno * aluno;
    Arv * esq;
    Arv * dir;
};

Arv* arv_criavazia (void){
    return NULL;
}

Arv* arv_cria (Aluno * aluno, Arv* e, Arv* d){
    Arv * no = malloc(sizeof(Arv));
    no->aluno = aluno;
    no->esq = e;
    no->dir = d;

    return no;
}

Arv* arv_libera (Arv* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
    }

    free(a);
}

int arv_vazia (Arv* a){
    return a == NULL;
}

int arv_pertence (Arv* a, char * nome){
    return !strcmp(getNome(a->aluno), nome);
}

void arv_imprime (Arv* a){
    printf("<");
    if (!arv_vazia(a)){
        imprimeAluno(a->aluno);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }   
    printf(">");
}

Arv* arv_pai (Arv* a, char * nome){
    if (arv_pertence(a->esq, nome) || arv_pertence(a->dir, nome)) return a;
    else if (!arv_vazia(a->dir)) return arv_pai(a->dir, nome);
    else if (!arv_vazia(a->esq)) return arv_pai(a->esq, nome);
}

int folhas (Arv* a){
    if (arv_vazia(a)) return 0;
    else return 1 + folhas(a->esq) + folhas(a->dir);
}

int ocorrencias (Arv* a, Aluno * aluno){
    if (arv_vazia(a)) return 0;
    else return arv_pertence(a, getNome(aluno)) + ocorrencias(a->esq, aluno) + ocorrencias(a->dir, aluno);
}

Aluno * aluno (Arv* a){
    return a->aluno;
}

static int max(int a, int b) { return (a>b) ? a : b; }

int altura (Arv* a){
    if (arv_vazia(a)) return -1;
    else return 1 + max(altura(a->esq), altura(a->dir));
} 

Arv * abb_insere(Arv * a, Aluno * aluno){
    
    if (arv_vazia(a)){
        return arv_cria(aluno, arv_criavazia(), arv_criavazia());
    } else {
        int mBusca = getMatricula(aluno);
        int mArvore = getMatricula(a->aluno);

        if (mBusca>mArvore) a->dir = abb_insere(a->dir, aluno);
        else a->esq = abb_insere(a->esq, aluno);
        
        return a;
    }
}

Arv * abb_remove(Arv * a, Aluno * aluno){
    if (arv_vazia(a)) return NULL;

    int mBusca = getMatricula(aluno);
    int mArvore = getMatricula(a->aluno);

    if (mBusca<mArvore) {
        a->esq = abb_remove(a->esq, aluno);
    } else if (mBusca>mArvore) {
        a->dir = abb_remove(a->dir, aluno);
    } else {
        if (arv_vazia(a->dir) && arv_vazia(a->esq)){
            free(a);
            a=NULL;
        } else if (arv_vazia(a->esq)){
            Arv * aux = a;
            a = a->dir;
            free(aux);
        } else if (arv_vazia(a->dir)){
            Arv * aux = a;
            a = a->esq;
            free(aux);
        } else {
            Arv * antecessor = a->esq;
            
            while(antecessor->dir != NULL){
                antecessor = antecessor->dir;
            }

            Aluno * alunoAux = a->aluno;
            a->aluno = antecessor->aluno;
            antecessor->aluno=alunoAux;

            a->esq = abb_remove(a->esq, aluno);
        }
    }
    return a;
}
