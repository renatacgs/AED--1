#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"

lista *cria(void){
    lista *li;
    li = (lista*) malloc(sizeof(lista));
    if(li!=NULL) *li = NULL;
    return li;
}
int tamanho(lista *li){
    if (li == NULL) return 0;
    int contador = 0;
    cad* no = *li;
    while (no != NULL){
        contador++;
        no = no->no;
    }
    return contador;
}
int cheia(lista* li){
    return 0;
    }
int vazia(lista *li){
    if(li == NULL)
        return 0;
    if(*li == NULL)
    return 0;
    return 1;
}


int insere(lista *li,unsigned int matricula,char nome[],float media, int faltas){
    if(li == NULL) return 0;
    cad *n = (cad*) malloc(sizeof(cad));
    if(n == NULL) return 0;
    n->p.matricula = matricula;
    strcpy(n->p.nome,nome);
    n->p.media = media;
    n->p.faltas = faltas;
    n->no = NULL;
    if((*li) == NULL) *li = n;
    else{
        cad *aux = *li;
        while (aux->no != NULL) aux = aux->no;
        aux->no = n;
    }
    return 1;
}
int rem(lista *li,unsigned int b){
    if(li == NULL) return 0;
    cad *ant,*n = *li;
    while (n != NULL && n->p.matricula != b){
        ant = n;
        n = n->no;
    }
    if(n == NULL) return 0;
    if(n == *li) *li = n->no;
    else ant->no = n->no;
    free(n);
    return 1;
}
int posicao(lista *li,unsigned int b){
    if(li == NULL) return 0;
    cad *n = *li;
    int i = 1;
    while (n != NULL && n->p.matricula != b){
        n = n->no;
    }
    if(n == NULL) return 0;

}

void libera (lista *li){
    if(li != NULL){
        cad* no;
        while ((*li) != NULL){
            no = *li;
            *li = (*li)->no;
            free(no);
        }
        free(li);
    }
}
int imprime(lista *li){
    if(li == NULL) return 0;
    if(*li == 0) return 0;
    cad *ant,*n = *li;
    int i = 1;
    while (n != NULL){
        printf("%s\n%u\n%.2f\n%d\n",n->p.nome,n->p.matricula,n->p.media,n->p.faltas);
        n = n->no;
    }
    return 1;
}

