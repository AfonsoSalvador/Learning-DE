#ifndef LISTA_REC
#define LISTA_REC

#include "aluno.h"

typedef struct lista Lista;

Lista* inicLista();

void insereAlunoLista(Lista* lista, Aluno* aluno);

void retiraAlunoLista(Lista* lista, char* nome);

void imprimeLista(Lista* lista);

void destroiLista(Lista* lista);


#endif //LISTA_REC