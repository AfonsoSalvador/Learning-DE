#include<stdio.h>
#include<stdlib.h>
#include"listaAluno.h"

int main(int argc, char const *argv[])
{
    ListaGen* lista;

    lista=inicializaListaAluno();

    Aluno* a1;
    Aluno* a2;
    Aluno* a3;
    Aluno* a4;
    Aluno* a5;
    Aluno* a6;

    a1=inicializaAluno("Aluno01",1,7);
    a2=inicializaAluno("Aluno02",2,5);
    a3=inicializaAluno("Aluno03",3,2);
    a4=inicializaAluno("Aluno04",4,4);
    a5=inicializaAluno("Aluno05",5,7);
    a6=inicializaAluno("Aluno06",6,5);

    insereAluno(a1,lista);
    insereAluno(a2,lista);
    insereAluno(a3,lista);
    insereAluno(a4,lista);
    insereAluno(a5,lista);
    insereAluno(a6,lista);

    printf("Imprimindo lista com alunos inseridos \n\n");
    
    imprimeListaAluno(lista);

    printf("Retirando aluno com matricula 1\n\n");
    excluiAluno(lista, 1);

    printf("Imprimindo lista com o aluno retirado\n\n");
    imprimeListaAluno(lista);

    printf("Liberando lista\n");
    liberaLista(lista);
    
    printf("Liberando alunos da lista\n");
    destroiAluno(a1);
    destroiAluno(a2);
    destroiAluno(a3);
    destroiAluno(a4);
    destroiAluno(a5);
    destroiAluno(a6);



    return 0;
}
