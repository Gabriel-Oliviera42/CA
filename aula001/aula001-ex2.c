#include <stdio.h>

int f2(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    else
        return f2(n - 1) + 2 * f2(n - 2);
}

//Vamos calcular o valor para um exemplo específico, digamos n = 3:

/*
  f2(3) = f2(2) + 2 * f2(1)
        = (f2(1) + 2 * f2(0)) + 2 * 1
        = (1 + 2 * 1) + 2 * 1
        = 3 + 2
        = 5
*/

int main() {
    // Teste i: f2(0)
    printf("f2(0) = %d\n", f2(0));

    // Teste ii: f2(1)
    printf("f2(1) = %d\n", f2(1));

    // Teste iii: f2(5)
    printf("f2(5) = %d\n", f2(5));

    return 0;
}