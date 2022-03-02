#include <stdio.h>
#include <stdlib.h>
#include "01.h"

struct num {
    double real, imag;
};

complex* cria_nro(double real, double imag) {
    complex *z;
    z = (complex*) malloc(sizeof(complex));
    if(z != NULL) {
        z->real = real;
        z->imag = imag;
    }
    return z;
}

void libera_nro(complex* *z) {
    free(*z);
    *z = NULL;
}

complex* soma(complex *a, complex *b) {
    if(a == NULL || b == NULL){
        return NULL;
    }
    return cria_nro(a->real + b->real, a->imag + b->imag);
}

complex* sub(complex *a, complex *b) {
    if(a == NULL || b == NULL){
        return NULL;
    }
    return cria_nro(a->real - b->real, a->imag - b->imag);
}

complex* mult(complex *a, complex *b) {
    if(a == NULL || b == NULL){
        return NULL;
    }
    double real = (a->real * b->real) - (a->imag * b->imag);
    double imag = (a->real * b->imag) + (a->imag * b->real);
    return cria_nro(real, imag);
}

int get_complex(complex *a, double *real, double *imag) {
    if(a == NULL) {
        return 0;
    }
    *real = a->real;
    *imag = a->imag;
    return 1;
}
