#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    Arvore* arv;
    arv = inicArvore(50);
    arv = insereFolha(30,arv);
    arv = insereFolha(20,arv);
    arv = insereFolha(40,arv);
    arv = insereFolha(53,arv);
    arv = insereFolha(67,arv);
    arv = insereFolha(14,arv);
    arv = insereFolha(27,arv);
    arv = insereFolha(42,arv);
    arv = insereFolha(62,arv);
    arv = insereFolha(89,arv);
    arv = insereFolha(55,arv);
    arv = insereFolha(47,arv);
    arv = insereFolha(6,arv);
    imprimeCodigo(arv);
    if(buscaValorArvore(arv,30)){
        printf("\nhá 30 na árvore!\n");
    }else{
        printf("Não há 30 na árvore\n");
    }
    if(buscaValorArvore(arv,60)){
        printf("\nhá 60 na árvore!\n");
    }else{
        printf("Não há 60 na árvore\n");
    }

    retiraValor(arv, 67);

    printf("\n\n");

    imprimeCodigo(arv);

    destroiArvore(arv);

    return 0;
}
