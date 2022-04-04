#include <stdlib.h>
#include "Deque.h"
#include <string.h>

#define MAX 11

struct fila{
    char info[MAX][21];
    int ini,fim;
};

Fila cria_fila(){
    Fila F = (Fila)malloc(sizeof(struct fila));
    if (F!=NULL){
        F->fim=0;
        F->ini=0;
    }
    return F;
}

int fila_vazia(Fila F){
    if (F!=NULL&&(F->ini==F->fim))
        return 1;
    return 0;
}

int fila_cheia(Fila F){
    if (F!=NULL && F->ini ==((F->fim+1)%MAX)) //encadeamento circular
        return 1;
    return 0;
}

int insere_elem_fim(Fila F, char a[]){
    if (F==NULL||fila_cheia(F)||strlen(a)>=21)
        return 0;
    strcpy(F->info[F->fim],a);
    F->fim = (F->fim+1)%MAX;
    return 1;
}

int insere_elem_ini(Fila F, char a[]){
    if (F==NULL||fila_cheia(F)||strlen(a)>=21)
        return 0;
    F->ini = (F->ini+MAX-1)%MAX;
    strcpy(F->info[F->ini],a);
    return 1;
}

int remove_elem_fim(Fila F, char a[]){
    if (F==NULL||fila_vazia(F))
        return 0;
    F->fim = (F->fim+MAX-1)%MAX;
    strcpy(a,F->info[F->fim]);
    return 1;
}

int remove_elem_ini(Fila F,char a[]){
    if (F==NULL||fila_vazia(F))
        return 0;
    strcpy(a,F->info[F->ini]);
    F->ini = (F->ini+1)%MAX;
    return 1;
}

int apaga_fila(Fila *F){
    if ((*F)==NULL)
        return 0;
    Fila aux = *F;
    free(aux);
    *F = NULL;
    return 1;
}

int esvazia_fila(Fila F){
    if (F==NULL)
        return 0;
    F->ini = 0;
    F->fim = 0;
    return 1;
}

int tamanho(Fila F, int *t){
    if (F==NULL)
        return 0;
    if (F->fim >= F->ini)
        *t = F->fim - F->ini;
    else
        *t = MAX - (F->ini - F->fim);
    return 1;
}
