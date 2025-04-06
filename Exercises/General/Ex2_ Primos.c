#include <stdio.h>
#include <math.h>

int main() {
    int num, i, quantidadePrimos = 0, numeroTeste = 2, soma = 0;

    printf("Digite quantos numeros primos deseja: ");
    scanf("%d", &num);

    while (quantidadePrimos < num) {
        int primo = 1;

        for (i = 2; i <= sqrt(numeroTeste); i++) {
            if (numeroTeste % i == 0) {
                primo = 0;
                break;
            }
        }

        if (primo) {
            printf("%d ", numeroTeste);
            quantidadePrimos++;
            soma += numeroTeste;
        }
        numeroTeste++;
    }
    printf("\nSoma: %d", soma);

    return 0;
}
