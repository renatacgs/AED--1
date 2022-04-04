#include <stdio.h>
#include "Deque.h"

int main()
{
    char a[21];
    Fila F,F1;
    int menu, flag=0,i,t;
    do{
        printf("-------MENU--------\n");
        printf("[1]Criar um Deque\n");
        printf("[2]Inserir um elemento no INICIO\n");
        printf("[3]Inserir um elemento no FINAL\n");
        printf("[4]Remover um elemento do INICIO\n");
        printf("[5]Remover um elemento do FINAL\n");
        printf("[6]Imprimir Deque\n");
        printf("[7]Esvaziar Deque\n");
        printf("[8]Apagar Deque\n");
        printf("[0]Sair\n");
        scanf("%d",&menu);
        setbuf(stdin,NULL);
        if (menu!=1&&menu!=0&&flag==0){
            printf("Antes de qualquer operacao, precisa criar a Fila\n");
            menu = -1;   //com esse valor, ele nao vai entrar em nenhum case no switch
        }
        switch (menu){
        case 1:
            if (flag == 1){
                printf("Ja existe uma Deque\n");
                break;
            }
            F = cria_fila();
            if (F!=NULL){
                printf("Deque criada com sucesso\n");
                flag = 1;
            }else
                printf("Falha ao criar a Deque");
            break;
        case 2:
            if (fila_cheia(F)){
                printf("O Deque está cheia\n");
                break;
            }
            printf("Digite a string: ");
            scanf("%[^\n]s",a);
            setbuf(stdin,NULL);
            if (insere_elem_ini(F,a))
                printf("String inserida com sucesso\n");
            else
                printf("Falha ao inserir String\n");
            break;
        case 3:
            if (fila_cheia(F)){
                printf("O deque esta cheio\n");
                break;
            }
            printf("Digite a string: ");
            scanf("%[^\n]s",a);
            setbuf(stdin,NULL);
            if (insere_elem_fim(F,a))
                printf("String inserido com sucesso\n");
            else
                printf("Falha ao inserir string\n");
            break;
        case 4:
            if (fila_vazia(F)){
                printf("A Deque esta vazia\n");
                break;
            }
            if (remove_elem_ini(F,a)){
                printf("String removida: %s\n",a);
            }else
                printf("Falha ao remover String\n");
            break;
        case 5:
            if (fila_vazia(F)){
                printf("A Deque esta vazia\n");
                break;
            }
            if (remove_elem_fim(F,a)){
                printf("String removida: %s\n",a);
            }else
                printf("Falha ao remover String\n");
            break;
        case 6:
            if (fila_vazia(F)){
                printf("A Deque esta vazia\n");
                break;
            }
            F1 = cria_fila();
            tamanho(F, &t);
            printf("Lista com %d strings\n",t);
            for (i=0;i<t;i++){
                remove_elem_ini(F,a);
                printf("%s\n",a);
                insere_elem_fim(F1,a);
            }
            for (i=0;i<t;i++){
                remove_elem_ini(F1,a);
                insere_elem_fim(F,a);
            }
            apaga_fila(&F1);
            break;
        case 7:
            if (fila_vazia(F)){
                printf("A Deque esta vazia\n");
                break;
            }
            if (esvazia_fila(F)){
                printf("Deque esvaziada com sucesso\n");
            }else
                printf("Falha ao esvaziar a Deque\n");
            break;
        case 8:
            if (apaga_fila(&F)){
                printf("Deque apagada com sucesso\n");
                flag = 0;
            }else
                printf("Falha ao apagar a Deque\n");
            break;
        }
    }while (menu!=0);
    return 0;
}
