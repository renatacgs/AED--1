#include<stdio.h>
#include<stdlib.h>

void posicao(int v[], int n){
    int i, j, aux;
    for(i=0;i<n;i++){
        printf("Digite um numero:\n");
        scanf("%d", &v[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        if(v[i]<v[j]){
            aux=v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
}
printf("Vetor ordenado:\n");
for(i=0;i<n;i++){
    printf("%d\n", v[i]);
}
}

int main(int argc, char *argv[]){
    int n;
    printf("Digite a capacidade de numeros do vetor(menos de 30):\n");
    scanf("%d", &n);
    if(n>30 || n<0){
        printf("Capacidade acima do limite!\n");
        system("exit");
    }else{
        int v[n];
        posicao(v,n);

    }
}


