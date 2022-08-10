#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char nome[80];
    int matric,i,count;
    Aluno* aluno;
    Lista* lista1;
    Lista* lista2;

    lista1=inicializaLista();
    lista2=inicializaLista();

    printf("Digite o numero de alunos:\n");
    scanf("%d",&count);

    for(i=0;i<count;i++){
        printf("Digite o nome:\n");
        scanf("%s",nome);
        printf("Digite a matricula:\n");
        scanf("%d",&matric);
        aluno=inicializaAluno(nome,matric);
        if(recuperaMatric(aluno)%2){
            insereAluno(aluno,lista1);
        }
        else
        insereAluno(aluno,lista2);
    }

    printf("IMPRIMINDO LISTA1 INVERTIDA\n");
    imprimeLista(lista1, 2);

    printf("IMPRIMINDO LISTA2 NORMAL\n");
    imprimeLista(lista2, 1);

    printf("Digite um nome para remover da lista 1:\n");
    scanf("%s",nome);
    excluiAluno(lista1,nome);

    printf("Digite um nome para remover da lista 2:\n");
    scanf("%s",nome);
    excluiAluno(lista2,nome);

    imprimeLista(lista1, 1);
    imprimeLista(lista2, 1);

    destroiLista(lista1);
    destroiLista(lista2);

    return 0;
}

//gcc -c *.c
//gcc *.o -o prog


