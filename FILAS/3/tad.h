struct bebida{
    char descricao[10];
    int codigo;
    float preco;
};

typedef struct fila lista;
lista * cria_fila(void);
void libera_fila(lista*fi);
void clear(void);
int tamanho_fila(lista*fi);
int fila_vazia(lista *fi);
int insere_fila(lista *fi, struct bebida b);
int remove_fila(lista *fi);
int consulta_fila(lista *fi, struct bebida *b);
void imprime(lista *fi);
