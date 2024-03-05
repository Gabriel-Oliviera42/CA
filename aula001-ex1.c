#include <stdio.h>

// Função recursiva para calcular x elevado a n
float pot(float x, int n) {
    // Caso base: qualquer número elevado a 0 é 1
    if (n == 0) {
        return 1.0;
    } else if (n > 0) {
        // Caso positivo: x^n = x * x^(n-1)
        return x * pot(x, n - 1);
    } else {
        // Caso negativo: x^(-n) = 1 / (x^n), tratando números negativos
        return 1.0 / (x * pot(x, -(n + 1)));
    }
}

int main() {
    float base;
    int expoente;

    // Entrada do usuário para a base
    printf("Digite a base (x): ");
    scanf("%f", &base);

    // Entrada do usuário para o expoente
    printf("Digite o expoente (n): ");
    scanf("%d", &expoente);

    // Chamada da função pot para calcular o resultado
    float resultado = pot(base, expoente);

    // Exibição do resultado
    printf("%.2f elevado a %d é igual a %.4f\n", base, expoente, resultado);

    return 0;
}
