#ifndef FILAPRIORIDADE_H_INCLUDED
#define FILAPRIORIDADE_H_INCLUDED

struct paciente {
    char nome[51];
    int idade;
    float peso;
    float altura;
    char doenca;
    int gravidade;
};

typedef struct fila* Fila;

Fila cria_fila();
int fila_vazia(Fila F);
int insere_elem(Fila F, struct paciente a);
int remove_elem(Fila F, struct paciente* a);
int apaga_fila(Fila *F);
int esvazia_fila(Fila F);
int tamanho(Fila F, int *t);

#endif // FILAPRIORIDADE_H_INCLUDED

