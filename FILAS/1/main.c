#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"

int main(void){
    char dados[10];
    Fila *fi;
    int x,opcao;
    do{
    printf("\n[1]Criar Fila\n[2]Inserir elemento\n[3]Remover primeiro elemento\n[4]Imprimir a Fila\n[5]Liberar fila\n[6]Tamanho da fila\n[7]Sair\n");
    scanf("%d",&opcao);
    switch (opcao){
        case (1):
            fi  = cria_fila();
            printf("\nLista criada com sucesso. \n");
        break;

        case (2):
            printf("\nDigite as informacoes a serem inseridas: \n");
            setbuf(stdin,NULL);
            gets(dados);
            insere_fila(fi,dados);
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

        case(6):
            tamanho_fila(fi);
        break;

        case (7):
            libera_fila(fi);
            return 0;
        break;
    }
} while (opcao>0 && opcao<7);
return 1;
}
