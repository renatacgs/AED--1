#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct cad {
    char nome[20], matricula[20], cargo[20];
    int idade;
    float salario;
};

void consulta(struct cad *c){
    int i;
    char nome_pesquisado[20];
    while (strcmp(nome_pesquisado, "FIM")){
        printf("Digite o nome a ser pesquisado:\n");
                printf("\n");
        setbuf(stdin, NULL);
        gets(nome_pesquisado);
       for (i=0; i<10; i++){
            if (strcmp(nome_pesquisado,c[i].nome) == 0){
                printf("O %s tem idade de %d anos, matricula %s e cargo %s com salario de: %.2f\n", c[i].nome, c[i].idade, c[i].matricula, c[i].cargo, c[i].salario);
                        printf("\n");
                break;
            }
        }
    }
}

void cadastra(struct cad *c){
    int i;
    for (i=0; i<10; i++){
        printf("Digite um nome:\n");
        setbuf(stdin, NULL);
        gets(c[i].nome);
        printf("\n");
        printf("Digite o matricula do funcionario: \n");
        setbuf(stdin, NULL);
        gets(c[i].matricula);
        if (strcmp(c[i].matricula, "ZERO")==0){
            break;
        }
        if (strcmp(c[i].matricula, "0")==0){
            break;
        }
        if (strcmp(c[i].matricula, "zero")==0){
            break;
        }
        printf("\n");
        printf("Digite o idade:\n");
        scanf("%d", &c[i].idade);
                printf("\n");
        printf("Digite o salario:\n");
        scanf("%f", &c[i].salario);
                printf("\n");
        printf("Digite o cargo do funcionario:\n");
        setbuf(stdin, NULL);
        gets(c[i].cargo);
        printf("\n");
    }

}
int main(int argc, char *argv[]){
    struct cad c[10];
    cadastra(c);
    consulta(c);
    return 0;
}




