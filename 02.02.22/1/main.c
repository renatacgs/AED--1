#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void imprimir_lista(Lista list) {
    int valor;
    printf("\nLista\n");
    int i = 0;
    while(obtem_valor_elem(list, i, &valor)) {
        if(i != 0) printf(" ");
        printf("[%c]", valor);
        i++;
    }
    printf("\n");
}

void inserindo(Lista *list, int *vet) {
    int i;
    for(i = 0; i < 11; i++) {
        if(!insere_elem(list, vet[i])) 
            break;
    }
}

void remove_lista(Lista *list, int elem) {
    if(remove_elem(list, elem)) 
        printf("\nElemento foi removido da lista!!\n");
    else
        printf("\nElemento nao existe!!\n");
}

int main() {
    
    Lista dplEnc;
    dplEnc = cria_lista();
    imprimir_lista(dplEnc);
    inserindo(&dplEnc, vet);
    imprimir_lista(dplEnc);
    remove_lista(&dplEnc, 8);
    imprimir_lista(dplEnc);
    return 0;
}

