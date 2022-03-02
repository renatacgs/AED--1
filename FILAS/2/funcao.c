#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"

struct nomes{
    char palavra[30];
};

struct fila{
    int ini,qnt, fim;
    struct nomes Nome[];
};

Fila * cria_fila(void){
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if (fi != NULL){
        fi->ini = 0;
        fi->qnt = 0;
        fi->fim = 0;
    }
    return fi;
}

void libera_fila(Fila *fi){
    free(fi);
}

int tamanho_fila(Fila *fi){
    if (fi == NULL) return -1;
    return fi->qnt;
}

int fila_cheia(Fila *fi){
    if (fi == NULL) return -1;
    else return 0;
}

int fila_vazia(Fila *fi){
    if (fi == NULL) return -1;
    else return 0;
}

int insere_fila(Fila *fi,char dados[]){
    if (fi == NULL) return 0;
    if (fila_cheia(fi)) return 0;
    strcpy(fi->Nome[fi->fim].palavra,dados);
    fi->qnt++;
    return 1;
}

int remove_fila(Fila *fi){
    if (fi == NULL || fila_vazia(fi)) return 0;
    fi->qnt--;
    return 1;
}

int consulta_fila(Fila *fi, char *dados[]){
    if (fi == NULL || fila_vazia(fi)) return 0;
    *dados = fi->Nome[fi->ini].palavra;
    return 1;
}

void imprime(Fila *fi){
    if (fi == NULL || fila_vazia(fi)) printf("\nNada para imprimir !");
    for (int i=0; i<fi->qnt; i++){
        printf("\n%s \n",fi->Nome[i].palavra);
    }
}
