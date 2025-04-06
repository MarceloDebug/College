#include <stdio.h>

int main() {
    int num, i = 1;

    printf("Digite um numero: ");
    scanf("%d", &num);

    while(i <= num){
        printf("%d ", i);
        i++;
    }

    return 0;
}
