#include <stdio.h>
#include "02.h"

int main(){
    Ponto *point1, *point2;
    double x, y, z;
    printf("Digite as coordenadas do primeiro ponto:\n");
    printf("Digite x, y e z: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    point1 = cria_pto(x, y, z);
    printf("\nDigite as coordenadas do segundo ponto: \n");
    printf("Digite x, y e z: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    point2 = cria_pto(x, y, z);
    printf("\nA distancia entre esses dois pontos eh: %.3lf", distancia_pto(point1, point2));
    libera_pto(&point1);
    libera_pto(&point2);
    return 0;
}
