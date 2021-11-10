#include <stdio.h>
#include <stdlib.h>



int main(){

    int n, i, j, troca, soma, somant, k;


    scanf("%d", &n);

    int *vetor = new int[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }


for (i = 0; i <= n - 1; i++) {
    for (j = i + 1; j <= n - 1; j++) {
      if (vetor[i] > vetor[j]) {
        troca = vetor[j];
        vetor[j] = vetor[i];
        vetor[i] = troca;
      }
    }
  }
  k = n - 1;
  soma = vetor[0] + vetor[k];
  for (i = 1; i <= (n / 2) - 1; i++) {
    k--;
    somant = vetor[i] + vetor[k];
    if (soma != somant)
      i = 2 * n;

    soma = somant;
  }

  if (i == 2 * n + 1){
    printf("Nao!");
  }
  else{
    printf("Ok!");
  }

    return 0;
}