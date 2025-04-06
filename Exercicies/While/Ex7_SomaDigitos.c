#include <stdio.h>

int main() {
    int soma = 0, num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    while(num != 0){
        soma += num % 10;
        num /= 10;
    }

    printf("Soma digitos: %d", soma);

    return 0;
}
