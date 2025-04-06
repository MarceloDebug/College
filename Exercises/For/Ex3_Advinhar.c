#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, num, adivinhado;
    num = rand() % 10;

    for(int i = 0; i < 1;) {
        printf("Tente adivinhar o número: ");
        scanf("%d", &adivinhado);

        if(adivinhado == num) {
            printf("Parabens, voce acertou!!");
            break;
        }
    }

    return 0;
}
