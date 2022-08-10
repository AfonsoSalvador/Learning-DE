#include"listaAluno.h"
#include"aluno.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

//=========================================================

static int imprimeAluno(void* aluno, void* dado){
    printf("%s\nMatricula:%05d\nCR:%.2f\n\n",recuperaNome(aluno),recuperaMatric(aluno),recuperaCr(aluno));
    return 1;
}

//=========================================================

ListaGen* inicializaListaAluno(){
    return criaLista();
}

void insereAluno(Aluno* aluno, ListaGen* ListaGen){
    insereLista(ListaGen, aluno);
    return;
}

void excluiAluno(ListaGen* ListaGen, int mat){
    retiraLista(ListaGen,ehMesmaMatric, &mat);
    return;
}

void destroiListaAluno(ListaGen* ListaGen){
    liberaLista(ListaGen);
    return;
}

void imprimeListaAluno(ListaGen* ListaGen){
    percorreLista(ListaGen,imprimeAluno,NULL);
    return;
}
