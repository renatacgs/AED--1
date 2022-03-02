struct char{
    int ch;
};
struct caixa{
    struct caixa *no;
    struct char cha;
};
typedef struct caixa cad;
typedef struct caixa* lista;
lista *cria(void);
void libera (lista *li);
void ordena(lista *li,void l);
void rem(lista *li,void b);
void pos(lista *li,void l);
void imprime(lista *li);

