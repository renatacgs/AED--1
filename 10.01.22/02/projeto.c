#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "02.h"

struct ponto{
  double x, y, z;
};

struct ponto* cria_pto(double x, double y, double z) {
  struct ponto *ponto = NULL;
  ponto = (struct ponto*) malloc(sizeof(struct ponto));
  if(ponto != NULL) {
    ponto->x = x;
    ponto->y = y;
    ponto->z = z;
  }
  return ponto;
}

void libera_pto(struct ponto **p) {
  free(*p);
  *p = NULL;
}

double distancia_pto(struct ponto *p1, struct ponto *p2) {
  if(p1 == NULL || p2 == NULL) {
    return -1;
  }
  return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2));
}
