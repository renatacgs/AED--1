struct pass{
        unsigned int matricula;
        char nome[20];
        float media;
        int faltas;
};
struct caixa{
    struct caixa *no;
    struct pass p;
};
typedef struct caixa cad;
typedef struct caixa* lista;
lista *cria(void);
void libera (lista *li);
int insere(lista *li,unsigned int matricula,char nome[],float media, int faltas);
int rem(lista *li,unsigned int b);
int posicao(lista *li,unsigned int b);
int imprime(lista *li);

