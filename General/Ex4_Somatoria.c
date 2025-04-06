#include <stdio.h>

int main() {
    int val, som = 0, i;
    printf("Digite um valor para somatoria: ");
    scanf("%d", &val);

    for (i = 1; i <= val; i++) {
        som += (5 * (i * i) + (2 * i) + 8);
    }

    printf("%d", som);

    return 0;
}
