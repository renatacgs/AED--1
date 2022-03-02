#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"
int main(void){
    int i,j;
    lista *l;
do{
    printf("\n[1]Criar lista\n[2]Inserir caracter\n[3]Remover caracter\n[4]Imprimir a posicao do caracter\n[5]Imprimir a lista\n[6]Liberar lista\n[7]Sair\n");
    scanf("%d",&i);
    switch (i){
        case (1):
            l = cria();
            printf("\nLista Criada\n");
        break;
        case (2):
            printf("\nQual o caracter a ser inserido:\n");
            scanf("%c",&j);
            ordena(l,j);
        break;

        case (3):
            printf("\nQual o caracter a ser removido:\n");
            scanf("%c",&j);
            rem(l,j);
        break;
        case (4):
            printf("\nQual o caracter a ser consultado:\n");
            scanf("%c",&j);
            pos(l,j);
        break;
        case (5):
            printf("\nLista impressa: \n");
            imprime(l);
        break;
        case (6):
            libera(l);
            l = cria();
        break;
        case (7):
            libera(l);
            return 0;
        break;
    }
} while (i>0 && i<8);
return 1;
}
