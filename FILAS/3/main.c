#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"

int main(void){
    struct bebida a;
    lista *fi;
    int i;
    do{
    printf("\n[1]Criar Fila\n[2]Inserir elementos\n[3]Remover primeiro elemento\n[4]Imprimir a Fila\n[5]Liberar fila\n[6]Sair\n");
    scanf("%d",&i);
    switch (i){
        case (1):
            fi  = cria_fila();
            printf("Lista criada com sucesso.\n");
        break;

        case (2):
            printf("Digite o codigo da bebida :\n");
            scanf("%d", &a.descricao)
            printf("Digite a descricao da bebida: \n");
            setbuf(stdin,NULL);
            scanf(a.volume);
            printf("Digite o preco da bebida: \n");
            scanf("%f",&a.preco);
            insere_fila(fi,a);
        break;

        case (3):
            remove_fila(fi);
        break;

        case (4):
            imprime(fi);
        break;

        case (5):
            libera_fila(fi);
            fi = cria_fila();
        break;

        case (6):
            libera_fila(fi);
            return 0;
        break;
    }
} while (i>0 && i<7);
return 1;
}
