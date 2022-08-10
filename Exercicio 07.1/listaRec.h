#ifndef LISTA_REC
#define LISTA_REC

#include "aluno.h"

typedef struct lista Lista;

Lista* inicLista();

void insereAlunoLista(Lista* lista, Aluno* aluno);

void retiraAlunoLista(Lista* lista, char* nome);

void imprimeLista(Lista* lista);

void comparaLista(Lista* lista1, Lista* lista2);

void destroiLista(Lista* lista);

void destroiListaes(Lista* lista);

#endif //LISTA_REC