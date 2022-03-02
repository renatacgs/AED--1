#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"

int main(void){
    int opcao;
    long int matricula;
    char nome[30];
    char setor;
    float salario;
    Pilha* pi;
    do{
    printf("\n[1]Criar Pilha\n[2]Inserir elementos\n[3]Tamanho da pilha\n[4]Imprimir a Pilha\n[5]Liberar pilha\n[6]Sair\n");
    scanf("%d",&opcao);
    switch (opcao){
        case (1):
            pi  = cria_pilha();
            printf("Pilha criada\n");
        break;

        case (2):
            printf("\nDigite o numero da matricula do funcionario:\n ");
            setbuf(stdin,NULL);
            scanf("%ld",&matricula);
            push(pi,matricula);
            printf("\nDigite o nome do funcionario:\n ");
            setbuf(stdin,NULL);
            scanf("%c",&nome);
            push(pi,nome);
            printf("\nSelecione o setor do funcionario: (F - fabrica, A - administrativo, C - comercial ou G � gerencia):\n");
            setbuf(stdin,NULL);
            scanf("%c",&setor);
            if(setor != 'F' || setor != 'A' || setor != 'C' || setor != 'G'){
                printf("\nSetor incorreto, favor digitar novamente.\n");
            }

            push(pi,setor);
            printf("\nDigite o salario do funcionario: \n");
            setbuf(stdin,NULL);
            scanf("%f",&salario);
            push(pi,salario);
        break;

        case (3):
            tamanho_pilha(pi);
        break;

        case (4):
            imprime(pi);
        break;

        case (5):
            libera_pilha(pi);
            pi = cria_pilha();
        break;

        case (6):
            libera_pilha(pi);
            return 0;
        break;
    }
} while (opcao>0 && opcao<7);
return 1;
}
