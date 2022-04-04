#include <stdlib.h>
#include "FilaPrioridade.h"


struct no{
    struct paciente info;
    struct no* prox;
};

struct fila{
    struct no* fim;
};

Fila cria_fila(){
    Fila F =(Fila)malloc(sizeof(struct fila));
    if (F!=NULL){
        F->fim = NULL;
    }
    return F;
}

int fila_vazia(Fila F){
    if (F!=NULL&&F->fim==NULL)
        return 1;
    return 0;
}

int insere_elem(Fila F, struct paciente a){
    if (F==NULL)
        return 0;
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if (novo==NULL)
        return 0;
    novo->info = a;
    if (fila_vazia(F)){
        F->fim = novo;
        novo->prox = novo;
    }else if (novo->info.gravidade<F->fim->prox->info.gravidade){   //se for menor que o primeiro elemento
        novo->prox = F->fim->prox;
        F->fim->prox = novo;
    }else if (novo->info.gravidade>=F->fim->info.gravidade){        //se for maior que o ultimo elemento
        novo->prox = F->fim->prox;
        F->fim->prox = novo;
        F->fim = novo;
    }else{                                                          //se nao for nenhuçm caso de cima, vai ter que percorrer
        struct no* aux = F->fim->prox;
        while(novo->info.gravidade>=aux->prox->info.gravidade){     //sempre olhando o da frente
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    return 1;
}

int remove_elem(Fila F, struct paciente* a){
    if (F==NULL||fila_vazia(F))
        return 0;
    struct no* aux = F->fim->prox;
    *a = aux->info;
    if (F->fim==F->fim->prox)   //se a lista só tem um elemento
        F->fim=NULL;
    else
        F->fim->prox = aux->prox;
    free(aux);
    return 1;
}

int apaga_fila(Fila *F){
    if ((*F)==NULL)
        return 0;
    struct no* aux = (*F)->fim;
    while(!fila_vazia(*F)){
        (*F)->fim = aux->prox;
        free(aux);
        aux = (*F)->fim;
    }
    free(*F);
    *F = NULL;
    return 1;
}

int esvazia_fila(Fila F){
    if (F==NULL)
        return 0;
    struct no* aux = F->fim;
    while(!fila_vazia(F)){
        F->fim = aux->prox;
        free(aux);
        aux = F->fim;
    }
    return 1;
}

int tamanho(Fila F, int *t){
    if (F==NULL||fila_vazia(F))
        return 0;
    int i=1;
    struct no* aux = (F->fim)->prox;
    while(aux!=F->fim){
        aux = aux->prox;
        i++;
    }
    *t = i;
    return 1;
}
