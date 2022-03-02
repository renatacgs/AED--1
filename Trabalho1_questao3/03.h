typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista lst, float elem);
int remov(Lista lst, float elem);
int obtem_elem(Lista lst, int pos, float *valor);
int remov_pos(Lista lst, int pos, float *valor);
int tamanho(Lista lst);
int iguais(Lista lst, Lista lst2);
void esvaziar(Lista lst);
Lista intercala(Lista lst, Lista lst2);
