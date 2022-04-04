#include <stdio.h>
#include "FilaPrioridade.h"

int main()
{
    struct paciente a;
    Fila F,F1;
    int menu, flag=0,i,t;
    do{
        printf("-------MENU--------\n");
        printf("[1]Criar uma Fila\n");
        printf("[2]Inserir um Paciente\n");
        printf("[3]Remover um Paciente\n");
        printf("[4]Imprimir Fila de Prioridade\n");
        printf("[5]Esvaziar a Fila\n");
        printf("[6]Apagar a Fila\n");
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
                printf("Ja existe uma Fila\n");
                break;
            }
            F = cria_fila();
            if (F!=NULL){
                printf("Fila criada com sucesso\n");
                flag = 1;
            }else
                printf("Falha ao criar a Fila");
            break;
        case 2:
            printf("Nome do Paciente: ");
            scanf("%[^\n]s",a.nome);
            setbuf(stdin,NULL);
            printf("Idade do Paciente: ");
            scanf("%d",&(a.idade));
            setbuf(stdin,NULL);
            printf("Peso do Paciente: ");
            scanf("%f",&(a.peso));
            setbuf(stdin,NULL);
            printf("Altura do Paciente: ");
            scanf("%f",&(a.altura));
            setbuf(stdin,NULL);
            printf("Doenca do Paciente(C, N, S ou R): ");
            scanf("%c",&(a.doenca));
            setbuf(stdin,NULL);
            printf("Gravidade da doenca do Paciente (1 - 5): ");
            scanf("%d",&(a.gravidade));
            setbuf(stdin,NULL);
            while(a.gravidade<1||a.gravidade>5){
                printf("O valor informado nao e valido, digite novamente: ");
                scanf("%d",&(a.gravidade));
                setbuf(stdin,NULL);
            }
            if (insere_elem(F,a))
                printf("Paciente inserido com sucesso\n");
            else
                printf("Falha ao inserir paciente\n");
            break;
        case 3:
            if (fila_vazia(F)){
                printf("A fila esta vazia\n");
                break;
            }
            if (remove_elem(F,&a)){
                printf("Nome: %s\nIdade: %d\nPeso: %.2f\nAltura: %.2f\nDoenca: %c\nGravidade da doenca: %d\nPaciente removido\n"
                       ,a.nome, a.idade, a.peso, a.altura, a.doenca, a.gravidade);
            }else
                printf("Falha ao remover o paciente\n");
            break;
        case 4:
            if (fila_vazia(F)){
                printf("A fila esta vazia\n");
                break;
            }
            F1 = cria_fila();
            tamanho(F, &t);
            printf("Lista com %d Pacientes\n",t);
            for (i=0;i<t;i++){
                remove_elem(F,&a);
                printf("Nome: %s\nIdade: %d\nPeso: %.2f\nAltura: %.2f\nDoenca: %c\nGravidade da doenca: %d\n\n"
                       ,a.nome, a.idade, a.peso, a.altura, a.doenca, a.gravidade);
                insere_elem(F1,a);
            }
            for(i=0;i<t;i++){
                remove_elem(F1,&a);
                insere_elem(F,a);
            }
            apaga_fila(&F1);
            break;
        case 5:
            if (fila_vazia(F)){
                printf("A fila esta vazia\n");
                break;
            }
            if (esvazia_fila(F)){
                printf("Fila esvaziada com sucesso\n");
            }else
                printf("Falha ao esvaziar a Fila\n");
            break;
        case 6:
            if (apaga_fila(&F)){
                printf("Fila apagada com sucesso\n");
                flag = 0;
            }else
                printf("Falha ao apagar a Fila\n");
            break;
        }
    }while (menu!=0);
    return 0;
}
