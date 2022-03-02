#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"

struct fila{
    struct elemento *ini;
    struct elemento *fim;
};

struct elemento{
    struct bebida dados;
    struct elemento *prox;
};

typedef struct elemento elem;

lista * cria_fila(void){
    lista* fi = (lista*)malloc(sizeof(lista));
    if (fi != NULL){
        fi->fim = NULL;
        fi->ini = NULL;
    }
    return fi;
}

void libera_fila(lista*fi){
    if(fi != NULL){
        elem* no;
        while (fi->ini != NULL){
            no = fi->ini;
            fi->ini = fi->ini->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_fila(lista*fi){
    if(fi == NULL) return 0;
    int cont = 0;
    elem* no = fi->ini;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int fila_cheia(lista *fi){
    return 0;
}

int fila_vazia(lista *fi){
    if(fi == NULL) return 1;
    if(fi->ini == NULL) return 1;
    return 0;
}

int insere_fila(lista *fi, struct bebida b){
    if(fi == NULL) return 0;
    elem *no = (elem*) malloc(sizeof(elem));
    if(no == NULL) return 0;
    no->dados = b;
    no->prox = NULL;
    if(fi->fim == NULL) fi->ini = no;
    else fi->fim->prox = no;
    fi->fim = no;
    return 1;
}

int remove_fila(lista *fi){
    if(fi == NULL || fi->ini == NULL) return 0;
    elem *no = fi->ini;
    fi->ini = fi->ini->prox;
    if(fi->ini == NULL) fi->fim = NULL;
    free(no);
    return 1;
}

int consulta_fila(lista *fi, struct bebida *b){
    if(fi == NULL || fi->ini == NULL) return 0;
    *b = fi->ini->dados;
    return 1;
}

void imprime(lista *fi){
    if (fi == NULL || fila_vazia(fi)) printf("\nNada a imprimir.");
    elem *no = fi->ini;
    while (no != NULL){
        printf("\nCodigo: %d\n Descricao: %s\n Preco: %f\n",no->dados.codigo, no->dados.descricao, no->dados.preco);
        no = no->prox;
    }
}
