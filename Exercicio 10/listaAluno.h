#ifndef ListaGen_ALUNO
#define ListaGen_ALUNO

#include<stdio.h>
#include "listaGen.h"
#include "aluno.h"

ListaGen* inicializaListaAluno();

void insereAluno(Aluno* aluno, ListaGen* ListaGen);

void excluiAluno(ListaGen* ListaGen, int mat);

void destroiListaAluno(ListaGen* ListaGen);

void imprimeListaAluno(ListaGen* ListaGen);

#endif //ListaGen_ALUNO