#include <stdlib.h>
#include "Lista.h"

struct no{
    int info;
    struct no* prox;
};

/*
Cria lista
entrada: nenhuma
pr�-condi��o: nenhuma
processo: nenhum
p�s condi��o: nenhum
saida: NULL
*/
Lista cria_lista(){
    return NULL;
}

/*
lista_vazia
entrada: endere�o de uma lista
pr�-condi��o: nenhuma
processo: verifica se a lista est� vazia
p�s condi��o: nenhuma
saida: 1 se a lista est� vazia, 0 caso contrario
*/
int lista_vazia(Lista a){
    if (a!=NULL)
        return 0;
    return 1;
}

/*
insere elemento
entrada: endere�o do endere�o de uma lista e um valor int
pr�-condi��o: ter espa�o na memoria para alocar um novo no
processo: insere o elemento no come�o da lista
p�s condi��o: um novo elemneto � inserido na lista
saida: 1 se sucesso, 0 se falha
*/
int insere_elem(Lista *a, int valor){
    Lista b = (struct no*)malloc(sizeof(struct no));
    if (b==NULL)
        return 0;
    b->info = valor;
    if (*a==NULL){  
        *a = b;
        b->prox=NULL;
        return 1;
    }
    b->prox = (*a); 
    *a = b;         
    return 1;
}

/*
remove elemento
entrada: endere�o do endere�o de uma lista um valor int
pr�-condi��o: a lista nao estar vazia
processo: remove a primeira ocorrencia do elemento da lista
p�s condi��o: um elemento � removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_elem(Lista *a, int valor){
    if (*a == NULL ) 
        return 0;
    Lista aux = *a;
    if ((*a)->info==valor){ 
        *a = aux->prox;
        free(aux);
        return 1;
    }
    while (aux->prox!=NULL && aux->prox->info != valor) 
        aux = aux->prox;
    if (aux->prox == NULL)
        return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux->prox->prox;
    free(aux2);
    return 1;
}

/*
remove maior
entrada: endere�o do endere�o de uma lista e o endere�o de um valor int
pr�-condi��o: a lista nao estar vazia
processo: remove a ultima ocorrencia do maior elemento da lista e retorna seu valor por referencia
p�s condi��o: o menor elemento � removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_maior(Lista *a,int *valor){
    if (*a == NULL ) //se a Lista esta vazia FALHA
        return 0;
    if ((*a)->prox==NULL){  
        Lista aux = *a;
        *valor = aux->info;
        free(aux);
        *a = NULL;
        return 1;
    }
    Lista aux = *a;     
    Lista maior = aux;  
    while(aux->prox!=NULL){
        if (maior->prox->info <= aux->prox->info) 
            maior = aux;
        aux = aux->prox;
    }
    if ((*a)->info > maior->prox->info){    
        maior = (*a);
        *a = (*a)->prox;
    }else {
        aux = maior;
        maior=maior->prox;
        aux->prox = aux->prox->prox;
    }
    *valor = maior->info;
    free(maior);
    return 1;
}

/*
get elemento posi��o
entrada: endere�o da lista, posi�ao do elemento e endere�o de um int
pr�-condi��o:a lista nao estar vazia e ser uma posi�ao valida
processo: retorna o elemento na posi��o n por referencia
p�s condi��o: nenhuma
saida: 1 se sucess0, 0 se falha
*/
int get_elem_pos(Lista a,int n, int *valor){
    int i;
    Lista aux = a;
    for (i=1;i<n;i++){
        if (aux->prox== NULL)
            break;
        aux = aux->prox;
    }
    if (aux==NULL)
        return 0;
    *valor = aux->info;
    return 1;
}

/*
get_tamanho_da_lista
entrada: endere�o de uma lista, endere�o de uma variavel int
pr�-condi��o: nenhuma
processo: retorna o tamanho da lista por referencia
p�s condi��o: nenhuma
saida: nenhuma
*/
void get_tamanho_da_lista(Lista a,int *n){
    if (a==NULL){
        *n = 0;
    }else {
        int i=0;
        Lista aux = a;
        while (aux->prox!= NULL){
            aux = aux->prox;
            i++;
        }
        *n = i+1;
    }
}

/*
limpa lista
entrada: endere�o do endere�o de uma lista
pr�-condi��o: a lista nao estar vazia
processo: limpa a lista, voltando ela para seu estado de vazia
p�s condi��o: uma lista � limpada
saida: 1 se sucesso, 0 se falha
*/
int limpa_lista(Lista *a){
    if (*a == NULL)
        return 0;
    Lista aux = *a , aux2 = (*a)->prox;
    while (aux2!= NULL){
        free(aux);
        aux = aux2;
        aux2 = aux2->prox;
    }
    *a = NULL;
    return 1;
}

/*
Inverter lista
entrada: endere�o de uma lista 'a' e endere�o do endere�o de uma lista 'b'
pr�-condi��o: lista 'a' nao estar vazia e lista 'b' estar vazia
processo: copia a primeira lista na ordem inversa e armazena o resultado na segunda lista
p�s condi��o: uma lista invertida e copiada em outra lista
saida: 1 se sucesso, 0 se falha
*/
int inverter_lista(Lista a,Lista *b){
    if (a==NULL||(*b)!=NULL)    
        return 0;
    Lista aux = a->prox;
    Lista aux2 = (struct no*)malloc(sizeof(struct no));

    (*b)=aux2;
    aux2->info = a->info;
    aux2->prox = NULL;
    while (aux!=NULL){
        aux2 = (struct no*)malloc(sizeof(struct no));
        aux2->prox = (*b);
        aux2->info = aux->info;
        (*b) = aux2;
        aux = aux->prox;
    }
    return 1;
}

/*
intercalar listas
entrada: endere�o de uma lista 'a', endere�o de uma lista 'b', endere�o do endere�o de uma lista 'c'
pr�-condi��o: listas 'a' e 'b' nao estarem vazias e lista 'c' estar vazia
processo: copia e intercala a primeira com a segunda lista, armazenado a lista resultante na terceira lista
p�s condi��o: duas listas sao intercaladas e copiadas em outra lista
saida: 1 se sucesso, 0 se falha
*/
int intercalar_listas(Lista a, Lista b, Lista *c){
    if ((*c)!=NULL || (a==NULL&&b==NULL))
        return 0;
    Lista aux3 = (struct no*)malloc(sizeof(struct no)); 
    *c = aux3;                  
    if (a==NULL){
        aux3->info = b->info;
        b=b->prox;
        while(b!=NULL){
            aux3->prox = (struct no*)malloc(sizeof(struct no));  
            aux3 = aux3->prox;
            aux3->info = b->info;
            b=b->prox;
        }
        aux3->prox = NULL;
        return 1;
    }
    aux3->info = a->info;
    a=a->prox;
    while(a!=NULL||b!=NULL){
        if (b!=NULL){
            aux3->prox = (struct no*)malloc(sizeof(struct no));   
            aux3=aux3->prox;                              
            aux3->info = b->info;                        
            b = b->prox;      
        }
        if (a!=NULL){
            aux3->prox = (struct no*)malloc(sizeof(struct no));   
            aux3 = aux3->prox;                              
            aux3->info = a->info;                        
            a = a->prox;                              
        }

    }
    aux3->prox = NULL;
    return 1;
}
