#include <stdio.h>
#define MAX 100

struct Estudante {
  int RGA;
  char nome[100];
  double media;
} Estudantes;

/* Buscas */

int buscaRGA(Estudante v[], int n, int RGA);
int buscaNome(Estudante v[], int n, char nome[]);
int buscaMedia(Estudante v[], int n, double media);

void ordenaEstudantes(Estudante v[], int n, char op){};

void imprimeEstudante(Estudante v[], int k);
void imprimeEstudantes(Estudante v[], int n);

void ler_estudantes(int qtdAlunos, Estudante Estudantes[MAX]) {
  for (int i = 0; i < qtdAlunos; i++) {
    scanf("%i", &Estudantes[i].RGA);
    scanf(" %[^\n]s", &Estudantes[i].nome);
    scanf("%lf", &Estudantes[i].media);
  }
}

int main() {

  int qtdAlunos, qtdBuscas;
  char opcao;
  Estudante Estudantes[MAX];

  scanf("%d", &qtdAlunos);

  ler_estudantes(qtdAlunos, Estudantes);

  scanf(" %c", &opcao);
  scanf("%d", &qtdBuscas);

  s

  return 0;
}