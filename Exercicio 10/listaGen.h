#ifndef LISTA_GEN
#define LISTA_GEN

#include <stdio.h>

typedef struct listagen ListaGen;

ListaGen* criaLista(void);

ListaGen* insereLista(ListaGen* lista, void* elem);

ListaGen* retiraLista(ListaGen* lista, int (*cb)(void*,void*),void* chave);

int percorreLista(ListaGen* lista, int(*cb)(void*, void*),void* dado);

void liberaLista(ListaGen* lista);






#endif