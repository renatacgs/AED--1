#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main()
{
    int num,elem,resto,result;
    int retorno;
    char op;
    Pilha p = cria_pilha();

    do{
        printf("\nDigite o numero que sera convertido: ");
        scanf("%d",&num);

        if(num < 0){
            printf("\nFim, numero incorreto\n");
            apaga_pilha(&p);
            break;
        }

        //obriga o usuario a entrar com uma opcao valida.
        do{
            printf("\nB para Binario\n");
            printf("O para Octal\n");
            printf("H para Hexadecimal\n");

            printf("Digite a conversao desejada: ");
			while ((op = getchar()) != '\n');

            scanf("%c",&op);

            if(op!='B' && op!='O' && op!='H' && op!='b' && op!='o' && op!='h')
                printf("\nOpcao invalida! \n");
            else
                break;

        }while(1);

        if(op == 'B' || op == 'b'){
            result = num;

            while(result != 0){
                resto = result % 2;
                result = result / 2;
                retorno = push(p,resto);

                if(!retorno)
                    break;
            }

            if(!retorno)
            {
                printf("\nErro! Numero com muitos digitos apos conversao! \n");
                continue;
            }

            printf("\nO numero convertido eh: ");
            while(pilha_vazia(p)!=1){
                pop(p,&elem);//quando a pilha for vazia, n�o entra no la�o
                printf("%d", elem);

            }
        }

        if(op == 'O' || op == 'o'){
            result = num;

            while(result != 0){
                resto = result%8;
                result = result/8;
                push(p,resto);

                if(!retorno)
                    break;
            }

            if(!retorno)
            {
                printf("\nErro! Numero com muitos digitos apos conversao!\n");
                continue;
            }

            printf("\nO numero convertido eh: ");
            while(pilha_vazia(p)!=1){
                verifica_topo(p,&elem);
                printf("%d",elem);
                pop(p,&elem); //quando a pilha for vazia, n�o entra no la�o
            }
        }

        if(op == 'H' || op == 'h'){
            result = num;

            while(result != 0){
                resto = result % 16;
                result = result / 16;
                push(p,resto);

                if(!retorno)
                    break;
            }

            if(!retorno)
            {
                printf("\nErro! Numero com muitos digitos apos conversao!\n");
                continue;
            }

            printf("\nO numero convertido eh: ");
            while(pilha_vazia(p)!=1){
                verifica_topo(p,&elem);

                if(elem>=0 && elem<=9)
                    printf(" %d ", elem);
                if(elem == 10)
                    printf(" A ");
                if(elem == 11)
                    printf(" B ");
                if(elem == 12)
                    printf(" C ");
                if(elem == 13)
                    printf(" D ");
                if(elem == 14)
                    printf(" E ");
                if(elem == 15)
                    printf(" F ");

                pop(p,&elem); //quando a pilha for vazia, nao entra no laco
            }
        }

    }while(1);
    return 0;
}
