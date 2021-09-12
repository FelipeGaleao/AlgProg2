#include <stdio.h>
#include <math.h>


// (a) Escreva uma função não-recursiva com a seguinte interface:


int pot(int x, int n){
    int resultado = 0;
    while(n > 0){
        resultado += x;
        n -= 1;
    }
    return resultado;
}

// (b) Escreva uma função recursiva com a seguinte interface:


int potR(int x, int n){
    if(n == 0){
        return 1;
    }else if(n > 1){
        return (x * potR(x, n-1));
    }
}

// (c) Escreva um programa que receba dois números inteiros e demonstre os dois resultados

void calcular(void){
    int valor_x, valor_n;
    scanf("%i %i", &valor_x, &valor_n);
    printf("O resultado sem RECURSIVIDADE sera: \n %d \n", pot(valor_x, valor_n));
    printf("O resultado com RECURSIVIDADE sera: \n %d \n", potR(valor_x, valor_n));
}


int main(){

    calcular();

}
