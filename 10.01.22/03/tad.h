struct esfera{
    float x, y, z, x1, y1, z1, raio, area, volume;
};

typedef struct esfera cria;

struct complexo{
    cria A[20];
    int quantidade;
};

typedef struct complexo *com;

com cria_esfera(void);
void insere_numero(com l,cria* aux);
void libera_esfera(com l,int i);
void raio(com l);
void area(com l);
void volume(com l);
