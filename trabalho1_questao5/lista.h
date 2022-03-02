typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_final(Lista *lst, int elem);
int insere_inicio (Lista *lst, int elem);
int remove_inicio (Lista *lst, int *elem);
int remove_pares (Lista *lst);
int esvazia_lista(Lista *lst);
int insere_pos(Lista *lst, int index, int elem);
void get_tamanho_da_lista(Lista lst,int *n);
int get_elem_pos(Lista lst,int n, int *valor);
