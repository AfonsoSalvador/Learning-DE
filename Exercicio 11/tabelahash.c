#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tabelahash.h"
#include"palavra.h"

struct hash{
    Palavra** vet;
    int tamanho;
};

static int hash (char* s, int tam){
    int i;
    int total = 0;
    for(i=0;s[i]!='\0';i++){
        total += s[i];
    }
    return (total % tam);
}


Hash* iniciaHash(int tamanho){
    int i;
    Hash* h = malloc(sizeof(Hash));
    h->tamanho=tamanho;
    h->vet=malloc(tamanho*sizeof(Palavra*));
    for(i=0; i<tamanho; i++){
        h->vet[i]=NULL;
    }
    return h;
}

Palavra* insere (Hash* h, char* palavra);

int contaPalavras(Hash* h);

void imprimeHash(Hash* h);

void liberaHash(Hash* h);