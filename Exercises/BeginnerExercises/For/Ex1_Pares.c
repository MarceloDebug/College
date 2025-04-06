#include <stdio.h>

int main() {
    int limite, i;

    printf("Digite o numero limite: ");
    scanf("%d", &limite);

    printf("Numeros pares: ");
    for(i = 2; i <= limite; i++) {
        if(i % 2 == 0) {
            printf(" %d,", i);
        }
    }

    return 0;
}
