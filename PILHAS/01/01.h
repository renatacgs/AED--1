#define MAX 20

struct caracteres {
    char x;
};

typedef struct pilha Pilha;
Pilha * cria_pilha(void);
void libera_pilha(Pilha*pi);
void clear(void);
int tamanho_pilha(Pilha*pi);
int pilha_cheia(Pilha *pi);
int pilha_vazia(Pilha *pi);
int push(Pilha *pi, char x);
int pop(Pilha *pi);
int consulta_pilha(Pilha *pi, char x);
void imprime(Pilha *pi);