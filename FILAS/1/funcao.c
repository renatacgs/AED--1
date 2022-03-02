#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad.h"

#define MAX 20

struct fila{
    int ini,qnt, fim;
    struct aluno alunos[MAX];
};

Fila * cria_fila(void){
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if (fi != NULL)
    {
        fi->ini = 0;
        fi->qnt = 0;
        fi->fim = 0;
    }
    return fi;
}

void libera_fila(Fila *fi){
    free(fi);
}

int tamanho_fila(Fila *fi){
    if (fi == NULL) return -1;
    return fi->qnt;
}

int fila_cheia(Fila *fi){
    if (fi == NULL) return -1;
    if (fi->qnt == MAX) return 1;
    else return 0;
}

int fila_vazia(Fila *fi){
    if (fi == NULL) return -1;
    if (fi->qnt == MAX) return 1;
    else return 0;
}

int insere_fila(Fila *fi,struct aluno *a){
    if (fi == NULL) return 0;
    if (fila_cheia(fi)) return 0;
    fi->alunos[fi->fim] = *a;
    fi->fim = (fi->fim+1)%MAX;
    fi->qnt++;
    return 1;
}

int remove_fila(Fila *fi){
    if (fi == NULL || fila_vazia(fi)) return 0;
    fi->ini = (fi->ini+1)%MAX;
    fi->qnt--;
    return 1;
}

int consulta_fila(Fila *fi,struct aluno *a){
    if (fi == NULL || fila_vazia(fi)) return 0;
    *a = fi->alunos[fi->ini];
    return 1;
}

void imprime(Fila *fi){
    if (fi == NULL || fila_vazia(fi)) printf("\nNada a imprimir.");
    for (int i = 0; i < fi->qnt; i++)
    {
        printf("\nMatricula: %i \nNome: %s \nNota: %f \nSituacao: %i ",fi->alunos[i].matricula,fi->alunos[i].nome,fi->alunos[i].notas,fi->alunos[i].situacao);
    }
}
