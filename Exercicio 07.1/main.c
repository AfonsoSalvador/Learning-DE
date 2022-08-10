#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaRec.h"

int main(int argc, char const *argv[])
{
    Lista* listaG=inicLista();

    Lista* lista=inicLista();

    Lista* lista2=inicLista();

    Aluno* a1;Aluno* a2;Aluno* a3;Aluno* a4;Aluno* a5;



    a1=inicializaAluno("Afonso",123);a2=inicializaAluno("Salvador",123);
    a3=inicializaAluno("De",123);a4=inicializaAluno("Magalhaes",123);
    a5=inicializaAluno("Thamya",123);

    insereAlunoLista(listaG,a1);
    insereAlunoLista(listaG,a2);
    insereAlunoLista(listaG,a3);
    insereAlunoLista(listaG,a4);
    insereAlunoLista(listaG,a5);

    insereAlunoLista(lista,a1);

    insereAlunoLista(lista,a2);
    insereAlunoLista(lista,a3);insereAlunoLista(lista,a4);

    imprimeLista(lista);

    printf("Retirando Magalhaes da lista\n");
    retiraAlunoLista(lista,"Magalhaes");
    printf("Magalhaes retirado da lista \n");
    printf("Imprimindo lista sem Magalhaes\n\n");
    imprimeLista(lista);

    printf("Retirando Salvador da lista\n");
    retiraAlunoLista(lista,"Salvador");
    printf("Salvador retirado da lista \n");
    printf("Imprimindo lista sem Salvador\n\n");
    imprimeLista(lista);


    printf("Retirando Afonso da lista\n");
    retiraAlunoLista(lista,"Afonso");
    printf("Afonso retirado da lista \n");
    printf("Imprimindo lista sem Afonso\n\n");
    imprimeLista(lista);

    printf("Retirando De da lista\n");
    retiraAlunoLista(lista,"De");
    printf("De retirado da lista \n");
    printf("Imprimindo lista sem De\n\n");
    imprimeLista(lista);

    printf("Inserindo um novo aluno depois da retirada do ultimo\n");
    insereAlunoLista(lista,a5);
    imprimeLista(lista);

    printf("\n----------------------------------------------\n\n\n\n");
    printf("-----------TESTES DE COMPARAÇÃO DE LISTAS -----------\n");

    insereAlunoLista(lista2,a5);
    printf("Criando nova lista e inserindo o mesmo aluno para comparar\n");

    printf("\n\n\nImprimindo lista1\n\n");
    imprimeLista(lista);
    printf("Imprimindo lista2\n\n");
    imprimeLista(lista2);

    comparaLista(lista,lista2);



    insereAlunoLista(lista2, a3);

    printf("\n\n\nImprimindo lista1\n\n");
    imprimeLista(lista);
    printf("Imprimindo lista2\n\n");
    imprimeLista(lista2);


    comparaLista(lista,lista2);


    printf("\nDestruindo listas\n");
    destroiListaes(lista2);
    destroiListaes(lista);
    destroiLista(listaG);


    return 0;
}

