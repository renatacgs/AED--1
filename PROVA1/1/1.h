typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista a);
int insere_car(Lista *a, char elem);
int remove_ultimavogal(Lista *a, char elem);
int apaga_lista(Lista *a);