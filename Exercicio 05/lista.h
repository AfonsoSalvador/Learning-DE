#ifndef LISTA_H
#define LISTA_H

#include "aluno.h"

typedef struct celula Celula;//ok

typedef struct lista Lista;//ok

Lista* inicializaLista();//ok

void insereAluno(Aluno* aluno, Lista* lista);//ok

void excluiAluno(Lista* lista, char* nome);//ok

void destroiCelula(Celula* celula);//ok

void destroiLista(Lista* lista);//ok

void imprimeLista(Lista* lista, int orient);//ok

#endif