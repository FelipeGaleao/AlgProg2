#include <stdio.h>
#define MAX 100

struct Estudante {
  int RGA;
  char nome[100];
  double media;
} Estudantes;

/* Buscas */

int buscaRGA(Estudante v[], int n, int RGA) {
  int esq, dir, meio;
  esq = -1;
  dir = n;
  while (esq < dir - 1) {
    meio = (esq + dir) / 2;
    if (v[meio].RGA < RGA)
      esq = meio;
    else
      dir = meio;
  }
  return dir;
}

int buscaNome(Estudante v[], int n, char nome[]) {
  int inicio = 0;
  int fim = n - 1;
  int meio;
  int j = 0;
  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    if (nome[j] == v[meio].nome[j])
      return meio;
    else if (nome[j] < v[meio].nome[j])
      fim = meio - 1;
    else if (nome[j] > v[meio].nome[j])
      inicio = meio + 1;
  }
  return -1;
}
int buscaMedia(Estudante v[], int n, double media) {
  int inicio = 0;
  int fim = n - 1;
  int meio;

  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    if (media == v[meio].media)
      return meio;
    else if (media < v[meio].media)
      fim = meio - 1;
    else if (media > v[meio].media)
      inicio = meio + 1;
  }
  return -1;
}

void troca(Estudante &a, Estudante &b) {
  Estudante tmp = a;
  a = b;
  b = tmp;
}

int strcmp(char a, char b) {
  if (a > b) {
    return -1;
  }
  if (a == b) {
    return 0;
  }
  if (a <= b) {
    return 1;
  }
}

int separa(int p, int r, Estudante v[MAX], char opcao) {

  char pivot;
  int pivotRGA;
  float pivotMedia;
  Estudante pivotEstudante;

  if (opcao == 'r') {
    pivotRGA = v[r].RGA;
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
      if (v[i].RGA <= pivotRGA) {
        troca(v[i], v[q]);
        q++;
      }
    }

    if (opcao == 'n') {
      int k;
      for (k = 0; v[i].nome[k] == pivotEstudante.nome[k]; k++);
      int vl = strcmp(v[i].nome[k], pivotEstudante.nome[k]);
      if (vl == 1) {
          troca(v[i], v[q]);
          q++;
      }
  
    }
    if (opcao == 'm') {
      if (v[i].media <= pivotMedia) {
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
    quicksort(p, q - 1, v, opcao);
    quicksort(q + 1, r, v, opcao);
  }
}
void imprimeEstudante(Estudante v[], int k) {
  if (k < 0) {
    printf("RGA: null \n");
    printf("Nome: null \n");
    printf("Media: null \n");
    printf("------------ \n");
  } else {
    printf("RGA: %d \n", v[k].RGA);
    printf("Nome: %s \n", v[k].nome);
    printf("Media: %.2lf \n", v[k].media);
    printf("------------ \n");
  }
};
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

void ordenaEstudantes(Estudante v[], int n, char op) {
  quicksort(0, n - 1, v, op);
}

int main() {

  int qtdAlunos, qtdBuscas;
  char opcao;
  Estudante Estudantes[MAX];

  scanf("%d", &qtdAlunos);

  ler_estudantes(qtdAlunos, Estudantes);
  scanf(" %c", &opcao);
  scanf("%d", &qtdBuscas);

  ordenaEstudantes(Estudantes, qtdAlunos, opcao);
  // quicksort(0, qtdAlunos - 1, Estudantes, opcao);
  // int a = buscaNome(Estudantes, qtdAlunos, "jorge");
  // printf("%i", a);
  // printf("\n");
  // imprimeEstudante(Estudantes, a);
  imprimeEstudantes(Estudantes, qtdAlunos);

  return 0;
}