#include <stdio.h>

int main(void) {
    int num[5] = {5,2,6,1,3}; // Vetor com os números
    int aux = 0; // variavel auxiliar
    int i, j; // variaveis contadoras
    int n = 5; // 
    int menor; // 


    // laço de repetição para fazer a troca
    for (i = 0; i < n - 1; i++) {
        menor = i;
        for (j = i + 1; j < n; j++) {
            if (num[j] < num[menor]) {
                menor = j;
            }
        }

        if (i != menor) {
            aux = num[i];
            num[i] = num[menor];
            num[menor] = aux; 
        }
    }       
    
    return 0;
}
