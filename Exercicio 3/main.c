#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{
    Matriz  *Mat1, *Mat2, *MatT, *MatM;
    int i,j,val;

    Mat1=inicializaMatriz(3,3);

    Mat2=inicializaMatriz(3,3);

    for(i=0,val=0;i<3;i++){
        for(j=0;j<3;j++){
            val++;
            modificaElemento(Mat1,i,j,val);
            modificaElemento(Mat2,i,j,val*2);
        }
        
    }
    printf("Imprimindo mat1\n");
    imprimeMatriz(Mat1);


    printf("\n adquirindo o valor de coordenadas 1/2\n");
    printf("Valor: %02d\n\n",recuperaElemento(Mat1,0,1));


    printf("\n adquirindo numero de linhas e colunas de mat1:\n");
    printf("Numero de linhas: %d Numero de colunas: %d\n\n",recuperaNLinhas(Mat1),recuperaNColunas(Mat1));

    printf("Imprimindo mat2\n");
    imprimeMatriz(Mat2);

    printf("\nTranspondo mat2\n");
    MatT=transposta(Mat2);
    printf("\nImprimindo Transposta de mat2\n");
    imprimeMatriz(MatT);


    printf("\n\n\nImprimindo mat1 e mat2:\n");
    imprimeMatriz(Mat1);
    imprimeMatriz(Mat2);

    printf("\n\nMultilicando mat1 com mat2");
    MatM=multiplicacao(Mat1,Mat2);
    printf("Imprimindo o resultado:\n");
    imprimeMatriz(MatM);


    printf("\nDestruindo todas as matrizes, tchau!");

    destroiMatriz(Mat1);
    destroiMatriz(Mat2);
    destroiMatriz(MatT);

    
    destroiMatriz(MatM);
    



    return 0;
}
