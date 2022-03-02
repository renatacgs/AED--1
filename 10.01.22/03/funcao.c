#include <stdlib.h>
#include <math.h>
#include "tad.h"

#define PI 3.14
com cria_esfera(void){
    com l = (com) malloc(sizeof(struct complexo));
    if(l==NULL) return NULL;
    else{
        l->quantidade = 0;
        return l;
    };
}

void insere_numero(com l,cria* aux){
    l->A[l->quantidade] = *aux;
    raio(l);
    area(l);
    volume(l);
    l->quantidade++;
}

void libera_numero(com l,int i){
    if (i == 1) free(l);
    else if (i == 2) l->quantidade--;
}

void raio(com l){
    double P,E,T,O,U;
    P = (l->A[l->quantidade].x - l->A[l->quantidade].x1) * (l->A[l->quantidade].x - l->A[l->quantidade].x1);
    E = (l->A[l->quantidade].y - l->A[l->quantidade].y1) * (l->A[l->quantidade].y - l->A[l->quantidade].y1);
    T = (l->A[l->quantidade].z - l->A[l->quantidade].z1) * (l->A[l->quantidade].z - l->A[l->quantidade].z);
    O = sqrt( P + E + T);
    l->A[l->quantidade].raio = O;
}
void area(com l){
    l->A[l->quantidade].area = 4 * PI * (l->A[l->quantidade].raio)*(l->A[l->quantidade].raio);
}
void volume(com l){
    l->A[l->quantidade].volume = (4*PI*(pow(l->A[l->quantidade].raio,3)))/3;
}
