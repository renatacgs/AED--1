struct numero{
    int nu;
};

typedef struct caixa cad;
typedef struct caixa* lista;
lista *cria(void);
void libera (lista *li);
int ord(lista *li,int l);
int rem(lista *li,int b);
int imprime(lista *li);
