#include <stdio.h>

int main() {
    int i;
    double nota, media = 0;
    printf("Digite os 10 valores:\n");

    for(i = 1; i <= 10; i++) {
        printf("%dº nota: ", i);
        scanf("%lf", &nota);
        media += nota;
    }

    printf("Media: %.2lf", media / 10);
    return 0;
}
