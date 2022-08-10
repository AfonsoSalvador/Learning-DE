#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

struct item{
    int ID;
};

struct pilha{
    int max;
    int top;
    Item** itens;
};

Pilha* InicializaPilha(int max){
    Pilha* pilha;
    pilha= malloc(sizeof(Pilha));

    pilha->itens=malloc(sizeof(Item*)*max);

    pilha->max=max;

    pilha->top=0;

    return pilha;
}

void FPVaziaPilha (Pilha *pilha){
    Item* p;
    int tam;
    
    if(pilha->top==NULL|| pilha->top==0){
        return;
    }

    for(;TamanhoPilha(pilha)!=0;){
        p=PopPilha(pilha);
        DestroiItem(p);
    }

    return;

}

int EhVaziaPilha (Pilha* pilha){
    if(TamanhoPilha(pilha)==0){
        return 1;
    }
    else return 0;
}

int PushIDPilha (int ID,Pilha* pilha ){
    Item* item;
    if(!pilha || pilha->top==pilha->max){
        printf("ERRO: PILHA JA ESTA CHEIA");
        return 0;
    }

    item=InicializaItem(ID);

    if(!pilha->top){
        pilha->top=0;
    }

    pilha->itens[pilha->top]=item;
    pilha->top++;

    return 1;
}

Item* PopPilha (Pilha* pilha){
    Item* item;

    if(!pilha || pilha->top==0 || !pilha->top || !pilha->top==0){
        printf("ERRO: PILHA ESTA VAZIA");
        return NULL;
    }

    item=pilha->itens[pilha->top-1];
    pilha->itens[pilha->top-1]=NULL;
    pilha->top--;

    return item;
}

int PopIDPilha (Pilha* pilha){
    Item* item;
    int ID;

    if(!pilha || pilha->top==0 || !pilha->top || !pilha->top==0){
        printf("ERRO: PILHA ESTA VAZIA");
        return 0;
    }

    item=pilha->itens[pilha->top-1];
    pilha->itens[pilha->top-1]=NULL;
    pilha->top--;

    ID=item->ID;
    DestroiItem(item);

    return ID;
}

int TamanhoPilha (Pilha* pilha){
    if(!pilha->top||pilha->top==0){
        return 0;
    }
    else return pilha->top-1;
}

void ImprimePilha (Pilha* pilha){
    Item* p;
    int aux=0;
    
    if(!pilha->top||pilha->top==0){
        printf("----------PILHA VAZIA----------\n");
        return;
    }

    prinft("----------------- INICIO DA PILHA -----------------");
    for(p=pilha->itens[aux];  aux<pilha->top  ;aux++,p=pilha->itens[aux]){
        printf("\n\n");
        ImprimeItem(p);
        printf("\n\n");
    }
    prinft("------------------ FIM DA PILHA -------------------");


}

void DestroiPilha (Pilha* pilha){
    FPVaziaPilha(pilha);
    free(pilha->itens);
    free(pilha);
}

Item* InicializaItem (int n){
    Item* item;
    item=malloc(sizeof(item));
    item->ID==n;

    return item;
}

void ImprimeItem (Item* item){
    printf("\n ITEM ID : %d",item->ID);
    return;
}

void DestroiItem (Item* item){
    free(item);
    return;
}