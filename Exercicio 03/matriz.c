#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

struct matriz{
    float* matr;
    int linhas;
    int colunas;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz* mat;
    mat=malloc(sizeof(Matriz));
    mat->matr=malloc(sizeof(float)*nlinhas*ncolunas);
    mat->colunas=ncolunas;
    mat->linhas=nlinhas;
    return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->matr[(linha*mat->colunas)+coluna]=elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->matr[(linha*mat->colunas)+coluna];
}

int recuperaNColunas (Matriz* mat){
    return mat->colunas;
}

int recuperaNLinhas (Matriz* mat){
    return mat->linhas;
}

Matriz* transposta (Matriz* mat){
    int i,j;
    float temp;
    Matriz* trans;
    trans=inicializaMatriz(mat->colunas,mat->linhas);
    for(i=0;i<mat->colunas;i++){
        for(j=0;j<mat->linhas;j++){
            temp= recuperaElemento(mat,i,j);
            modificaElemento(trans,j,i,temp);
        }
    }

    return trans;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if(recuperaNColunas(mat1)!=recuperaNLinhas(mat2)){
        printf("Nao eh possivel multiplicar essas matrizes! Retornando NULO.\n\n");
        return NULL;
    }

    Matriz* multi;
    multi=inicializaMatriz(mat1->linhas,mat2->colunas);
    int i,j,k;
    float sum;

    for(i=0;i<mat1->linhas;i++){
        for(j=0;j<mat2->colunas;j++){
            for(k=0,sum=0;k<multi->colunas||k<multi->linhas;k++){
                sum+=recuperaElemento(mat1,i,k)*recuperaElemento(mat2,k,j);
            }
            modificaElemento(multi,i,j,sum);
        }
    }

    return multi;    
}

void imprimeMatriz(Matriz* mat){
    int i,j;

    for(i=0;i<mat->linhas;i++){
        for(j=0;j<mat->colunas;j++){
            printf("%02d ",recuperaElemento(mat,i,j));
        }
        printf("\n");
    }
    printf("\n\n");
}

void destroiMatriz(Matriz* mat){
    free(mat->matr);
    free(mat);
}
