#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

struct pilha{
    int no[max];
    int topo;
};

/*
cria_pilha
----------
Entrada: nenhuma
Processo: aloca uma strutura do tipo 'struct pilha'
Saida: Endereco para um tipo 'struct pilha', em sucesso, NULL, em fracasso.
*/
Pilha cria_pilha(){
    Pilha p;
    p = (Pilha) malloc(sizeof(struct pilha)); 

    if(p!=NULL) 
        p->topo = -1;
    return p;
}

/*
pilha_vazia
-------------
Entrada: Tipo pilha
Processo: verifica se a pilha esta vazia
Saida: 1, se vazio, 0, se nao vazio.
*/
int pilha_vazia(Pilha p){
    if(p->topo == -1) 
        return 1;
    else
        return 0;
}

/*
pilha_cheia
-------------
Entrada: Tipo pilha
Processo: verifica se a pilha esta cheia
Saida: 1, se cheia, 0, se nao cheia.
*/
int pilha_cheia(Pilha p){
    if(p->topo == max-1) 
        return 1;
    else
        return 0;
}

/*
push
-------------
Entrada: Tipo pilha, inteiro
Processo: insere o inteiro passado no topo da pilha
Saida: 1, em sucesso, 0, em fracasso
*/
int push(Pilha p, int elem){
    if(p == NULL  || pilha_cheia(p) ) 
        return 0;

    p->topo ++; 
    p->no[p->topo] = elem;

    return 1;
}

/*
pop
-------------
Entrada: Tipo pilha, endereco para inteiro
Processo: remove o elemento no topo da pilha e o atribui a variavel cujo endereco foi passado
Saida: 1, em sucesso, 0, em fracasso
*/
int pop(Pilha p, int *elem){
    if(p == NULL  || pilha_vazia(p)) 
        return 0;

    *elem = p->no[p->topo]; 
    p->topo--; 

    return 1;
}

/*
verifica_topo
-------------
Entrada: Tipo pilha, endereco para inteiro
Processo: atribui a variavel cujo endereco foi passado o vaor do elemento no topo da pilha.
Saida: 1, em sucesso, 0, em fracasso
*/
int verifica_topo(Pilha p, int *elem){
    if(p == NULL  || pilha_vazia(p)) 
        return 0;

    *elem = p->no[p->topo]; 

    return 1;
}

/*
esvazia_pilha
-------------
Entrada: Tipo pilha
Processo: retorna a pilha ao estado vazio
Saida: 1, em sucesso, 0, em fracasso
*/
int esvazia_pilha(Pilha p){
    if(p == NULL || pilha_vazia(p))
        return 0;

    p->topo = -1;

    return 1;
}

int apaga_pilha(Pilha *p){
    if(p == NULL)
        return 0;

    free(*p);
}
