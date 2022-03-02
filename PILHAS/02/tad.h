#define MAX 20

struct numero {
    int x;
    long int matricula;
    char nome[30], setor;
    float salario;
  };

typedef struct pilha Pilha;
Pilha * cria_pilha(void);
void libera_pilha(Pilha*pi);
int tamanho_pilha(Pilha*pi);
int pilha_cheia(Pilha *pi);
int pilha_vazia(Pilha *pi);
int push(Pilha *pi, int x);
int pop(Pilha *pi);
int consulta_pilha(Pilha *pi, int x);
void imprime(Pilha *pi);

