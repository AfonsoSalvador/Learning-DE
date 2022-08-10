#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char nome[80];
    int matric,i;
    Aluno* aluno;
    Lista* lista;

    lista=inicializaLista();

    for(i=0;i<2;i++){
        printf("Digite o nome:\n");
        scanf("%s",nome);
        printf("Digite a matricula:\n");
        scanf("%d",&matric);
        aluno=inicializaAluno(nome,matric);
        insereAluno(aluno,lista);
    }

    imprimeLista(lista);



    return 0;
}

//gcc -c *.c
//gcc *.o -o prog


