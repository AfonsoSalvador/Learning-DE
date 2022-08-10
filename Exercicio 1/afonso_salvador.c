#include <stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14

void calc_esfera (float r, float* area, float* volume);
int raizes (float a, float b, float c, float* x1, float* x2);
int pares (int n, int* vet);
void inverte (int n, int* vet);
double avalia (double* poli, int grau, double x);

int main(void) {
  float* area   = (float*)malloc(sizeof(float));
  float* volume = (float*)malloc(sizeof(float));
  
  float* x1     = (float*)malloc(sizeof(float));
  float* x2     = (float*)malloc(sizeof(float));
  
  int raiz = 0;
  

  int* vet = malloc(sizeof(int)*10);

  for(int x=0; x<10; x++){
    vet[x]=x+1;
  }


  int par=0;

  double poli[3]={1,2,3};

  double res=0;

  calc_esfera(5.0,area,volume);
  raiz=raizes(1.0,-6.0,8.0,x1,x2);
  par=pares(10,vet);
  inverte(10,vet);
  res=avalia(poli,2,3);
  




  free(vet);
  free(area);
  free(volume);
  free(x1);
  free(x2);
  
  return 0;
}

void calc_esfera (float r, float* area, float* volume){
  *area= 4*PI*pow(r,2);
  *volume= (4*PI*pow(r,3))/3;

  printf("A área da esfera é de %.2f e seu volume é de %.2f\n",*area, *volume);
  
}

int raizes (float a, float b, float c, float* x1, float* x2){
 *x1=((-b+sqrt(pow(b,2)-(4*a*c)))/2*a);
 *x2=((-b-sqrt(pow(b,2)-(4*a*c)))/2*a);

  printf("as raízes da função são: %.2f e %.2f\n",*x1,*x2);
    
  if(*x1<0 || *x2<0){
    return 0;
  }
  return 1;
}

int pares (int n, int* vet){
  int count, j;

  for(count=0, j=0;j<n;j++){
    if(vet[j]%2==0){
      count++;
    }
  }

  printf("Dentro deste vetor há %d números pares\n",count);
  
  return count;
}

void inverte (int n, int* vet){
  int novoVet[n], j, k;

  for(j=n-1,k=0;k<n;j--,k++){
    novoVet[k]=vet[j];
  }

  for(j=0;j<n;j++){
    vet[j]=novoVet[j];
  }

  printf("O vetor invertido é:\n<");
  
  for(j=0;j<n;j++){
    if(j!=0){
      printf(",");
    }
    printf("%d ",vet[j]);
    
  }
  printf(">\n");
}

double avalia (double* poli, int grau, double x){
  int j,h;
  double res;

  for(j=1,res=poli[0];j<=grau;j++){
    res+=poli[j]*pow(x,j);
  }

  printf("O resultado desta função é %.2f\n",res);

  return res;
}


