#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include <string.h>
int entrada_carro(Fila f, int c){
    int validaL, validaN, i;
    Carro carro;
    time_t horario;
    time (&horario);
    Tempo = localtime (&horario);

    do{
        setbuf(stdin,NULL);
        validaL = 0;
        validaN = 0;
        i = 0;
        printf("\nDigite a placa do carro (A placa eh composta por 4 letras do alfabeto e 3 numeros de 0 a 9): ");
        scanf("%s", carro.placa);
        while(carro.placa[i] != '\0'){
            if(carro.placa[i] >= 'A' && carro.placa[i] <= 'Z'){
                validaL++;

            }
            else if(carro.placa[i] >= '0' && carro.placa[i] <= '9'){
                    validaN++;
            }
            i++;
        }
        if( validaL !=4 || validaN != 3 ){
            printf("\nA placa inserida eh invalida! (Uma placa possui 7 algarismos, sendo 4 letras do alfabeto e 3 numeros de 0 a 9)\n");

        }

    }while(validaL != 4 || validaN != 3 );

    do {
        setbuf(stdin,NULL);
        printf("\nDigite o tipo de servico (A para Avulso ou M para Mensalista): ");
        scanf("%c", &carro.servico);
        fflush(stdin);
        if(carro.servico != 'A' && carro.servico != 'M'){
            printf("Servico invalido, digite A ou M\n");
        }

    } while(carro.servico != 'A' && carro.servico != 'M');
    fflush(stdin);
    carro.hora = Tempo->tm_hour;
    carro.minuto = Tempo->tm_min;
    setbuf(stdin,NULL);

    insere_fim(f, carro);

    printf("Carro inserido com sucesso!\n");
    setbuf(stdin,NULL);
    return 1;

}

int saida_carro (Fila f, Carro carro){
    Carro veiculo;
    Fila aux = cria_fila();
    int verifica;
    while (1){
        if (remove_fila(f, &veiculo) == 0)
            break;
        if (strcmp(veiculo.placa, carro.placa) == 0){
            if(veiculo.servico == 'A'){
                int valor = 0;
                time_t horario, hora,minuto;
                time (&horario);
                Tempo = localtime (&horario);
                hora = Tempo->tm_hour;
                minuto = Tempo->tm_min;

                printf("\nAgradecemos a preferencia, estamos cobrando R$7,00 pela primeira hora e R$1,00 por hora adicional, com 10 minutos de tolerancia\n");
                printf("\nSeu carro de placa %s chegou em nosso estabelecimento as: %d:%d\n", veiculo.placa, veiculo.hora, veiculo.minuto);
                printf("\nE foi removido as: %d:%d \n", hora, minuto);

                int calc1 = hora - veiculo.hora;
                int calc2 = minuto - veiculo.minuto;
                if(calc2 > 10 && calc1 == 1){
                    valor = 7;
                    printf("O valor a ser pago sera de: R$%d,00\n", valor);
                    break;
                } else if(calc2 > 10 && calc1 >= 2 ){
                        valor = 7 + (calc1 * 1);
                        printf("O valor a ser pago sera de: R$%d,00\n", valor);
                        break;
                    } else printf("Voce saiu durante a tolerancia de 10 minutos\n");
                        break;


            } else {
                time_t horario, hora,minuto;
                time (&horario);
                Tempo = localtime (&horario);
                hora = Tempo->tm_hour;
                minuto = Tempo->tm_min;

                printf("\nSeu carro de placa %s chegou em nosso estabelecimento as: %d:%d\n", veiculo.placa, veiculo.hora, veiculo.minuto);
                printf("\nE foi removido as: %d:%d \n", hora, minuto);
            }

        printf("\nO carro foi retirado com sucesso!\n");
        verifica = 1;
        } else{
            insere_fim(aux, veiculo);
        }
    } while (fila_vazia(aux) == 0){
        remove_fila(aux, &veiculo);
        insere_fim(f, veiculo);
    }
    apaga_fila(&aux);
    if(verifica == 1)
        return 1;
    else
    return 0;
}

