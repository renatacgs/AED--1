#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED


typedef struct fila* Fila;

Fila cria_fila();
int fila_vazia(Fila F);
int fila_cheia(Fila F);
int insere_elem_fim(Fila F, char a[]);
int insere_elem_ini(Fila F, char a[]);
int remove_elem_fim(Fila F, char a[]);
int remove_elem_ini(Fila F,char a[]);
int apaga_fila(Fila *F);
int esvazia_fila(Fila F);
int tamanho(Fila F, int *t);


#endif // DEQUE_H_INCLUDED
