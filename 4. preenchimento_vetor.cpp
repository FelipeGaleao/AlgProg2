#include <stdio.h>

int main(){
    // definições de variáveis 
    float valor_recebido[21] = {};

    // entrada 
    scanf("%f", &valor_recebido[0]);

    // processamento e saída 
    for(int i = 0; i < 21; i = i+1){
        valor_recebido[i+1] = valor_recebido[i]/2;
        printf("N[%d] = %.4f \n", i, valor_recebido[i]);
        
    }

    return 0;
}