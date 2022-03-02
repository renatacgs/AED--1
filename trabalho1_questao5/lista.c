#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



struct no {
    int info;
    Lista prox;

};

/*
Cria lista
entrada: nenhuma
pré-condição: nenhuma
processo: nenhum
pós condição: nenhum
saida: NULL
*/
Lista cria_lista(){
    return NULL;
}

/*
lista_vazia
entrada: endereço de uma lista
pré-condição: nenhuma
processo: verifica se a lista está vazia
pós condição: nenhuma
saida: 1 se a lista está vazia, 0 caso contrario
*/

int lista_vazia(Lista lst){
    if (lst == NULL){
        return 1;
    } else {
        return 0;
    }

}

/*
insere_final
entrada: endereço do endereço de uma lista e um valor int
pré-condição: ter espaço na memoria para alocar um novo no
processo: insere o elemento no final da lista, caso a lista seja vazia, sera inserido no comeco (que tambem eh o final)
pós condição: um novo elemento é inserido no final da lista e a lista passa a apontar para esse novo elemento
saida: 1 se sucesso, 0 se falha
*/

int insere_final(Lista *lst, int elem){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N== NULL){
       return 0;
    }
    N->info = elem;

    if(lista_vazia(*lst) == 1){
        N->prox = N;
        *lst = N;
    } else {
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
    }
    return 1;
}

/*
insere_inicio
entrada: endereço do endereço de uma lista e um valor int
pré-condição: ter espaço na memoria para alocar um novo no
processo: insere o elemento no inicio da lista, caso a lista seja vazia, sera inserido no comeco.
pós condição: um novo elemento é inserido no inicio da lista e o lst->prox ira apontar para esse novo no que foi inserido
saida: 1 se sucesso, 0 se falha
*/

int insere_inicio (Lista *lst, int elem){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N== NULL){
       return 0;
    }
    N->info = elem;


    if(lista_vazia(*lst) == 1){
        N->prox = N;
        *lst = N;
    } else {
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
    }
    return 1;

}

/*
remove_inicio
entrada: endereço do endereço de uma lista e o endereco de um valor int
pré-condição: existir uma lista e a  lista nao pode estar vazia
processo: remove o primeiro elemento da lista, caso tenha apenas um, a lista aponta para NULL e a memoria alocada pelo NO é liberada.
pós condição: o primeiro elemento é removido da lista
saida: 1 se sucesso, 0 se falha
*/


int remove_inicio (Lista *lst, int *elem){

    if(lista_vazia(*lst) == 1){
        return 0;
    }
    Lista aux = (*lst)->prox;
    *elem = aux->info;
    if (*lst == (*lst)->prox){
        *lst = NULL;
    } else {
        (*lst)->prox = aux->prox;
    }
    free(aux);
    return 1;
}

/*
remove_final
entrada: endereço do endereço de uma lista e o endereco de um valor int
pré-condição: existir uma lista e a  lista nao pode estar vazia
processo: remove o ultimo elemento da lista, caso tenha apenas um, a lista aponta para NULL e a memoria alocada pelo NO é liberada.
pós condição: o ultimo elemento é removido da lista e a lista passa a apontar para o sucessor do no removido
saida: 1 se sucesso, 0 se falha
*/

int remove_final (Lista *lst, int *elem){

    if(lista_vazia(*lst) == 1){
        return 0;
    }
    *elem = (*lst)->info;
    Lista aux = (*lst)->prox;
    if (*lst == (*lst)->prox){
        *lst == NULL;
        free(aux);
    } else {
        while (aux->prox != (*lst))
            aux = aux->prox;
            aux->prox = (*lst)->prox;
            free(*lst);
            *lst = aux;
    }

    return 1;
}

/*
remove pares
entrada: endereco de uma lista
pré-condição: a lista nao estar vazia
processo: remove todos os numeros pares que estao na lista
pós condição: os numeros pares foram removidos da lista
saida: 1 se sucesso, 0 se falha
*/

int remove_pares(Lista *lst){
    if (lista_vazia(*lst) == 1){
        return 0;
    }
    Lista aux = *lst;

    if (*lst == (*lst)->prox){
        if ((*lst)->info % 2 == 0){
            *lst == NULL;
            free(aux);
        } else return 1;
    }else{

        while (aux->prox != *lst){
                if(aux->prox->info % 2 == 0){
                    Lista aux2 = aux->prox;
                    aux->prox = aux->prox->prox;
                    free(aux2);
                }
                aux = aux->prox;
        }

        if((*lst)->info % 2 == 0){
            aux->prox = (*lst)->prox; /
            Lista aux3 = *lst;
            free (aux3);
            *lst = aux;
        }
     }

    return 1;

}
/*
esvazia_lista
entrada: endereço do endereço de uma lista
pré-condição: a lista nao estar vazia
processo: apaga a lista, voltando ela para seu estado de vazia
pós condição: uma lista é apagada (ou limpa)
saida: 1 se sucesso, 0 se falha
*/

int esvazia_lista(Lista *lst){
    if(lista_vazia(*lst) == 1){
        return 0;
    } else{
    Lista aux = *lst;
        while (aux->prox != *lst){
            Lista aux2 = aux->prox;
            aux->prox = aux->prox->prox;
            free(aux2);
        }
        *lst = NULL;
        free(aux);
    }

    return 1;
}
/*
insere_pos
entrada: endereço do endereço de uma lista, uma posição index e um valor int
pré-condição: ter espaço na memoria para alocar um novo no e ser uma posição valida
processo: insere o elemento na posicao indicada da lista
pós condição: um novo elemneto é inserido na lista
saida: 1 se sucesso, 0 se falha
*/

int insere_pos(Lista *lst, int index, int elem){
    int i = 1;
    int cont = 1;

    if (index <= 0)
        return 0;

    Lista N = (Lista)malloc(sizeof(struct no));

    if (N == NULL)
    return 0;

    N->info = elem;

    if(index == 1 && lista_vazia(*lst)){
      N->prox = N;
     *lst = N;
     return 1;
    }

    Lista aux = (*lst)->prox; /
    while (aux->prox != (*lst)->prox){ /
        aux = aux->prox;
        cont++;
    }

    if(index > cont+1)
       return 0;

    Lista aux2 = (*lst)->prox;
        if (index == cont+1){
            N->prox = aux2->prox;
            aux2->prox = N;
            *lst = N;
        }else{

        while (i < index-1){
            aux2 = aux2->prox;
            i++;
        }

        N->prox = aux2->prox;
        aux2->prox = N;
    }

    return 1;
}


/*
get_tamanho_da_lista
entrada: endereço de uma lista, endereço de uma variavel int
pré-condição: nenhuma
processo: retorna o tamanho da lista por referencia
pós condição: nenhuma
saida: nenhuma
*/

void get_tamanho_da_lista(Lista lst,int *n){
    if (lst==NULL){
        *n = 0;
    }else {
        int i=0;
        Lista aux = lst;
        while (aux->prox!= lst){
            aux = aux->prox;
            i++;
        }
        *n = i+1;
    }
}

/*
get_elemento_posição
entrada: endereço da lista, posiçao do elemento e endereço de um int
pré-condição:a lista nao estar vazia e ser uma posiçao valida
processo: retorna o elemento na posição n por referencia
pós condição: nenhuma
saida: 1 se sucess0, 0 se falha
*/

int get_elem_pos(Lista lst,int n, int *valor){
    if (lst==NULL)
        return 0;
    int i;
    Lista aux = lst->prox;
    for (i=1;i<n;i++){
        if (aux == lst)
            break;
        aux = aux->prox;
    }
    *valor = aux->info;
    return 1;
}

