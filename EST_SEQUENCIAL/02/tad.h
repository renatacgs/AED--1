typedef struct casas lista;
lista *cria(void);
void libera (lista *li);
int insere(lista *li, char n[],int v,float p);
int rem(lista *li, char n[]);
int pos(lista *li, char n[]);
int imprime(lista *li);


