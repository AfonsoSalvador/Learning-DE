#ifndef LISTA_H
#define LISTA_H

#include "aluno.h"

typedef struct celula Celula;

typedef struct lista Lista;

Lista* inicializaLista();

void insereAluno(Aluno* aluno, Lista* lista);

void excluiAluno(Lista* lista, char* nome);

void destroiCelula(Celula* celula);

void destroiLista(Lista* lista);

void imprimeLista(Lista* lista);

#endif