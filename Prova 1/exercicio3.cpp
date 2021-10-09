#include <stdio.h>

void troca(int &a, int &b) {
  char tmp = a;
  a = b;
  b = tmp;
}
int buscarPivot(int qtdElementos, int v[1001]) {
  int i = (qtdElementos - 1) / 2;
  return v[i];
}

int separa(int p, int r, int v[1001]) {
  
  int pivot;
 // Para vetores de tamanho par, é o último elemento da primeira metade 
  if ((r + 1) % 2 == 0) {
    pivot = ((r+1)/2)-1;
  }
   else {
    pivot = buscarPivot((r - 1) / 2, v);
  }


  int q = p;
  for (int i = p; i < r; i++) {
    if (v[i] <= pivot) {
      troca(v[i], v[q]);
      q++;
    }
  }
  troca(v[q], v[r]);
  return q;
}

void quicksort(int p, int r, int v[1001]) {
  int q;
  if (p < r) {
    q = separa(p, r, v);
    q = separa(p, r, v);
    // quicksort(p, q - 1, v);
    // quicksort(q + 1, r, v);
  }
}

void ler_elementos(int v[1001], int qtdElementos) {
  for (int i = 0; i < qtdElementos; i++) {
    scanf("%i", &v[i]);
  }
}

int main() {
  int v[1001], qtdElementos, numeroPivot;

  scanf("%i ", &qtdElementos);
  ler_elementos(v, qtdElementos);
  quicksort(0, qtdElementos - 1, v);
  return 0;
}