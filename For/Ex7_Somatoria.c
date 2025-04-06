#include <stdio.h>

int main() {
    int tamanho, i, soma = 0, valor;

    printf("Digite o tamanho da sequencia: ");
    scanf("%d", &tamanho);

    for(i = 1; i <= tamanho; i++) {
        printf("Digite o %do valor: ", i);
        scanf("%d", &valor);
        soma += valor;
    }

    printf("Somatoria = %d", soma);

    return 0;
}
