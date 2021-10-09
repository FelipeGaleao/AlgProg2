#include <stdio.h>


int soma_digito(int n){
    if(n == 0)
        return 0;
    return ((n % 10) + soma_digito(n / 10));
}

int main() {
  int numero;
  scanf("%i", &numero);
  int vl = soma_digito(numero);
  printf("%i", vl);

return 0;
}