#include <stdlib.h>
#include <stdio.h>
#include "tad.h"

int main(void){
    int i,j;
    lista *l;
do{
    printf("\n[1]Criar lista\n[2]Inserir elemento\n[3]Remover elemento\n[4]Imprimir a lista\n[5]Liberar lista\n[6]Sair\n");
    scanf("%d",&i);
    switch (i){
        case (1):
            l = cria();
            printf("Lista criada\n");
        break;

        case (2):
            printf("\nQual o numero que deseja inserir? ");
            scanf("%d",&j);
            ord(l,j);
        break;

        case (3):
            printf("\nQual o numero que deseja apagar? ");
            scanf("%d",&j);
            rem(l,j);
        break;

        case (4):
            printf("Lista impressa:\n");
            imprime(l);
        break;

        case (5):
            libera(l);
            l = cria();
        break;

        case (6):
            libera(l);
            return 0;
        break;
    }
} while (i>0 && i<7);
return 1;
}
