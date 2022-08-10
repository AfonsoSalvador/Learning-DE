#ifndef PILHA_H
#define PILHA_H

typedef struct item Item;
typedef struct pilha Pilha;

Pilha* InicializaPilha(int max);

void FPVaziaPilha (Pilha *pilha);

int EhVaziaPilha (Pilha* pilha);

int PushPilha (Item* item,Pilha* pilha );

int PushIDPilha (int ID,Pilha* pilha )

Item* PopPilha (Pilha* pilha);

int PopIDPilha (Pilha* pilha);

int TamanhoPilha (Pilha* pilha);

void ImprimePilha (Pilha* pilha);

void DestroiPilha (Pilha* pilha);

Item* InicializaItem (int n);

void ImprimeItem (Item* item);

void DestroiItem (Item* item);


#endif