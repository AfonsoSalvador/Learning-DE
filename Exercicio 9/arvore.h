#ifndef ARVORE_H
#define ARVORE_H

typedef struct arvore Arvore;

Arvore* inicArvore(int valor);

Arvore* insereFolha(int valor, Arvore* arv);

//------------------------------------------------

int ehFolha (Arvore* arv);

//------------------------------------------------

int buscaValorArvore (Arvore* arv, int chave);

Arvore* buscaArvoreArvore (Arvore* arv, int chave);

//------------------------------------------------

void imprimeArvore (Arvore* arv);

void imprimeCodigo(Arvore* arv);

//------------------------------------------------

Arvore* retiraValor(Arvore* arv, int valor);


//------------------------------------------------

void destroiArvore(Arvore* arv);

void destroiNo(Arvore* arv);

#endif //ARVORE_H