typedef struct lista* Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int apaga_lista(Lista *a);
int intercala(Lista a,Lista b, Lista c);