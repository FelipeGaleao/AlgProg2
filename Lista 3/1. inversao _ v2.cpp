#include <stdio.h>
#define MAX_CARACTERES 1000

void ler_vetores(int tamanho_vetor, int vetor_valores[MAX_CARACTERES],
                 int index) {
  if (index < tamanho_vetor) {
    int var_temp;
    scanf("%i", &var_temp);
    vetor_valores[index] = var_temp;
    ler_vetores(tamanho_vetor, vetor_valores, index + 1);
  }
}

void inverte(int v[1000], int n, int esq, int dir) {
   int aux;
    // Versao recursiva
    if(esq < dir){
        aux = v[esq];
        v[esq] = v[dir];
        v[dir] = aux;
        inverte(v, n, esq+1, dir-1);
    }
}

void imprimir_vetor(int vetor_valores[MAX_CARACTERES], int tamanho_vetor,
                   int index) {
  if (index < tamanho_vetor) {
    if (index == tamanho_vetor) {
      printf("%i \n", vetor_valores[index]);
    } else {
      printf("%i ", vetor_valores[index]);
    }
    imprimir_vetor(vetor_valores, tamanho_vetor, index + 1);
  }
}
int main() {

  int tamanho_vetor = 0;
  int vlr_esq = 0;
  int vlr_dir = 0;
  int vetor_valores[MAX_CARACTERES];

  scanf("%i", &tamanho_vetor);
  scanf("%i %i", &vlr_esq, &vlr_dir);
  ler_vetores(tamanho_vetor, vetor_valores, 0);

  inverte(vetor_valores, tamanho_vetor, vlr_esq, vlr_dir);


  imprimir_vetor(vetor_valores, tamanho_vetor, 0);

  return 0;
}