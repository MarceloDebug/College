#include <stdio.h>

int main() {
    int i = 1;
    double media = 0, numero;

    while(i <= 5){
        printf("Digite o %d numero: ", i);
        scanf("%lf", &numero);
        media += numero;
        i++;
    }

    printf("Média: %.2lf", media / 5);

    return 0;
}
