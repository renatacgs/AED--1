#define MAX 100
union tipo_dado{
    float num;
    char info;
};


typedef union tipo_dado Tipo_dado;
typedef struct pilha *Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha pi);
int push (Pilha* pi, Tipo_dado elem);
int pop (Pilha* pi, Tipo_dado* elem);
int le_topo (Pilha pi,Tipo_dado* elem);
