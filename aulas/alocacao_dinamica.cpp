#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    scanf("%i", &n);
    int x[100], y[100];
    int prod;
    for(int i = 0; i < n; i++){
        scanf("%i", &x[i]);
    }

    for(int i = 0; i < n; i++){
        scanf("%i", &y[i]);
    }

    for(int i = 0; i < n; i++){
        prod = prod + x[i] * y[i];
        printf("O produto escalar: %i \n", prod);
    }

    return 0;
}