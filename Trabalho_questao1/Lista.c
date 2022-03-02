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
pr�-condi��o: nenhuma
processo: aloca memoria para uma nova lista
p�s condi��o: uma nova lista � criada
saida: endere�o da lista criada
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
entrada: endere�o de uma lista
pr�-condi��o: nenhuma
processo: verifica se a lista est� vazia
p�s condi��o: nenhuma
saida: 1 se a lista est� vazia, 0 caso contrario
*/
int lista_vazia(Lista lst){
    if (lst->Fim == 0)
        return 1;
    else
        return 0;
}

/*
lista_cheia
entrada: endere�o de uma lista
pr�-condi��o: nenhuma
processo: verifica se a lista esta cheia
p�s condi��o: nenhuma
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
entrada: endere�o de uma lista e um elemento char
pr�-condi��o: ser um endere�o valido e a lista nao estar cheia
processo: insere o elemento na posi��o correspondente (ordem crescente)
p�s condi��o: um novo elemneto � inserido na lista
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
entrada: endere�o de uma lista e um elemento char
pr�-condi��o: ser um endere�o valido e a lista nao estar vazia
processo: remove o elemento da lista
p�s condi��o: um elemento � removido da lista
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
remove posi��o
entrada: endere�o de uma lista, uma posi��o n e um endere�o de uma variavel char
pr�-condi��o: ser um endere�o valido e uma posi��o valida
processo: remove o elemento na posi��o n e retorna seu valor por referencia
p�s condi��o: um elemento � removido da lista
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
entrada: endere�o de uma lista
pr�-condi��o: ser um endere�o valido e a lista nao estar vazia
processo: remove todas as vogais da lista
p�s condi��o: a lista fica sem vogais
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
get elemento posi��o
entrada: endere�o da lista, posi�ao do elemento e endere�o de uma variavel char
pr�-condi��o: ser um endere�o de lista valido e n ser uma posi�ao valida
processo: retorna o elemento na posi��o n por referencia
p�s condi��o: nenhuma
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
entrada: endere�o de uma lista, endere�o de uma variavel int
pr�-condi��o: ser um endere�o de lista valido
processo: retorna o tamanho da lista por referencia
p�s condi��o: nenhuma
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
entrada: endere�o do endere�o de uma lista
pr�-condi��o: ser um endere�o valido
processo: apaga a lista, liberando espa�o na memoria
p�s condi��o: uma lista � apagada
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
entrada: endere�o de uma lista
pr�-condi��o: ser um endere�o valido
processo: limpa a lista, retornando ela para o estado de vazia
p�s condi��o: a lista � limpada
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
entrada: endere�o de 3 listas
pr�-condi��o: os 3 endere�os serem validos
processo: intercala os elementos da primeira lista com a segunda e guarda o resultado na terceira lista
p�s condi��o: uma terceira lista � preenchida com a intercala�ao das duas primeiras
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
