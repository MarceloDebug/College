#include <stdio.h>

int main() {
    int n, i;
    int a = 0, b = 1, fibonacci = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        fibonacci = a + b;
        a = b;
        b = fibonacci;
    }

    printf("Termo %d da série de Fibonacci é: %d\n", n, a);

    return 0;
}
