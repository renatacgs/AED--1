#include <stdlib.h>
#include "Lista.h"

#define MAX 20

struct lista{
    char no[MAX];
    int Fim;
};

/*
Cria lista
entrada: nenhuma
pré-condição: nenhuma
processo: aloca memoria para uma nova lista
pós condição: uma nova lista é criada
saida: endereço da lista criada
*/
Lista cria_lista(){
    Lista lst;
    lst = (Lista)malloc(sizeof(struct lista));
    if (lst != NULL)
        lst->Fim = 0;
    return lst;
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
    if (lst->Fim == 0)
        return 1;
    else
        return 0;
}

/*
lista_cheia
entrada: endereço de uma lista
pré-condição: nenhuma
processo: verifica se a lista esta cheia
pós condição: nenhuma
saida: 1 se a lista esta cheia, 0 caso contrario
*/
int lista_cheia(Lista lst){
    if (lst->Fim == MAX)
        return 1;
    else
        return 0;
}

/*
insere ordenado
entrada: endereço de uma lista e um elemento char
pré-condição: ser um endereço valido e a lista nao estar cheia
processo: insere o elemento na posição correspondente (ordem crescente)
pós condição: um novo elemneto é inserido na lista
saida: 1 se sucesso, 0 se falha
*/
int insere_ord(Lista lst, char x){
    if (lista_cheia(lst)==1||lst==NULL)
        return 0;
    if (lista_vazia(lst)==1||x>=lst->no[lst->Fim-1]){
        lst->no[lst->Fim] = x;
    }else{
        int i,aux = 0;
        while (x>=lst->no[aux])
            aux++;
        for(i=lst->Fim; i>aux; i--)
            lst->no[i]=lst->no[i-1];
        lst->no[aux] = x;
    }
    lst->Fim++;
    return 1;
}

/*
remove ordenado
entrada: endereço de uma lista e um elemento char
pré-condição: ser um endereço valido e a lista nao estar vazia
processo: remove o elemento da lista
pós condição: um elemento é removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_ord(Lista lst, char x){
    if (lst == NULL
        ||lista_vazia(lst)==1
        ||x<lst->no[0]
        ||x>lst->no[lst->Fim-1])
        return 0;
    int i,aux = 0;
    while (aux<lst->Fim && lst->no[aux]<x){
        aux++;
    }
    if (aux==lst->Fim||lst->no[aux]>x)
        return 0;
    for(i=aux+1;i<lst->Fim;i++)
        lst->no[i-1]=lst->no[i];
    lst->Fim--;
    return 1;
}

/*
remove posição
entrada: endereço de uma lista, uma posição n e um endereço de uma variavel char
pré-condição: ser um endereço valido e uma posição valida
processo: remove o elemento na posição n e retorna seu valor por referencia
pós condição: um elemento é removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_pos(Lista a,int n,char *c){
    if (a==NULL || n>a->Fim)
        return 0;
    *c = a->no[n-1];
    int i;
    for(i=n-1;i<a->Fim-1;i++)
        a->no[i] = a->no[i+1];
    a->Fim--;
    return 1;

}

/*
remove vogais
entrada: endereço de uma lista
pré-condição: ser um endereço valido e a lista nao estar vazia
processo: remove todas as vogais da lista
pós condição: a lista fica sem vogais
saida: 1 se sucesso, 0 se falha
*/
int remove_vogais(Lista a){
    if(a==NULL||lista_vazia(a))
        return 0;
    int i,j=0;      
    for(i=0;i<a->Fim-j;i++){   
        for(;(a->no[i+j]=='a'
            ||a->no[i+j]=='e'
            ||a->no[i+j]=='i'
            ||a->no[i+j]=='o'
            ||a->no[i+j]=='u'
            ||a->no[i+j]=='A'
            ||a->no[i+j]=='E'
            ||a->no[i+j]=='I'
            ||a->no[i+j]=='O'
            ||a->no[i+j]=='U')&&j<a->Fim-i;){
            j++;        
        }
        a->no[i] = a->no[i+j];  
    }                           
    a->Fim =  a->Fim - j;      
    return 1;
}

/*
get elemento posição
entrada: endereço da lista, posiçao do elemento e endereço de uma variavel char
pré-condição: ser um endereço de lista valido e n ser uma posiçao valida
processo: retorna o elemento na posição n por referencia
pós condição: nenhuma
saida: 1 se sucess0, 0 se falha
*/
int get_elem_pos(Lista a, int n, char *x){
    if (a==NULL||n>a->Fim||n<=0)
        return 0;
    *x = a->no[n-1];
    return 1;
}

/*
get_tamanho_da_lista
entrada: endereço de uma lista, endereço de uma variavel int
pré-condição: ser um endereço de lista valido
processo: retorna o tamanho da lista por referencia
pós condição: nenhuma
saida: 1 se sucesso, 0 se falha
*/
int get_tamanho_da_lista(Lista a, int *n){
    if (a==NULL)
        return 0;
    *n = a->Fim;
    return 1;
}

/*
apaga lista
entrada: endereço do endereço de uma lista
pré-condição: ser um endereço valido
processo: apaga a lista, liberando espaço na memoria
pós condição: uma lista é apagada
saida: 1 se sucesso, 0 se falha
*/
int apaga_lista(Lista *a){
    if(*a == NULL)
        return 0;
    free(*a);
    *a = NULL;
    return 1;
}

/*
limpa lista
entrada: endereço de uma lista
pré-condição: ser um endereço valido
processo: limpa a lista, retornando ela para o estado de vazia
pós condição: a lista é limpada
saida: 1 se sucesso, 0 se falha
*/
int limpa_lista(Lista a){
    if (a==NULL)
        return 0;
    a->Fim = 0;
    return 1;
}

/*
intercala_lista
entrada: endereço de 3 listas
pré-condição: os 3 endereços serem validos
processo: intercala os elementos da primeira lista com a segunda e guarda o resultado na terceira lista
pós condição: uma terceira lista é preenchida com a intercalaçao das duas primeiras
saida: 1 se sucesso, 0 se falha
*/
int intercala_lista(Lista a,Lista b, Lista c){
    if (a==NULL||b==NULL||c==NULL)
        return 0;
    int i=0,j=0;    
    while(i<a->Fim&&j<b->Fim){     
        if (a->no[i]<=b->no[j]){    
            c->no[c->Fim] = a->no[i];
            c->Fim++;
            i++;
            if (c->Fim == MAX)
                return 1;
        }else{
            c->no[c->Fim] = b->no[j];   
            c->Fim++;                   
            j++;
            if (c->Fim == MAX)
                return 1;
        }
    }
    if(i==a->Fim){      
        for(;j<b->Fim;j++){
            c->no[i+j] = b->no[j];
            c->Fim++;
            if (c->Fim == MAX)
                return 1;
        }
    }else{              
        for(;i<a->Fim;i++){
            c->no[i+j] = a->no[i];
            c->Fim++;
            if (c->Fim == MAX)
                return 1;
        }
    }
    return 1;
}
