#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 2

struct bebidas{
char nome[20];
int volume;
float preco;
};

void inserir(struct bebidas *b, int tam, int posicao){
    int i;
    if(posicao<=tam){
        printf("\n");
        printf("Digite o nome da bebida:\n");
        setbuf(stdin,NULL);
        gets(b[posicao].nome);
        printf("Digite o volume da bebida:\n");
        scanf("%d", &b[posicao].volume);
        printf("Digite o preco da bebida:\n");
        scanf("%f", &b[posicao].preco);
        printf("\n");
}else{
printf("Tabela de cadastro esta cheia !\n");
}
}

void apagar(struct bebidas *b){
    b = realloc(b, (TAM*sizeof(struct bebidas)-sizeof(struct bebidas)));
}

int main(){
    int i, opcao;
    int posicao=0;
    struct bebidas *b=NULL;
    b = (struct bebidas*) malloc(TAM*sizeof(struct bebidas));

do{
    printf("[1]Inserir bebida na tabela\n[2]Apagar ultimo registro da tabela\n[3]Imprimir tabela\n[4]Sair\n");
    scanf("%d", &opcao);
    if(opcao==1){
        inserir(b, TAM, posicao);
        posicao++;
        }
    if(opcao==2){
        apagar(b);
        posicao--;
        printf("Registro apagado !\n");
    }
    if(opcao==3){
        for(i = 0;i <posicao;i++){
                printf("\nNome: %s\n",b[i].nome);
                printf("Volume: %d(ml)\n",b[i].volume);
                printf("Preco: R$ %.2f\n",b[i].preco);
                printf("\n");
    }
    }
    if(opcao==4){
    break;
    }

}while(opcao>0 && opcao <5);

return 0;
}
