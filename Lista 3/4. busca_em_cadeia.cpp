#include <stdio.h>
#define MAX 100

int strcmp(char palavra[MAX], char palavra_buscada[MAX]) {
  int i;

  for (i = 0; palavra[i] == palavra_buscada[i]; i++)
    if (palavra[i] == '\0')
      return 1;
  return -1;
}

int main() {
  int qtdPalavras;
  char palavras[MAX][MAX];
  char palavrasBuscadas[20][MAX];
  int qtdBuscas;
  scanf("%i", &qtdPalavras);

  for (int i = 0; i < qtdPalavras; i++) {
    scanf("%s", palavras[i]);
  }

  scanf("%i", &qtdBuscas);

  for (int i = 0; i < qtdBuscas; i++) {
    scanf("%s", palavrasBuscadas[i]);
  }

  for (int i = 0; i < qtdBuscas; i++) {
    int vl;
    for (int j = 1; j <= qtdPalavras; j++) {
      vl = strcmp(palavras[j], palavrasBuscadas[i]);
      if(vl == 1)
      break;
    }
    if (vl == 1) {
      printf("encontrado\n");
    } else {
      printf("nao encontrado\n");
    }
  }
  return 0;
}