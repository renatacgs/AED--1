#include <stdio.h>
#include <stdlib.h>
#include "03.h"

struct no{
    float info;
    struct no* prox;
};

/*
cria_lista
Entrada: nenhuma
Processo: cria uma lista com cabeçalho e seta ela pra estado vazio
Saida: tipo LISTA
*/
Lista cria_lista(){
    Lista cabe;
    cabe = (Lista) malloc(sizeof(struct no));

    if(cabe != NULL){
        cabe->prox = NULL;
        cabe->info = 0;
    }

    return cabe;
}


/*
lista_vazia
Entrada: tipo Lista
Processo: verifica se a lista esta vazia, o que ocorre se o cabelho aponta para NULL
Saida: 1, se vazia, 0, se nao vazia
*/
int lista_vazia(Lista lst){
    if(lst->prox == NULL)
        return 1;

    return 0;
}

/*
insere_ord
Entrada: tipo Lista, tipo float representado um elemento
Processo: Insere um novo elemento, ordenadamente, na lista
Saida: 0, em fracasso, 1, em sucesso
*/
int insere_ord(Lista lst, float elem){

    Lista novo;
    novo = (Lista) malloc(sizeof(struct no));

    if(novo == NULL)
        return 0;

    novo->info = elem;

    Lista aux = lst;

    while(aux->prox != NULL && aux->prox->info > elem)
        aux = aux->prox;

    novo->prox = aux->prox;
    aux->prox = novo;
    lst->info++;

    return 1;
}

/*
remover
Entrada: tipo Lista, tipo float representado um elemento
Processo: Remove um elemento da lista
Saida: 0, em fracasso, 1, em sucesso
*/
int remov(Lista lst, float elem){
    if(lista_vazia(lst))
        return 0;

    Lista aux = lst->prox,aux2 = lst;

    while(aux->info > elem && aux->prox != NULL){
        aux = aux->prox;
        aux2 = aux2->prox;
    }

    if(aux->prox == NULL || aux->info != elem){
        return 0;
    }else{
    aux2->prox = aux->prox;
    free(aux);
    }

    lst->info--;
    return 1;
}
/*remover na posição
Entrada: tio lista, int da posição e o float com o valor do elemento naquela posição
Processo: remove o elemento na posição digitada
Saida: 0, em fracasso e 1 em sucesso
*/
int remov_pos(Lista lst, int pos, float *valor){
    Lista aux = lst;
    if(lista_vazia(lst) || pos < 1 || pos > lst->info)
        return 0;

    int i = 1;
    while(i != pos){
        aux = aux->prox; 
        i++;
    }

    *valor = aux->prox->info; 

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);

    lst->info--; 

    return 1;
}


/*
obtem_elemento
Entrada: tipo Lista, inteiro representando posicao a ser retornada, endereco para float onde o valor sera armazenado
Processo: realiza a consulta de um elemento na lista
Saida: 0, em fracasso, 1, em sucesso
*/
int obtem_elem(Lista lst, int pos, float *valor){

    if(lista_vazia(lst) || pos < 1 || pos > lst->info)
        return 0;

    lst = lst->prox;

    int i = 1;
    while(i < pos){
        lst = lst->prox;
        i++;
    }

    *valor = lst->info;
    return 1;
}

/*
tamanho
Entrada: tipo Lista
Processo: consulta a quantidade de elementos da lista
Saida: quantidade de elementos da lista
*/
int tamanho(Lista lst){
    return lst->info;
}

/*
iguais
Entrada: dois tipo Lista
Processo: verifica se as duas listas recebidas sao iguais
Saida: 0, se nao, 1, se sim
*/
int iguais(Lista lst, Lista lst2){

    if(lista_vazia(lst) == 1 && lista_vazia(lst2) == 1)
        return 1;
    else if(lista_vazia(lst) == 1 || lista_vazia(lst2) == 1)
        return 0;
    else if (tamanho(lst) != tamanho(lst2))
        return 0;

    while(lst->prox != NULL){
        if(lst->prox->info != lst2->prox->info){
            return 0;
        }
        lst = lst->prox;
        lst2 = lst2->prox;
    }

    return 1;
}

/*
esvaziar
Entrada: tipo Lista
Processo: esvazia uma lista
Saida: nada
*/
void esvaziar(Lista lst){
    float valor;

    if(lista_vazia(lst) == 1)
        return;

    int i;
    for(i = 0; i < tamanho(lst); i++){
        obtem_elem(lst,1,&valor);
        remov(lst,valor);
    }

    lst->info = 0;
    lst->prox = NULL;
}
/*intercalar duas listas
Entrada: Lista 1 e lista 2
Processo: vai intercalar as duas listas e armazenar em uma terceira
Saida: a lista 3 com o resultado das duas listas intercaladas
*/
Lista intercala(Lista lst, Lista lst2){
    Lista lst3 = cria_lista();
    if (lista_vazia(lst)&&lista_vazia(lst2))
        return lst3;
    Lista aux1 = lst->prox;
    Lista aux2 = lst2->prox;
    Lista aux3 = lst3;
    if(lista_vazia(lst) == 1){
        while(aux2!=NULL){
            aux3->info = aux2->info;
            aux3->prox = (Lista)malloc(sizeof(struct no));
            aux3 = aux3->prox;
            aux2 = aux2->prox;
            lst3->info++;
        }
    }
    else if(lista_vazia(lst2) == 1){
        while(aux1!=NULL){
            aux3->info = aux1->info;
            aux3->prox = (Lista)malloc(sizeof(struct no));
            aux3 = aux3->prox;
            aux1 = aux1->prox;
            lst3->info++;
        }
    }

    while(aux1 != NULL && aux2 != NULL){

        aux3->prox = (Lista)malloc(sizeof(struct no));
        aux3 = aux3->prox;
        if(aux1->info > aux2->info){
            aux3->info = aux1->info;
            aux1 = aux1->prox;
        }else{
            aux3->info = aux2->info;
            aux2 = aux2->prox;
        }
        lst3->info++;
    }
        if (aux1 == NULL){
            while(aux2 != NULL){
                aux3->prox = (Lista) malloc(sizeof(struct no));
                aux3= aux3->prox;
                aux3->prox= NULL;
                aux3->info = aux2->info;
                aux2 = aux2->prox;
                lst3->info++;
            }
        } else {
            while (aux1 != NULL){
                aux3->prox = (Lista) malloc(sizeof(struct no));
                aux3= aux3->prox;
                aux3->prox= NULL;
                aux3->info = aux1->info;
                aux1 = aux1->prox;
                lst3->info++;
            }

        }
    aux3->prox = NULL;
    return lst3;

}
