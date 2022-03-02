#include <stdio.h>

int arranjo(int argc, int aux);
int fatorial(int aux);

int main(int argc, char const *argv[]){
    int aux;
    printf("Digite a quantidade de elementos:\n");
    scanf("%d",&argc);
    printf("Digite de quanto quer arranjar:\n");
    scanf("%d",&aux);
    aux = arranjo(argc,aux);
    printf("%d",aux);
    return 0;
}

int arranjo(int argc, int aux){
    double n,n1;
    n = fatorial(argc);
    n1 = fatorial((argc-aux));
    aux = n/n1;
    return aux;
}

int fatorial(int aux){
    if ((aux == 1) || (aux == 0)) return 1;
    else return aux * fatorial(aux-1);
}
