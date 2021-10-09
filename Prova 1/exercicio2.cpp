#include <stdio.h>

struct Eletrodomestico {
  char nome[16];
  double potencia;
  double tad;
} eletrodomesticos;

void ler_eletrodomesticos(Eletrodomestico v[100], int qtd_eqpts) {
  for (int i = 0; i < qtd_eqpts; i++) {
    scanf("%s ", v[i].nome);
    scanf("%lf", &v[i].potencia);
    scanf("%lf", &v[i].tad);
  }
}

float calcular_consumo_total(Eletrodomestico v[100], int qtd_eqpts, int nd) {
  int kwhtotal = 0;
  for (int i = 0; i < qtd_eqpts; i++) {
    kwhtotal += (v[i].potencia * v[i].tad) * nd;
  }
  return kwhtotal;
}

void imprimir_porcentagem_equipamentos(Eletrodomestico v[100], int qtd_eqpts,
                                       int nd, int kwhtotal) {
  for (int i = 0; i < qtd_eqpts; i++) {
    float consumoeqpt = (v[i].potencia * v[i].tad) * nd;
    float pct_total = (consumoeqpt / kwhtotal) * 100;
    printf("%.2lf", pct_total);
    printf("%% \n");
  }
}

int main() {

  int numero_dias, qtd_eqpts, nd;
  float kwhtotal;
  Eletrodomestico eletrodomesticos[100];

  scanf("%i", &qtd_eqpts);

  ler_eletrodomesticos(eletrodomesticos, qtd_eqpts);
  scanf("%i", &nd);

  kwhtotal = calcular_consumo_total(eletrodomesticos, qtd_eqpts, nd);
  printf("%.2lf \n", kwhtotal);

  imprimir_porcentagem_equipamentos(eletrodomesticos, qtd_eqpts, nd, kwhtotal);

  return 0;
}