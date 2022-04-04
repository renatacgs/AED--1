#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

struct pilha{
    int tipo;
    Tipo_dado elem;
    struct pilha* prox;
};

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha pi){
    if(pi == NULL)
        return 1;
    else
        return 0;
}

int push (Pilha* pi, Tipo_dado elem){
    if(pi == NULL)
        return 0;
    Pilha no = (Pilha) malloc(sizeof(struct pilha));
    if(no == NULL)
        return 0;
    no->elem = elem;
    no->prox = *pi;
    *pi = no;
    return 1;
}

int pop (Pilha* pi, Tipo_dado* aleluia){

    if(pilha_vazia(*pi))
        return 0;
    Pilha aux = *pi;
    *aleluia = aux->elem;
    *pi = aux->prox;
    free(aux);
    return 1;
}

int le_topo (Pilha pi,Tipo_dado* elem){
    if (pilha_vazia(pi))
        return 0;
    *elem = pi->elem;
    return 1;
}
