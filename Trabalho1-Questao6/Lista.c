#include <stdlib.h>
#include <string.h>
#include "Lista.h"

#define MaxNome 20



struct no{
    double info;
    struct no* prox;
    struct no* ant;
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
int lista_vazia(Lista a){
    if (a!=NULL)
        return 0;
    return 1;
}

/*
insere elemento
entrada: endereço do endereço de uma lista e um valor double
pré-condição: ter espaço na memoria para alocar um novo no
processo: insere o elemento no começo da lista
pós condição: um novo elemneto é inserido na lista
saida: 1 se sucesso, 0 se falha
*/
int insere_elem(Lista *a, double valor){
    Lista b = (struct no*)malloc(sizeof(struct no));    //Criando o novo nó e já atribuindo os valores
    if (b==NULL)
        return 0;
    b->info = valor;
    b->ant = NULL;
    b->prox = *a;
    if ((*a)!=NULL)
        (*a)->ant = b;
    (*a) = b;
    return 1;
}

/*
insere elemento posição
entrada: endereço do endereço de uma lista, uma posição n e um valor double
pré-condição: ter espaço na memoria para alocar um novo no e ser uma posição valida
processo: insere o elemento na posiçlão indicada da lista
pós condição: um novo elemneto é inserido na lista
saida: 1 se sucesso, 0 se falha
*/
int insere_elem_pos(Lista *a, int n, double valor){
    Lista b = (struct no*)malloc(sizeof(struct no));
    if (b==NULL|| n < 1){
        return 0;
    }
    b->info = valor;
    if (n == 1){            
        b->prox = (*a);
        if ((*a)!=NULL)     
            (*a)->ant = b;
        b->ant = NULL;
        (*a) = b;           
        return 1;
    }
    Lista aux = (*a);       
    int i = 2;              
    while(aux != NULL && i<n){
        aux=aux->prox;
        i++;
    }
    if (aux==NULL)      
        return 0;
    b->prox = aux->prox;    
    if (b->prox!=NULL){     
        b->prox->ant = b;
    }
    aux->prox = b;          
    b->ant = aux;
    return 1;
}

/*
remove elemento
entrada: endereço do endereço de uma lista um valor double
pré-condição: a lista nao estar vazia
processo: remove a primeira ocorrencia do elemento da lista
pós condição: um elemento é removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_elem(Lista *a,double valor){
    if (*a == NULL ) 
        return 0;
    Lista aux = *a;
    if ((*a)->info==valor){ 
        *a = aux->prox;
        (*a)->ant = NULL;
        free(aux);
        return 1;
    }
    while (aux!=NULL && aux->info != valor) 
        aux = aux->prox;                    
    if (aux == NULL)    
        return 0;
    aux->ant->prox = aux->prox;
    if (aux->prox!=NULL)
        aux->prox->ant = aux->ant;
    free(aux);
    return 1;
}

/*
remove todos
entrada: endereço do endereço de uma lista um valor double
pré-condição: a lista nao estar vazia
processo: remove todas as ocorrencias do elemento da lista
pós condição: todos os elementos iguais ao valor passado sao removidos da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_todos(Lista *a, double valor){
    if ((*a)==NULL)
        return 0;
    int flag = 0;
    Lista aux = (*a)->prox;
    Lista aux2 = aux;
    while (aux!=NULL){
        if (aux->info == valor){
            aux->ant->prox = aux->prox;
            if(aux->prox!=NULL)
                aux->prox->ant = aux->ant;
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
            flag = 1;
        }else
            aux = aux->prox;
    }
    if ((*a)->info==valor){
        aux = *a;
        (*a) = (*a)->prox;
        free(aux);
        flag = 1;
    }
    return flag;
}

/*
remove menor
entrada: endereço do endereço de uma lista e o endereço de um valor double
pré-condição: a lista nao estar vazia
processo: remove a primeira ocorrencia do menor elemento da lista e retorna seu valor por referencia
pós condição: o menor elemento é removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_menor(Lista *a, double *valor){
    if ((*a)==NULL) 
        return 0;
    if ((*a)->prox == NULL){    
        *valor = (*a)->info;
        free(*a);
        *a = NULL;
        return 1;
    }
    Lista aux = (*a)->prox;     
    Lista aux2 = aux;           
    while (aux!=NULL){
        if (aux->info < aux2->info) 
            aux2 = aux;
        aux = aux->prox;
    }

    if ((*a)->info<=aux2->info){    
        aux2 = (*a);
        (*a) = (*a)->prox;
        (*a)->ant = NULL;
        *valor = aux2->info;
        free(aux2);
        return 1;
    }
    aux2->ant->prox = aux2->prox;
    if (aux2->prox!=NULL)       
        aux2->prox->ant = aux2->ant;    
    *valor = aux2->info;
    free(aux2);
    return 1;

}

/*
get elemento posição
entrada: endereço da lista, posiçao do elemento e endereço de um double
pré-condição:a lista nao estar vazia e ser uma posiçao valida
processo: retorna o elemento na posição n por referencia
pós condição: nenhuma
saida: 1 se sucess0, 0 se falha
*/
int get_elem_pos(Lista a,int n, double *valor){
    if (a==NULL)
        return 0;
    int i;
    Lista aux = a;
    for (i=1;i<n;i++){
        if (aux->prox== NULL)
            break;
        aux = aux->prox;
    }
    if (aux==NULL)
        return 0;
    *valor = aux->info;
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
void get_tamanho_da_lista(Lista a,int *n){
    if (a==NULL){
        *n = 0;
    }else {
        int i=0;
        Lista aux = a;
        while (aux->prox!= NULL){
            aux = aux->prox;
            i++;
        }
        *n = i+1;
    }
}

/*
apaga lista
entrada: endereço do endereço de uma lista
pré-condição: a lista nao estar vazia
processo: apaga a lista, voltando ela para seu estado de vazia
pós condição: uma lista é apagada (ou limpada)
saida: 1 se sucesso, 0 se falha
*/
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

/*
Inverter
entrada: endereço de uma lista a e endereço do endereço de uma lista b
pré-condição: lista a nao estar vazia e lista b estar vazia
processo: copia a primeira lista na ordem inversa e armazena o resultado na segunda lista
pós condição: uma lista invertida e copiada em outra lista
saida: 1 se sucesso, 0 se falha
*/
int inverter(Lista a, Lista *b){
    if (a==NULL || (*b) != NULL)
        return 0;
    Lista aux1 = a;
    Lista aux2 = (Lista)malloc(sizeof(struct no));
    Lista aux3 = aux2;
    aux2->info = aux1->info;
    (*b) = aux2;
    aux2->prox = NULL;
    aux1 = aux1->prox;
    while (aux1!=NULL){
        aux2 = (Lista)malloc(sizeof(struct no));
        aux3->ant = aux2;
        aux2->prox = aux3;
        aux3 = aux2;
        aux2->info = aux1->info;
        aux1 = aux1->prox;
    }
    (*b) = aux3;
    return 1;
}
