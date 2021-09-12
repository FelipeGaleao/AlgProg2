#include <stdio.h>


int piso_log2(int N){
   int i, n;
   i = 0;
   n = 1;
   if(n <= 2){
      return 1;
   }else{
      i++;
      return n <= N/2;
   }
   return i;    
}
int main(){
    int numero;
    scanf("%i", &numero);
    while(numero < 1){
       printf("Você precisa inserir um número maior que 1");
    }
    int resultado = piso_log2(numero);
    printf("O logaritmo de %i na base 2 = %i", numero, resultado);
    return 0;
}