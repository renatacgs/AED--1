typedef struct ponto Ponto;

struct ponto *cria_pto(double x, double y, double z);
void libera_pto(struct ponto **p);
double distancia_pto(struct ponto *p1, struct ponto *p2);