void imprimir_fila(Fila f, int cont){
    Fila aux = cria_fila();
       printf("\nBox %d:\n", cont);
    if(fila_vazia(f) == 1){
        printf("\nVazio\n");
    }
    else{
        while(fila_vazia(f) == 0)
        {
            Carro carro;
            remove_fila(f,&carro);
            printf("%s\n", carro.placa);
            insere_fim(aux,carro);
        }
        while(fila_vazia(aux) == 0)
        {
            Carro veiculo;
            remove_fila(aux,&veiculo);
            insere_fim(f,veiculo);
        }
        apaga_fila(&aux);
    }
}


int main(){
  Fila box1, box2,box3; //os 3 boxes do estacionamento
  Carro carro;
  int c1 = 0, c2 = 0, c3 = 0; //c1,c2,c3 servem para marcar qual boxe estara mais vazio
  int opcao = 0;

  box1 = cria_fila();
  box2 = cria_fila();
  box3 = cria_fila();

    do {
            printf("Escolha uma das opcoes abaixo: \n");
            printf("[1] Entrada de veiculo.\n");
            printf("[2] Saida de veiculos. \n");
            printf("[3] Visualizacao dos box. \n");
            printf("[4] Quantidade elementos. \n");
            printf("[5] Finalizar sistema. \n");
            printf("Digite a opcao: ");
            scanf("%d", &opcao);
            setbuf(stdin, NULL);
            if(opcao < 1 || opcao > 5){
                printf("Opcao invalida\n");
            }

            switch (opcao){
                case 1: {
                    if(c1 <= c2 && c1 <= c3 && c1<6){
                        if(entrada_carro(box1, c1) == -1){
                            printf("Erro na alocacao do box!\n");
                        }
                        else
                            printf("Veiculo foi colocado no Box nro 1\n\n");
                            c1++;
                        break;
                    }else
                    if(c2 <= c1 && c2 <= c3 && c2<6){
                        if(entrada_carro(box2, c2) == -1)
                            printf("Erro na alocacao do box!\n");
                        else
                             printf("Veiculo foi colocado no Box nro 2\n\n");
                            c2++;
                        break;

                    } else if (c3 < 6){
                        if(entrada_carro(box3, c3) == -1)
                            printf("Erro na alocacao do box!\n");
                        else
                             printf("Veiculo foi colocado no Box nro 3\n\n");
                            c3++;
                        break;
                    } else
                    setbuf(stdin,NULL);
                    printf("Estacionamento esta lotado, volte mais tarde! \n\n");
                    break;
                }
                case 2: {
                    int marcador = 0;
                    printf("Digite a placa do carro que deseja retirar: ");
                    gets(carro.placa);
                    fflush(stdin);
                    if(saida_carro(box1, carro) != 0){
                        c1=c1-1;
                        break;
                    } else{
                        marcador++;
                    }
                    if(saida_carro(box2, carro) != 0){
                        c2=c2-1;
                        break;
                    } else{
                        marcador++;
                      }
                    if(saida_carro(box3, carro) != 0){
                        c3=c3-1;
                        break;
                    } else {
                        marcador++;
                    }

                    if (marcador ==  3) {
                        setbuf(stdin,NULL);
                        printf("O carro nao foi encontrado no nosso estacionamento\n");
                        break;
                    }
                }

                case 3: {
                    int cont = 1;
                    printf("\nDisposicao dos veiculos no estacionamento:\n\n");
                    imprimir_fila(box1, cont);
                    cont = 2;
                    imprimir_fila(box2, cont);
                    cont = 3;
                    imprimir_fila(box3, cont);
                    break;
                }

                case 4: {
                    int valor, tamanho;
                    do{
                    printf("Digite o box que deseja saber a quantidade de elementos: ");
                    scanf("%d", &valor);
                        if(valor == 1){
                            tamanho = tamanho_fila(box1);
                            printf("O box1 possui %d carros\n\n", tamanho);
                            break;
                        } else
                        if(valor == 2){
                            tamanho = tamanho_fila(box2);
                            printf("O box2 possui %d carros\n\n", tamanho);
                            break;
                        } else
                        if(valor == 3){
                            tamanho = tamanho_fila(box3);
                            printf("O box3 possui %d carros\n\n", tamanho);
                            break;
                        } else{
                            printf("Escolha entre os boxs 1, 2 ou 3\n");
                        }
                    }while (valor < 1 || valor > 3);

                }
            }

    }while (opcao != 5);
    apaga_fila(&box1);
    apaga_fila(&box2);
    apaga_fila(&box3);
    printf("\n O sistema esta sendo encerrado! Ate logo..\n");
    return 0;
}
