#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include <string.h>
#define max 5

struct fila {
 Carro carros[max]; //pode ter 5 carros por fila;
 int ini, cont;   // ini = inicio da fila, cont = contar os elementos
};

Fila cria_fila(){
    Fila f;
    f = (Fila) malloc (sizeof (struct fila)); //alocacao de memoria
    if (f != NULL){
        f->ini = 0;
        f->cont = 0;
    }
    return f;

}

int fila_vazia (Fila f){
    if (f == NULL || f->cont != 0)
        return 0; //erro
    else
        return 1;

}

int fila_cheia (Fila f){
    if (f == NULL || f->cont != max)
        return 0; //erro
    else
        return 1;
}

int insere_fim (Fila f, Carro elem){
    if (f == NULL || fila_cheia(f) == 1){
        return 0;
    }
    f->carros[(f->ini+f->cont)%max] = elem;
    f->cont++;
    return 1;

}

int remove_fila (Fila f, Carro *elem){
    if (f == NULL || fila_vazia(f) == 1)
        return 0;
    *elem= f->carros[f->ini];
    f->ini = (f->ini+1)%max;
    f->cont--;
    return 1;
}

int apaga_fila(Fila *f){
    if (*f == NULL)
        return 0;
    free (*f);
    f = NULL;
    return 1;
}

int tamanho_fila (Fila f){
    if (f == NULL)
        return 0;
    else
        return f->cont;
}

int esvazia_fila(Fila p){
    if (p == NULL)
        return 0;
    p->cont = 0;
    return 1;
}
