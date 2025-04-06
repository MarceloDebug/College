#include <stdio.h>

int main() {
    int n1 = 0, i, n2;

    for (i = 1; i <= 3; i++) {
        printf("%do valor: ", i);
        scanf("%d", &n2);

        if (n2 > n1)
            n1 = n2;
    }

    printf("Maior número: %d", n1);

    return 0;
}
