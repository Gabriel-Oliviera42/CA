#include <stdio.h>

// Função recursiva para calcular a soma de elementos em um array
float somaArray(float arr[], int n) {
    // quando não há elementos no array
    if (n == 0) {
        return 0.0; // lembrando que vai develver um float
    } else {
        // Soma do elemento atual com a soma do restante do array
        return arr[n - 1] + somaArray(arr, n - 1);
    }
}

int main() {
    // Exemplo de array
    float exemploArray[] = {1.5, 2.0, 3.5, 4.0, 5.5};
    int tamanhoArray = sizeof(exemploArray) / sizeof(exemploArray[0]);

    // Chamada da função para calcular a soma
    float resultado = somaArray(exemploArray, tamanhoArray);

    // Exibição do resultado
    printf("A soma dos elementos no array é: %.2f\n", resultado);

    return 0;
}
