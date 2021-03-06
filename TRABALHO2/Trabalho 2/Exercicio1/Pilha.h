typedef struct pilha *Pilha;

#define max 20

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int push(Pilha p, int elem);
int pop(Pilha p, int *elem);
int verifica_topo(Pilha p, int *elem);
int esvazia_pilha(Pilha p);
int apaga_pilha (Pilha *p);
