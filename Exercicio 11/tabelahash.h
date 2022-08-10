#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include "palavra.h"

typedef struct hash Hash;

Hash* iniciaHash(int tamanho);

Palavra* insere (Hash* h, char* palavra);

int contaPalavras(Hash* h);

void imprimeHash(Hash* h);

void liberaHash(Hash* h);

#endif