#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no* prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista a){
    if (a!=NULL)
        return 0;
    return 1;
}

int insere_car(Lista *a, char elem){
    Lista b = (struct no*)malloc(sizeof(struct no));
    if (b==NULL)
        return 0;
    b->info = elem;
    if (*a==NULL){  
        *a = b;
        b->prox=NULL;
        return 1;
    }
    b->prox = (*a); 
    *a = b;         
    return 1;
}

int apaga_lista(Lista *a){
    if (*a == NULL)
        return 0;
    Lista aux = *a , aux2 = (*a)->prox;
    while (aux2!= NULL){
        free(aux);
        aux = aux2;
        aux2 = aux2->prox;
    }
    *a = NULL;
    return 1;
}

int remove_ultimavogal(Lista *a, char *elem){
    if (*a == NULL) 
        return 0;
    
    Lista aux = *a;     
    Lista vogal = aux; 
    vogal = 'A' || 'a' || 'E' || 'e' || 'I' || 'i' || 'O' || 'o' || 'U' || 'u'
    while(aux->prox!=vogal){
        if (vogal->prox->info <= aux->prox->info) 
            vogal = aux;
        aux = aux->prox;
    }
    if ((*a)->info > vogal->prox->info){    
        vogal = (*a);
        *a = (*a)->prox;
    }else {
        aux = vogal;
        vogal=vogal->prox;
        aux->prox = aux->prox->prox;
    }
    *elem = vogal->info;
    free(vogal);
    return 1;
}
