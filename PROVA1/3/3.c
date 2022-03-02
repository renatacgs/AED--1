#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{

	struct produto info;
	struct no* ant;
	struct no* prox;

};

int lista_vazia(Lista lst){

    if(lst == NULL) return 1;

    return 0;

}

int remove_menor(Lista *lst, struct produto *p){

    if(lista_vazia(*lst)) return 0;

    Lista aux = *lst;

    *lst = aux->prox;
    *p = aux->info;

    free(aux);

    return 1;

}

int insere_produto(Lista *lst, struct produto elem){

	Lista no = (Lista) malloc(sizeof(struct no));
	if (no == NULL) return 0;

	no->info = elem;

    Lista aux = *lst; 

    if((aux->info).codigo > elem.codigo){

        no->prox = aux;
        no->ant = aux->ant;
        aux->ant = no;

    }else{

        aux = (*lst)->prox; 
        Lista aux_ant = *lst;

        while((aux->info).codigo < elem.codigo && aux != NULL){
        
            aux = aux->prox;
            aux_ant = aux_ant->prox;

        }

    }   

    if(aux != NULL){

        no->prox = aux;
        no->ant = aux->ant;
        aux->ant = no;

    }else{ 

        no->prox = NULL;
        no->ant = aux_ant;

    }

	return 1;

}