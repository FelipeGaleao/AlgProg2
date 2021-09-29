#include <stdio.h>
#define MAX 100

// Definir tipo de registro para Aluno

struct Aluno {
  int numero_aluno;
  char nome[20];
} Alunos;

int recursive_binary_search(Aluno Alunos[1000], int begin, int end, int item) {
  /* Índice representando o meio do sub-vetor begin->end */
  int i = (begin + end) / 2;

  if (begin > end) { /* Ponto de parada. Item não está no vetor */
    return -1;
  }

  if (Alunos[i].numero_aluno == item) { /* Item encontrado */
    int j = 0;
    while (Alunos[i].nome != '\000') {
        printf("%c", Alunos[i].nome[j]);
        j++;
        if(Alunos[i].nome[j] == '\000'){
          printf("\n");
          break;
        }
    }
  }

  if (Alunos[i].numero_aluno < item) { /* Item está no sub-vetor à direita */
    return recursive_binary_search(Alunos, i + 1, end, item);

  } else { /* vector[i] > item. Item está no sub-vetor à esquerda */
    return recursive_binary_search(Alunos, begin, i - 1, item);
  }
}

void lerAlunos(int qtdAlunos, Aluno Alunos[1000]) {
  for (int i = 0; i < qtdAlunos; i++) {
    scanf("%i", &Alunos[i].numero_aluno);
    scanf("%s", Alunos[i].nome);
  }
}

// void exibirNomeAluno(int Aluno Alunos[1000]){
//   for(int i = 0; i < 20; i++){
//     printf("%c", Alunos[])
//   }
// }

void buscarAluno(int qtdBuscas, Aluno Alunos[1000], int qtdAlunos) {
  int numeroAluno;
  int resultadoBusca;
  for (int i = 0; i < qtdBuscas; i++) {
    scanf("%i", &numeroAluno);
    resultadoBusca = recursive_binary_search(Alunos, 0, qtdAlunos, numeroAluno);
    if (resultadoBusca != -1) {
      printf("encontrado");
    } else {
      printf("nao encontrado");
    }
  }
}

int main() {

  int qtdAlunos, qtdBuscas;
  Aluno Alunos[1000];

  scanf("%i", &qtdAlunos);
  lerAlunos(qtdAlunos, Alunos);
  scanf("%i", &qtdBuscas);

  buscarAluno(qtdBuscas, Alunos, qtdAlunos);

  return 0;
}