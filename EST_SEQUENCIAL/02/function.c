#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"

#define max 20

struct l{
    char nome[50];
    int vol;
    float preco;
};

struct casas{
    int qnt;
    struct l info[max];
};

typedef struct casas lista;

lista *cria(void){
    lista *li;
    li = (lista*) malloc(sizeof(struct casas));
    if(li!=NULL) li->qnt = 0;
    return li;
}

void libera (lista *li){
    free(li);
}

int tamanho(lista *li){
    if (li == NULL) return -1;
    else return li->qnt;
}

int cheia(lista *li){
    if(li == NULL) return -1;
    return (li->qnt == max);
}

int vazia(lista *li){
    if(li == NULL) return -1;
    return (li->qnt == 0);
}

int insere(lista *li, char n[],int v,float p){
    if(li == NULL) return 0;
    if(cheia(li)) return 0;
    int k,i=0;
    while (i<li->qnt && li->info[i].nome[0] < n[0]) i++;
    for (k=li->qnt-1;k>=i; k--) li->info[k+1] = li->info[k];
    strcpy(li->info[li->qnt].nome,n);
    li->info[li->qnt].vol  = v;
    li->info[li->qnt].preco  = p;
    li->qnt++;
    return 1;
}

int rem(lista *li, char n[]){
    if(li == NULL) return 0;
    if(li->qnt == 0) return 0;
    int k,i = 0;
    while(i < li->qnt && (strcmp(li->info[i].nome,n) != 0)) i++;
    if (i == li->qnt) return 0;
    for (k = i; k < li->qnt-1; k++) li->info[k] = li->info[k+1];
    li->qnt--;
    return 1;
}

int pos(lista *li, char n[]){
    if(li == NULL) return 0;
    if(li->qnt == 0) return 0;
    int i = 0;
    while(i<li->qnt && strcmp(li->info[i].nome,n) != 0) i++;
    if (i == li->qnt){
        printf("Nao existente\n");
        return 0;
    }

    printf("\nA posicao eh %d ",i);
    return 1;
}

int imprime(lista *li){
    if(li == NULL) return 0;
    if(li->qnt == 0) return 0;
    int i;
    for (i = 0; i < li->qnt; i++){
        printf("\n %s  %d(ml)  R$%.2f ",li->info[i].nome, li->info[i].vol, li->info[i].preco);
    }
    return 1;
}

