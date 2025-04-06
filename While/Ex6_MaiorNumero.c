#include <stdio.h>

int main() {
    int size, i = 0, j = 0, num, maior = 0;

    printf("Digite quantos numeros irá digitar: ");
    scanf("%d", &size);
    int listaNum[size];

    while(i < size){
        printf("Digite um numero: ");
        scanf("%d", &num);
        listaNum[i] = num;
        i++;
    }

    while(j < size){
        if(maior < listaNum[j]){
            maior = listaNum[j];
        }
        j++;
    }

    printf("Maior: %d", maior);

    return 0;
}
