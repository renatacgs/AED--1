#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "01.h"

int main(void){
    int x,i;
    Pilha* pi;
    do{
    printf("\n[1]Criar Pilha\n[2]Inserir elementos\n[3]Imprimir a Pilha\n[4]Liberar pilha\n[5]Sair\n");
    scanf("%d",&i);
    clear();
    switch (i){
        case (1):
            pi  = cria_pilha();
            printf("\nPilha criada com sucesso!\n");
        break;

        case (2):
            clear();
            printf("\nQual o caracter que deseja inserir? ");
            setbuf(stdin,NULL);
            scanf("%c",&x);
            push(pi,x);
            clear();
        break;

        case (3):
            pop(pi);
            clear();
        break;

        case (4):
            imprime(pi);
        break;

        case (5):
            libera_pilha(pi);
            pi = cria_pilha();
            clear();
        break;

        case (6):
            libera_pilha(pi);
            clear();
            return 0;
        break;
    }
} while (i>0 && i<6);
return 1;
}
