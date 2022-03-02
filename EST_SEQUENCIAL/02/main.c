#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"

int main(void){
    int i,v;
    float p;
    lista *l;
    char n[50];
do{
    printf("\n[1]Criar lista\n[2]Inserir elementos\n[3]Remover elementos\n[4]Imprimir as informacoes do nome\n[5]Imprimir a lista\n[6]Liberar lista\n[7]Sair\n");
    scanf("%d",&i);
    switch (i){
        case (1):
            l = cria();
            printf("\n");
            printf("Lista Criada");
        break;

        case (2):
            printf("\nDigite o nome da bebida:\n");
            setbuf(stdin,NULL);
            gets(n);
            setbuf(stdin,NULL);
            printf("\nDigite o volume da bebida:\n");
            scanf("%i",&v);
            printf("\nDigite o preco da bebida:\n");
            scanf("%f",&p);
            insere(l,n,v,p);
        break;

        case (3):
            printf("\nQual o nome deseja remover?\n");
            setbuf(stdin,NULL);
            gets(n);
            setbuf(stdin,NULL);
            rem(l,n);
        break;

        case (4):
            printf("\nQual o nome que sera feita a consulta?\n");
            setbuf(stdin,NULL);
            gets(n);
            setbuf(stdin,NULL);
            pos(l,n);
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
