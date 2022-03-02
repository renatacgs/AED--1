#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int Escolha(){
    int choice;
    printf("[1]Criar uma lista\n");
    printf("[2]Adicionar um elemento no inicio da lista\n");
    printf("[3]Adicionar um elemento no final da  lista\n");
    printf("[4]Remover um elemento no inicio da lista\n");
    printf("[5]Remover um elemento no final da lista\n");
    printf("[6]Imprimir todos os elementos da lista\n");
    printf("[7]Remover todos os pares\n");
    printf("[8]Inserir na posicao\n");
    printf("[9]Limpar lista\n");
    printf("[0]Sair\n");
    printf("Escolha a opcao: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

int main()
{
    int valor, choice = 0, posicao, retorno;
    int n,i, flag = 0;
    Lista lst;

    do{
        choice = Escolha();
        switch(choice){
            case 1:
                if (flag == 0){
                     lst = cria_lista();
                     flag = 1;
                     printf("Lista criada com sucesso! \n");
                     break;
                }
                printf("Ja existe uma lista, nao pode criar outra! \n");
                break;
            case 2:
                setbuf(stdin,NULL);
                printf("Digite o valor a ser inserido no inicio da lista: ");
                scanf("%d", &valor);
                insere_inicio(&lst, valor);
                setbuf(stdin,NULL);
                printf("\n");
                break;
            case 3:
                setbuf(stdin,NULL);
                printf("Digite o valor a ser inserido no final da lista: ");
                scanf("%d", &valor);
                insere_final(&lst, valor);
                setbuf(stdin,NULL);
                printf("\n");
                break;

            case 4:
                if (lista_vazia(lst) == 1){
                    printf("A lista esta vazia");
                    break;
                }
                else{
                    remove_inicio(&lst, &valor);
                    printf("O valor: %d foi removido do inicio da lista", valor);
                    printf("\n");
                }
                break;
            case 5:
                if (lista_vazia(lst) == 1){
                    printf("A lista esta vazia");
                    break;
                }
                else{
                    remove_final(&lst, &valor);
                    printf("O valor: %d foi removido do final da lista", valor);
                    printf("\n");
                }
                break;
           case 6:
                if(lista_vazia(lst)==1 || lst == NULL){
                    printf("A lista nao possui elementos\n");
                    break;
                }
                get_tamanho_da_lista(lst,&n);
                printf("%d elementos\n", n);
                for(i=0;i<n;i++){
                    get_elem_pos(lst,i+1,&valor);
                    printf("%d \n",valor);
                }
                printf("}\n");
                break;

            case 7:
                if (lista_vazia(lst) == 1){
                    printf("A lista nao possui elementos");
                    break;
                }
                remove_pares(&lst);
                break;

            case 8:
                setbuf(stdin,NULL);
                printf("Digite a posicao: ");
                scanf ("%d", &posicao);
                printf("Digite o valor: ");
                scanf("%d", &valor);
                retorno = insere_pos(&lst, posicao, valor);

                if (retorno == 0){
                    printf("A insercao nao foi realizada!! \n");
                    printf("\n");
                    break;
                } else
                    printf("Insercao realizada com sucesso!! \n");
                setbuf(stdin,NULL);
                    printf("\n");
                break;

            case 9:
                   esvazia_lista(&lst);
                   if(lista_vazia(lst) == 1){
                    printf("Lista esvaziada com sucesso! \n");
                   }
                   break;

            case 10:
                    get_tamanho_da_lista(lst, &n);
                    printf("%d\n", n);

        }
    }while(choice!=0);
    return 0;
}
