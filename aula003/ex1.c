#include <stdio.h>

int main(void) {
    int num[10]; // Vetor com os números
    int aux = 0; // variavel auxiliar
    int i, j; // variaveis contadoras
    int trocas = 0; // variavel para guardar a quantidade de trocas

    // laça de repetição para ler os números do vetor
    for (i = 0; i < 10; i++) {
        printf("Digite o número: ");
        scanf("%d", &num[i]);
    }

    // laço de repetição para fazer a troca
    for (j = 0; j < 10; j++) {
        for (i = 0; i < 10; i++) {
            if(num[i] > num[i + 1]) {
                aux = num[i];
                num[i] = num[i + 1];
                num[i + 1] = aux; 
                trocas = trocas + 3; // acontece tres trocas a cada subistituição 
            }
        }
    }

    //laço de repetição para escrever o vetor em organizado
    for (i = 0; i < 10; i++) {
        printf("%d ",num[i]);
    }

    printf("\n%d ",trocas);

    return 0;
}
