#include <stdio.h>
#include <stdlib.h>

void percorreVetor(int n, int *p, int k) {
  int i;

  for (i = 0; i < n; i++) {
    if (*p % k != 0) {
      *p = *p / 2;
    }
    if (i < n - 1)
      printf("%i ", *p);
    if(i == n -1)
        printf("%i \n", *p);
    p++;
  }
}

int main() {
  int n, k;
  int *vetorPont;
  int vetor[100];
  
  scanf("%i %i", &n, &k);
  

  for (int i = 0; i < n; i++) {
    scanf("%i", &vetor[i]);
  }

  vetorPont = &vetor[0];

  percorreVetor(n, vetorPont, k);

  return 0;
}