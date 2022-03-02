#include <stdio.h>
#include <stdlib.h>
#include "03.h"

void manipular_lista(Lista lst);
void tratamento_escolha(Lista lst, int escolha);

int main(){
    Lista lst = cria_lista();
    Lista lst2 = cria_lista();
    Lista lst3 = cria_lista();

    if(lst == NULL || lst2 == NULL || lst3 == NULL){
        printf("\nFalha ao criar listas!\n");
        return 1;
    }

    int escolha = 0;
    int retorno = 0;
    float valor = 0;
    int sair = 0;
    int i;

    while(1){
        printf("Escolha uma opcao.\n");
        printf("[1]Manipular lista 1.\n");
        printf("[2]Manipular lista 2.\n");
        printf("[3]Verificar listas\n");
        printf("[4]Intercalar listas.\n");
        printf("[5]Manipular lista 3.\n");
        printf("[6]Sair.\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                manipular_lista(lst);
                break;

            case 2:
                manipular_lista(lst2);
                break;

            case 3:
                retorno = iguais(lst,lst2);
                if(retorno == 1)
                    printf("\nListas iguais.\n\n");
                else
                    printf("\nListas diferentes.\n\n");
                break;
            case 4:
                lst3 = intercala(lst,lst2);
                if(lst3 == NULL){
                    printf("Erro.\n");
                    break;
                }

                printf("\nLista intercalada: ");
                if(lista_vazia(lst3))
                    printf("Lista vazia!\n\n");
                else{
                    for(i = 1; i<=tamanho(lst3); i++){
                        obtem_elem(lst3,i, &valor);
                        printf("%.2f ",valor);
                    }
                    printf("\n\n");
                }
                break;

            case 5:
                manipular_lista(lst3);
               break;

            case 6:
                sair = 1;
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
        if(sair == 1)
            break;
    }
}

void manipular_lista(Lista lst){
    int escolha = 0;

    while(1){
        printf("\nEscolha uma opcao:\n");
        printf("[1] Imprimir lista.\n");
        printf("[2] Inserir elemento na lista.\n");
        printf("[3] Remover elemento da lista.\n");
        printf("[4] Tamanho da lista.\n");
        printf("[5] Remover posicao da lista.\n");
        printf("[6] Voltar.\n");
        scanf("%d", &escolha);

        if(escolha == 6) break;

        tratamento_escolha(lst, escolha);
    }
}

void tratamento_escolha(Lista lst, int escolha){
    int i = 0;
    int retorno = 0;
    float valor = 0;
    int pos = 0;
    switch(escolha){
        case 1:
            if(lista_vazia(lst) == 1){
                printf("\nLista vazia.\n");
                break;
            }

            printf("\nLista: ");

            for(i = 1; i<=tamanho(lst); i++){
                obtem_elem(lst,i,&valor);
                printf("%.2f ",valor);
            }

            printf("\n\n");

            break;
        case 2:
            printf("Qual o elemento que deseja inserir: ");
            scanf("%f", &valor);
            retorno = insere_ord(lst, valor);

            if(retorno == 0)
                printf("Erro ao inserir.\n");
            else
                printf("Elemento inserido.\n");
            break;

        case 3:
            printf("Elemento que deseja remover: ");
            scanf("%f", &valor);
            retorno = remov(lst,valor);
            if(retorno==0){
                printf("Valor nao contido na lista");
            }
            break;

        case 4:
            printf("Lista de tamanho: %d\n", tamanho(lst));
            break;

        case 5:
            printf("Posicao que deseja remover: ");
            scanf("%d", &pos);
            retorno = remov_pos(lst,pos,&valor);
            if(retorno == 0) printf("Posicao invalida\n");
            else             printf("Valor removido: %.2f\n", valor);

            break;

        default:
            printf("Opcao invalida!\n");
    }
}
