struct tm * Tempo; //Tempo eh um ponteiro para a struct do time.h

struct carro {
    char placa [8];
    char servico;
    time_t hora;
    time_t minuto;

};
typedef struct carro Carro;
typedef struct fila *Fila; // Fila é um ponteiro para a struct fila

Fila cria_fila();
int fila_vazia (Fila f);
int fila_cheia (Fila f);
int insere_fim (Fila f, Carro elem);
int remove_fila (Fila f, Carro *elem);
int apaga_fila(Fila *f);
int tamanho_fila (Fila f);
int esvazia_fila(Fila f);
