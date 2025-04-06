#include <stdio.h>

int main() {
    int i = 0, numeroDigitado, numero = 42; //numero fixo em 42

    while(i != 1){
        printf("Tente adivinhar o numero: ");
        scanf("%d", &numeroDigitado);

        if (numeroDigitado == numero){
            printf("Você acertou!!");
            i = 1;
        }
        else{
            printf("Errou!! Tente novamente\n\n");
        }
    }

    return 0;
}
