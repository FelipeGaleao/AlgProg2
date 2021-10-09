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

void troca(Estudante &a, Estudante &b) {
  Estudante tmp = a;
  a = b;
  b = tmp;
}

int separa(int p, int r, Estudante v[MAX], char opcao) {

  char pivot;
  Estudante pivotEstudante;

  if (opcao == 'r') {
    pivot = v[r].RGA;
  }
  if (opcao == 'n') {
    pivotEstudante = v[r];
  }
  if (opcao == 'm') {
    pivot = v[r].media;
  }
  int q = p;

  for (int i = p; i < r; i++) {
    if (opcao == 'r') {
      if (v[i].RGA <= pivot) {
        troca(v[i], v[q]);
        q++;
      }
    }
    if (opcao == 'n') {
      if (v[i].nome <= pivotEstudante.nome) {
        troca(v[i], v[q]);
        q++;
      }
    }
    if (opcao == 'm') {
      if (v[i].media <= pivot) {
        troca(v[i], v[q]);
        q++;
      }
    }
  }
  troca(v[q], v[r]);
  return q;
}

void quicksort(int p, int r, Estudante v[MAX], char opcao) {
  int q;
  if (p < r) {
    q = separa(p, r, v, opcao);
    q = separa(p, r, v, opcao);
    quicksort(p, q - 1, v, opcao);
    quicksort(q + 1, r, v, opcao);
  }
}

void imprimeEstudante(Estudante v[], int k);
void imprimeEstudantes(Estudante v[], int n) {
  for (int i = 0; i < n; i++) {
    printf("RGA: %d \n", v[i].RGA);
    printf("Nome: %s \n", v[i].nome);
    printf("Media: %.2lf \n", v[i].media);
    printf("------------ \n");
  }
}

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

  quicksort(0, qtdAlunos - 1, Estudantes, opcao);
  imprimeEstudantes(Estudantes, qtdAlunos);

  return 0;
}