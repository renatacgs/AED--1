typedef struct no * Lista;


struct produto{

    int codigo;
    char nome[10];
    double preco;

};

int lista_vazia(Lista lst);
int remove_menor(Lista *lst, struct produto *p);
int insere_produto(Lista *lst, struct produto elem);