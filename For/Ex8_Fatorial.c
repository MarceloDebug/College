#include <stdio.h>

int main() {
    int num, i, fatorial = 1;
    printf("Digite um numero: ");
    scanf("%d", &num);

    for(i = num; i >= 1; i--) {
        fatorial *= i;
        printf("%d", i);

        if(i != 1) {
            printf(" * ");
        }
    }

    printf(" = %d", fatorial);

    return 0;
}
