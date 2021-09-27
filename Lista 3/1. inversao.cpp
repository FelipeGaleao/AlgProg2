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

void inverter_vetor(int vetor_valores[MAX_CARACTERES],
                    int vetor_invertido[MAX_CARACTERES], int vlr_esq,
                    int vlr_dir, int lim_vlr_dir, int tamanho_vetor,
                    int indice_i) {
  int vlr_temp = vlr_dir;
  if (indice_i < tamanho_vetor) {
    if (indice_i >= vlr_esq && indice_i <= lim_vlr_dir) {
      //   printf("%i ", vetor_valores[vlr_temp]);
      vetor_invertido[indice_i] = vetor_valores[vlr_dir];
      vlr_temp = vlr_dir - 1;
    } else {
      vetor_invertido[indice_i] = vetor_valores[indice_i];
      //   printf("%i ", vetor_valores[i]);
    }
    indice_i = indice_i + 1;
    inverter_vetor(vetor_valores, vetor_invertido, vlr_esq, vlr_temp,
                   lim_vlr_dir, tamanho_vetor, indice_i);
  }
}

int imprimir_vetor(int vetor_invertido[MAX_CARACTERES], int tamanho_vetor,
                   int index) {
  if (index < tamanho_vetor) {
    if (index == tamanho_vetor) {
      printf("%i \n", vetor_invertido[index]);
    } else {
      printf("%i ", vetor_invertido[index]);
    }
    imprimir_vetor(vetor_invertido, tamanho_vetor, index + 1);
  }
}
int main() {

  int tamanho_vetor = 0;
  int vlr_esq = 0;
  int vlr_dir = 0;
  int vetor_valores[MAX_CARACTERES];
  int vetor_invertido[MAX_CARACTERES];

  scanf("%i", &tamanho_vetor);
  scanf("%i %i", &vlr_esq, &vlr_dir);
  ler_vetores(tamanho_vetor, vetor_valores, 0);

  inverter_vetor(vetor_valores, vetor_invertido, vlr_esq, vlr_dir, vlr_dir,
                 tamanho_vetor, 0);

  imprimir_vetor(vetor_invertido, tamanho_vetor, 0);

  return 0;
}