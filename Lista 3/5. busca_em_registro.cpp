#include <stdio.h>
#define MAX 1000

// Definir tipo de registro para Aluno

struct Aluno {
  int numero_aluno;
  char nome[21];
} Alunos;

int recursive_binary_search(Aluno Alunos[MAX], int begin, int end,
                            int numeroAluno) {
  /* Índice representando o meio do sub-vetor begin->end */
  int i = (begin + end) / 2;

  if (begin > end) { /* Ponto de parada. Item não está no vetor */
    return -1;
  }

  if (Alunos[i].numero_aluno == numeroAluno) { /* Item encontrado */
    for (int j = 0; j <= 21 && Alunos[i].nome[j] != '\0'; j++) {
      printf("%c", Alunos[i].nome[j]);
    }
    return 1;
  }

  if (Alunos[i].numero_aluno <
      numeroAluno) { /* Item está no sub-vetor à direita */
    return recursive_binary_search(Alunos, i + 1, end, numeroAluno);

  } else { /* Alunos[i] > item. Item está no sub-vetor à esquerda */
    return recursive_binary_search(Alunos, begin, i - 1, numeroAluno);
  }
}

void lerAlunos(int qtdAlunos, Aluno Alunos[MAX]) {
  for (int i = 0; i < qtdAlunos; i++) {
    scanf("%i", &Alunos[i].numero_aluno);
    scanf("%s", Alunos[i].nome);
  }
}


void buscarAluno(int qtdBuscas, Aluno Alunos[MAX], int qtdAlunos) {
  int numerosAluno[qtdBuscas];
  int resultadoBusca;
  for (int i = 0; i < qtdBuscas; i++) {
    scanf("%i", &numerosAluno[i]);
  }
  for (int i = 0; i < qtdBuscas; i++) {
    resultadoBusca = recursive_binary_search(Alunos, 0, qtdAlunos, numerosAluno[i]);
    if(resultadoBusca != 1){
      printf("%s", "\nnao encontrado");
      break;
    }
  }
}

int main() {

  int qtdAlunos, qtdBuscas;
  Aluno Alunos[MAX];

  scanf("%i", &qtdAlunos);
  lerAlunos(qtdAlunos, Alunos);
  scanf("%i", &qtdBuscas);

  buscarAluno(qtdBuscas, Alunos, qtdAlunos);

  return 0;
}