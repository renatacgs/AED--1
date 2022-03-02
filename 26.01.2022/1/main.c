#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"
int main(void){
    int i;
    lista *l;

unsigned int matricula;
    char nome[20];
    float media;
    int faltas;
do{
    printf("\n[1]Criar lista\n[2]Inserir elemento\n[3]Remover elemento\n[4]Imprimir a posicao do nome\n[5]Imprimir a lista\n[6]Liberar lista\n[7]Sair\n");
    scanf("%d",&i);
    switch (i){
        case (1):
            l = cria();
            printf("\nLista Criada");
        break;
        case (2):
            printf("\nDigite o nome a ser inserido:\n");
            setbuf(stdin,NULL);
            gets(nome);
            setbuf(stdin,NULL);
            printf("\nDigite a matricula:\n");
            scanf("%u",&matricula);
            printf("\nDigite a media:\n");
            scanf("%f",&media);
            printf("\nDigite a quantidade de faltas:\n");
            scanf("%d",&faltas);
            insere(l,matricula,nome,media,faltas);
 break;

        case (3):
            printf("\nDigite a matricula a ser apagada:\n");
            scanf("%u",&matricula);
            rem(l,matricula);
        break;

        case (4):
            printf("\nDigite a matricula a ser consultada:\n");
            scanf("%u",&matricula);
            printf("%d\n",posicao(l,matricula));
        break;

        case (5):
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
