#include <stdio.h>

int main() {
    int soma = 0, i;

    for(i = 1; i <= 100; i++) {
        if(i % 2 == 0) {
            soma += i;
        }
    }

    printf("soma dos pares de 1 a 100: %d", soma);
    return 0;
}
