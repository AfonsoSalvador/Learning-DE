#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char* Nome; 
  int matricula;
  float p1,p2,p3;
}Aluno;

void imprime_aprovados (int n, Aluno** turma);

float media_turma (int n, Aluno** turma);

float media_aluno(Aluno* aluno);

void registra_aluno(int count,int n,Aluno** turma);

Aluno* cadastra_aluno(char* Nome, int matricula, float p1, float p2, float p3);

void destroi_aluno(Aluno* aluno);

void imprime_turma(int n, Aluno** turma);

void adicionar_aluno(int n, int novo, Aluno** turma);

int main(void) {

    int status=4,qtd=0,count=0;
    char nome[80],selecao;
    int matricula;
    float p1, p2, p3;
    Aluno* aluno;


    printf("Quantos alunos há na turma?\n");
    scanf("%d",&qtd);
            
    Aluno** turma = (Aluno**) malloc (qtd * sizeof(Aluno*));

    for(count=0;count<qtd;count++){
        printf("\n---------------Aluno %d---------------\n\n",count+1);
        printf("Nome:  ");
        scanf("%*c");
        scanf("  %79[^\n]",nome);
        printf("Matricula:  ");
        scanf("%d",&matricula);
        printf("Prova 1:  ");
        scanf("%f",&p1);
        printf("Prova 2:  ");
        scanf("%f",&p2);
        printf("Prova 3:  ");
        scanf("%f",&p3);

        aluno=cadastra_aluno(nome,matricula,p1,p2,p3);
        turma[count]=aluno;

        system("clear");
        printf("Aluno %d cadastrado!\n\n\n",count+1);


          
            
    }
  
    imprime_turma(qtd,turma);

  while(1){
    printf("------------PROGRAMA DE GERENCIAMENTO DE ALUNOS------------\n\n");
    printf("--------------------O QUE DESEJA FAZER?--------------------\n\n");
    
    printf("1-Mostrar Aprovados\n2-Media da turma\n3-Listar Turma\n4-Sair\n\n");

    scanf("%d",&status);
    


    system("clear");
    
    switch (status){          
        case 1: 
            if(qtd<1){
                printf("É necessário primeiro registrar a turma, pressione ENTER e selecione 'Cadastrar alunos'\n");
                scanf("%*c");
                break;
            }
            printf("APROVADOS:\n\n");
            imprime_aprovados(qtd,turma);
            scanf("%*c");
            printf("\n\n");
            break;


        case 2:
            printf("Media da turma: %.2f\n\n",media_turma(qtd,turma));
            
            
            break;

        case 3:
          imprime_turma(qtd,turma);

          printf("continuar? Digite 's'\n");
          scanf("%c",&selecao);
          
          break;

        case 4: 
            for(count=0;count<qtd;count++){
                destroi_aluno(turma[count]);
            }
            free(turma);

            exit(0);
        
        default:
            printf("\nNumero nao aceito, selecione uma opcao mostrada no perfil\n");
            scanf("%*c");
            system("clear");
            break;

  
    }
  }
  
  
  if(status!=4){
  for(count=0;count<qtd;count++){
        destroi_aluno(turma[count]);
    }
    free(turma);
    }
    
  return 0;
}


Aluno* cadastra_aluno(char* Nome, int matricula, float p1, float p2, float p3){
    
    Aluno* aluno= malloc(sizeof(Aluno));
    aluno->matricula=matricula;
    aluno->Nome=strdup(Nome);
    aluno->p1=p1;
    aluno->p2=p2;
    aluno->p3=p3;

    return aluno;
}


void imprime_aprovados (int n, Aluno** turma){
  int count, flag=0;

  for(count=0;count<n;count++){
    if(media_aluno(turma[count])>=5){
      flag=1;
      printf("%s\n",turma[count]->Nome);
    }
  }
  if(flag==0){
    printf("NAO HA ALUNOS APROVADOS\n\n");
  }
  
}

float media_aluno(Aluno* aluno){
  float media, soma=0;

  media+=aluno->p1;
  media+=aluno->p2;
  media+=aluno->p3;

  media/=3;

  return media;
  
  
}

float media_turma (int n, Aluno** turma){
  float media=0;
  int count;

  for(count=0;count<n;count++){
    media+=media_aluno(turma[count]);
  }
  media/=n;
  return media;
}


void destroi_aluno(Aluno* aluno){
    free(aluno->Nome);
    free(aluno);
}

void imprime_turma(int n, Aluno** turma){
  int count;

  for(count=0;count<n;count++){
    printf("--------------ALUNO %d--------------\nNOME: %s\nMATRICULA: %d\n NOTAS: %.2f, %.2f, %.2f\n\n"
    ,count+1,turma[count]->Nome,turma[count]->matricula,turma[count]->p1,turma[count]->p2,turma[count]->p3);
  }
  
}


void adicionar_aluno(int n, int novo, Aluno** turma){
  turma=realloc(turma,sizeof(Aluno*)*novo);
  registra_aluno(n,novo,turma);

}

void registra_aluno(int count,int n,Aluno** turma){
  char nome[80];
  int matricula, i=count;
  float p1, p2, p3;
  Aluno* aluno;

  for(;i<n;count++){
    printf("\n---------------Aluno %d---------------\n\n",i+1);
    printf("Nome:  ");
    scanf("%*c");
    scanf("  %79[^\n]",nome);
    printf("Matricula:  ");
    scanf("%d",&matricula);
    printf("Prova 1:  ");
    scanf("%f",&p1);
    printf("Prova 2:  ");
    scanf("%f",&p2);
    printf("Prova 3:  ");
    scanf("%f",&p3);

    aluno=cadastra_aluno(nome,matricula,p1,p2,p3);
    turma[i]=aluno;

    system("clear");
    printf("Aluno %d cadastrado!\n\n\n",i+1);


          
            
  }
}