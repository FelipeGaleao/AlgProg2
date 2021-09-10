#include <stdio.h>


int piso_log2(int N){
   int i, n;
   i = 0;
   n = 1;
   while (n <= N/2) {
      n = 2 * n;
      i += 1;
   }
   return i;    
}
int main(){
    int numero;
    scanf("%i", &numero);
    numero = piso_log2(numero);
    printf("O numero eh: %i", numero);
    scanf("%i", numero);
}