#include <stdio.h>

int main() {
    int l1, l2, l3;
    printf("Digite os lados do triangulo: ");
    scanf("%d", &l1);
    scanf("%d", &l2);
    scanf("%d", &l3);

    if (l1 + l2 > l3 && l2 + l3 > l1 && l3 + l1 > l2) {
        if (l1 == l2 && l1 == l3) {
            printf("Forma um triangulo equilatero");
        } else if (l1 == l2 || l2 == l3 || l1 == l3) {
            printf("Forma um triangulo isosceles");
        } else {
            printf("Forma um triangulo escaleno");
        }
    } else {
        printf("Não forma um triangulo");
    }

    return 0;
}
