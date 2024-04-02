#include <stdio.h>

int main(void) {
    int num[5] = {5,2,6,1,3}; // Vetor com os números
    int aux = 0; // variavel auxiliar
    int i, j; // variaveis contadoras
    int n = 5; // 


    // laço de repetição para fazer a troca
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= n - 1; j++) {
            if(num[j] > num[j + 1]) {
                aux = num[j];
                num[j] = num[j + 1];
                num[j + 1] = aux; 
            }
        }
    }       
    
    return 0;
}
