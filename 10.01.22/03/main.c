#include "tad.h"
#include <stdio.h>

int main(void){
    int opc,i;
    com l = cria_esfera();
    cria aux;
    do
    {
        printf("\nEscolha uma opcao:\n1 - Insere coordenada \n2 - Imprimir todas\n3 - Eliminar a ultima esfera \n4 - Sair\n");
        scanf("%d",&opc);
        switch (opc)
        {
            case(1):
                printf("\nDigite a coordenada X: ");
                scanf("%f",&aux.x);
                printf("\nDigite a coordenada Y: ");
                scanf("%f",&aux.y);
                printf("\nDigite a coordenada Z: ");
                scanf("%f",&aux.z);
                printf("\nDigite a outra coordenada X: ");
                scanf("%f",&aux.x1);
                printf("\nDigite a outra coordenada Y: ");
                scanf("%f",&aux.y1);
                printf("\nDigite a outra coordenada Z: ");
                scanf("%f",&aux.z1);
                insere_numero(l,&aux);
            break;

            case(2):
                for(i = 0; i < l->quantidade; i++) printf("\n_______________ \nPonto 1 (%2.f, %2.f, %2.f) \nPonto 2 (%2.f, %2.f, %2.f) \nRaio: %2.f \nArea: %2.f \nVolume: %2.f", l->A[i].x, l->A[i].y, l->A[i].z, l->A[i].x1, l->A[i].y1, l->A[i].z1, l->A[i].raio, l->A[i].area, l->A[i].volume);
            break;

            case(3):
                libera_numero(l,2);
            break;

            case (4):
                libera_numero(l,1);
                return 0;
            break;

            default:
                printf("Essa opcao nao eh valida.\n");
            break;
        }
    } while (1);
    return 1;
}
