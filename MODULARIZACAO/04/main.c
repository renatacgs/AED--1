#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void cadastro(int n_alunos, char nome_arquivo[]){
    int i, matricula;
	FILE *arquivo;
	char nome_aluno[50];
	float notafinal;
	nome_arquivo = strcat(nome_arquivo, ".txt");
	arquivo = fopen(nome_arquivo, "w");
	for(i=0; i<n_alunos; i++){
		printf("\nDigite o nome do aluno:\n");
		setbuf(stdin,NULL);
		gets(nome_aluno);
		fprintf(arquivo, "Aluno: %s \n", nome_aluno);
		printf("\nDigite o numero de matricula:\n");
		scanf("%d", &matricula);
		fprintf(arquivo, "Matricula: %d\n", matricula);
		printf("\nDigite a nota final(entre 0 e 100):\n");
		scanf("%f", &notafinal);
        fprintf(arquivo, "Nota final: %d\n", notafinal);

		if(notafinal<0 || notafinal>100){
            printf("Nota invalida, favor digitar novamente !\n");
		}
		fprintf(arquivo, "\nNota final: %.2f\n", notafinal);
	}
	fclose(arquivo);

}

int main(int argc, char *argv[]){
	int n_alunos;
	char nome_arquivo[70];
	printf("Digite o numero de alunos:\n");
	scanf("%d", &n_alunos);
	printf("\nDigite o nome do arquivo:\n");
	setbuf(stdin,NULL);
	gets(nome_arquivo);
	cadastro(n_alunos, nome_arquivo);
	return 0;
}
