#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alunos{
    char nome[50];
    double media;
    int n_faltas;
};

    void selectionSort (struct alunos *a, int qtd){
        int menor, i, j, troca;
        double troca_media;
        char troca_nome[50];
        for(i=0;i<qtd-1;i++){
            menor=i;
        for(j=i+1; j<qtd;j++){
            if(a[j].media < a[menor].media)
                menor = j;
                }
            if(i!=menor){
                troca_media = a[i].media;
                a[i].media= a[menor].media;
                a[menor].media = troca_media;

                troca = a[i].n_faltas;
                a[i].n_faltas = a[menor].n_faltas;
                a[menor].n_faltas = troca;

                strcpy(troca_nome, a[i].nome);
                strcpy(a[i].nome, a[menor].nome);
                strcpy(a[menor].nome, troca_nome);
    }
        }

    }

int main() {
    int qtd, i;
    printf("Digite a quantidade de alunos:\n");
        scanf("%d", &qtd);
    if(qtd<0){
        printf("Quantidade invalida, favor digitar novamente:\n");
        scanf("%d", &qtd);
    }

    struct alunos *a = (struct alunos*)malloc(qtd * sizeof(struct alunos));
    for(i=0;i<qtd;i++){
        printf("\nDigite o nome do aluno:\n");
            setbuf(stdin,NULL);
            gets(a[i].nome);
        printf("\nDigite a media do aluno:\n");
            scanf("%lf", &a[i].media);
        if(a[i].media < 0 ){
            printf("\nNumero invalido, digite novamente:\n");
            scanf("%lf", &a[i].media);
        }

        printf("\nDigite a quantidade de faltas do aluno:\n");
            scanf("%d", &a[i].n_faltas);

    }
        selectionSort(a, qtd);

    for(i = 0; i < qtd; i++){
        printf("Nome: %s\n", a[i].nome);
        printf("Media: %.2lf\n", a[i].media);
        printf("Numero de faltas: %d\n", a[i].n_faltas);
    }
    free(a);
    return 0;
}
