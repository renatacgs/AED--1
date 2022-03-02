typedef struct casas lista;
lista *cria(void);
void libera (lista *li);
int tamanho(lista *li);
int cheia(lista *li);
int vazia(lista *li);
int insere(lista *li, char n[]);
int rem(lista *li, char n[]);
int pos(lista *li, char n[]);
int imprime(lista *li);

