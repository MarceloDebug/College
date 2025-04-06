#include <stdio.h>
#include <math.h>

int main() {
    int num, i, soma = 0;

    printf("Digite a potencia de que numero deseja: ");
    scanf("%d", &num);

    for(i = 0; i <= num; i++) {
        printf("%d^%d", num, i);
        soma += pow(num, i);

        if(i != num) {
            printf(" + ");
        }
    }

    printf(" = %d", soma);

    return 0;
}
