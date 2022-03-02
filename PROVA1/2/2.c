#include <stdlib.h>
#include "lista.h"

#define MAX 30

struct lista{
    char no[MAX];
    int Fim;
};

Lista cria_lista(){
    Lista lst;
    lst = (Lista)malloc(sizeof(struct lista));
    if (lst != NULL)
        lst->Fim = 0;
    return lst;
}

int lista_vazia(Lista lst){
    if (lst->Fim == 0)
        return 1;
    else
        return 0;
}

int lista_cheia(Lista lst){
    if (lst->Fim == MAX)
        return 1;
    else
        return 0;
}

int apaga_lista(Lista *a){
    if(*a == NULL)
        return 0;
    free(*a);
    *a = NULL;
    return 1;
}

int intercala(Lista a,Lista b, Lista c){ 
    if (a==NULL||b==NULL||c==NULL){
        return 0
    
    }

    int i=0,j=0;

    while(i < a->Fim && j < b->Fim){
            c->no[c->Fim] = a->no[i];
            c->Fim++;
            i++;
            if (c->Fim == MAX){
                return 1;
        }else{
            c->no[c->Fim] = b->no[j];
            c->Fim++;
            j++;
        }if (c->Fim == MAX){
                return 1;
        }
    }

    if(i == a->Fim){
        for(; j < b->Fim; j++){
            c->no[i+j] = b->no[j];
            c->Fim++;
            if (c->Fim == MAX)
                return 1;
        }
        
    }else{
        for(; i<a->Fim; i++){
            c->no[i+j] = a->no[i];
            c->Fim++;
            if (c->Fim == MAX)
                return 1;
        }
    }
    return 1;
}

