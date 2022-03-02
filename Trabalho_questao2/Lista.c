#include <stdlib.h>
#include "Lista.h"
#include <string.h>

#define MAX 10
#define tamanhoMAX 16

struct lista{
    char no[MAX][tamanhoMAX];
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
insere elemento
entrada: endere�o de uma lista e uma string (vetor de caracteres)
pr�-condi��o: ser um endere�o valido e a lista nao estar cheia
processo: insere o elemento no final da lista
p�s condi��o: um novo elemneto � inserido na lista
saida: 1 se sucesso, 0 se falha
*/
int insere_elem(Lista lst, char x[]){
    if (lista_cheia(lst)==1||lst==NULL||strlen(x)>=tamanhoMAX)
        return 0;
    strcpy(lst->no[lst->Fim],x);
    lst->Fim++;
    return 1;
}

/*
remove elemento
entrada: endere�o de uma lista e uma string (vetor de caracteres)
pr�-condi��o: ser um endere�o valido e a lista nao estar vazia
processo: remove o elemento da lista
p�s condi��o: um elemento � removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_elem(Lista lst, char x[]){
    if (lst == NULL || lista_vazia(lst)==1)

        return 0;
    int i,aux = 0;
    while (aux<lst->Fim && strcmp(lst->no[aux],x)!=0){  
        aux++;
    }
    if (aux==lst->Fim)  
        return 0;
    for(i=aux+1;i<lst->Fim;i++) 
        strcpy(lst->no[i-1],lst->no[i]);
    lst->Fim--;
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
get elemento posi��o
entrada: endere�o da lista, posi�ao do elemento e endere�o de uma String (vetor de caracteres)
pr�-condi��o: ser um endere�o de lista valido e n ser uma posi�ao valida
processo: retorna o elemento na posi��o n por referencia
p�s condi��o: nenhuma
saida: 1 se sucess0, 0 se falha
*/
int get_elem_pos(Lista a, int n, char x[]){
    if (a==NULL||n>a->Fim||n<=0)
        return 0;
    strcpy(x,a->no[n-1]);
    return 1;
}

/*
remove posi��o
entrada: endere�o de uma lista, uma posi��o n e um endere�o de uma string (vetor de caracteres)
pr�-condi��o: ser um endere�o valido e uma posi��o valida
processo: remove o elemento na posi��o n e retorna seu valor por referencia
p�s condi��o: um elemento � removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_pos(Lista a,int n,char c[]){
    if (a==NULL || n>a->Fim || lista_vazia(a))
        return 0;
    strcpy(c,a->no[n-1]);   
    int i;
    for(i=n-1;i<a->Fim-1;i++)    
        strcpy(a->no[i],a->no[i+1]);
    a->Fim--;
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
insere_pos
entrada: endere�o de uma lista, posi�ao n e uma string (vetor de caracteres)
pr�-condi��o: se um endere�o de lista valido e uma posi�ao valida
processo: insere a string na posi�ao n da lista
p�s condi��o: um novo elemento � inserido na lista
saida: 1 se sucesso, 0 se falha
*/
int insere_pos(Lista a, int n, char x[]){
    if (a==NULL || n > MAX)
        return 0;
    if (n > a->Fim) 
        strcpy(a->no[a->Fim],x);
    int i;
    for (i=a->Fim;i>n;i--)  
        strcpy(a->no[i],a->no[i-1]);
    strcpy(a->no[n],x);     
    a->Fim++;
    return 1;
}

/*
remove menor
entrada: endere�o de uma lista, endere�o de uma string
pr�-condi��o: ser um endere�o de lista valido e a lista nao estar vazia
processo: remove o menor elemento da lista e retorna seu valor por referencia
p�s condi��o: um elemento � removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_menor(Lista a,char x[]){
    if (a==NULL || lista_vazia(a))
        return 0;
    int i, aux=0;
    for(i=0;i<a->Fim;i++)   
        if (strcmp(a->no[i],a->no[aux])<0)
            aux = i;    
    return remove_pos(a,aux+1,x);   
}

/*
contatenar
entrada: endere�o de 3 listas
pr�-condi��o: os 3 endere�os serem validos
processo: concatena a segunda lista no final da primeira e armazena o resultado em uma terceira lista
p�s condi��o: uma terceira lista � criada com a concatena�ao das duas primeiras
saida: 1 se sucesso, 0 se falha
*/
int concatenar(Lista a, Lista b, Lista c){
    if(a==NULL || b==NULL || c==NULL)
        return 0;
    int i;
    while (i<a->Fim&&i<b->Fim){ 
        strcpy(c->no[i],a->no[i]);  
        strcat(c->no[i],b->no[i]);  
        if (strlen(a->no[i])+strlen(b->no[i])>=tamanhoMAX){ 
            c->no[i][tamanhoMAX-1] = '\0';
        }
        i++;
    }
    if (a->Fim<b->Fim){ 
        for(;i<b->Fim;i++)
            strcpy(c->no[i],b->no[i]);
    }else {             
        for(;i<a->Fim;i++)
            strcpy(c->no[i],a->no[i]);
    }
    c->Fim = i;
    return 1;
}
