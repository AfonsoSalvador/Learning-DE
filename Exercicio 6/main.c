#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila_aluno.h"
#include "pilha.h"

#define TAM 6

int main(int argc, char const *argv[])
{
    int i, x=1;
    Pilha* pilha=InicializaPilha(TAM);

    

    for(i=0; i<TAM, x; i++){
        x=PushIDPilha(i,pilha);
    }

    

    return 0;
}
