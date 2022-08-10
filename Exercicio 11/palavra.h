#ifndef TABELA_H
#define TABELA_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct palavra Palavra;

Palavra* inicPalavra (char* pal);

char* getPalavra(Palavra* p);

void setOcorrencias(Palavra* p);

int getOcorrencias(Palavra* p);

Palavra* buscaPalavra(Palavra* p, char* pal);

Palavra* inserePalavraLista(Palavra* lista, Palavra* p);

int contaPalavrasLista(Palavra* p);

void imprimeLista(Palavra* p);

void liberaListaPalavra(Palavra* pal);

#endif