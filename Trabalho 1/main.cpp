#include <stdio.h>
#define MAX 100

/* Criação da estrutura de registro para Estudante */

struct Estudante {
  int RGA;
  char nome[100];
  float media;
} Estudantes;

/* Função para verificar se os nomes são iguais.
  char palavra[MAX] => palavra a ser comparada 1;
  char palavra_buscada[MAX] => palavra a ser comparada 2;

  Compara as duas palavras, caso for igual retorna 1, se não, verifica se é
  maior, se for retorna -1, se não for retorna 0

  */

int check_nome(char palavra[MAX], char palavra_buscada[MAX]) {
  int i;

  for (i = 0; palavra[i] == palavra_buscada[i]; i++)
    if (palavra[i] == '\0')
      return 1;
  if (palavra[i] > palavra_buscada[i])
    return -1;
  if (palavra[i] < palavra_buscada[i])
    return 0;
}

/* Função para comparar duas strings e definir qual é maior que a outra */

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

/* Buscas */

int buscaRGA(Estudante v[], int n, int RGA) {
  int inicio = 0;
  int fim = n - 1;
  int meio;

  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    if (RGA == v[meio].RGA)
      return meio;
    else if (RGA < v[meio].RGA)
      fim = meio - 1;
    else if (RGA > v[meio].RGA)
      inicio = meio + 1;
  }
  return -1;
}

int buscaNome(Estudante v[], int n, char nome[MAX]) {
  int inicio = 0;
  int fim = n - 1;
  int meio;
  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    if (check_nome(nome, v[meio].nome) == 1)
      return meio;
    else if ((check_nome(nome, v[meio].nome) == 0))
      fim = meio - 1;
    else if ((check_nome(nome, v[meio].nome) == -1))
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

/* Métodos para ordenação */

void troca(Estudante &a, Estudante &b) {
  Estudante tmp = a;
  a = b;
  b = tmp;
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
    pivotMedia = v[r].media;
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
      for (k = 0; v[i].nome[k] == pivotEstudante.nome[k]; k++)
        ;
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

void ordenaEstudantes(Estudante v[], int n, char op) {
  quicksort(0, n - 1, v, op);
}

/* Funções para impressão e leituras do estudante */

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
    scanf("%f", &Estudantes[i].media);
  }
}

/* Funções para buscar um estudante */

void buscarEstudantes(char opcao, char nomeBusca[10000][MAX],
                      int rgaBusca[10000], float mediaBusca[10000],
                      int qtdBuscas, Estudante Estudantes[MAX], int qtdAlunos) {

  if (opcao == 'n') {
    for (int i = 0; i < qtdBuscas; i++) {
      scanf("%s", nomeBusca[i]);
    }
  }

  if (opcao == 'r') {
    for (int i = 0; i < qtdBuscas; i++) {
      scanf("%d", &rgaBusca[i]);
    }
  }
  if (opcao == 'm') {
    for (int i = 0; i < qtdBuscas; i++) {
      scanf("%f", &mediaBusca[i]);
    }
  }

  for (int i = 0; i < qtdBuscas; i++) {
    int vlrBusca;
    if (opcao == 'n')
      vlrBusca = buscaNome(Estudantes, qtdAlunos, nomeBusca[i]);

    if (opcao == 'r')
      vlrBusca = buscaRGA(Estudantes, qtdAlunos, rgaBusca[i]);

    if (opcao == 'm')
      vlrBusca = buscaMedia(Estudantes, qtdAlunos, mediaBusca[i]);

    imprimeEstudante(Estudantes, vlrBusca);
  }
}

int main() {

  int qtdAlunos, qtdBuscas;
  char opcao;
  char nomeBusca[10000][MAX];
  int rgaBusca[10000];
  float mediaBusca[10000];

  Estudante Estudantes[MAX];

  scanf("%d", &qtdAlunos);

  ler_estudantes(qtdAlunos, Estudantes);

  scanf(" %c", &opcao);
  scanf("%d", &qtdBuscas);

  ordenaEstudantes(Estudantes, qtdAlunos, opcao);

  buscarEstudantes(opcao, nomeBusca, rgaBusca, mediaBusca, qtdBuscas,
                   Estudantes, qtdAlunos);

  imprimeEstudantes(Estudantes, qtdAlunos);

  return 0;
}