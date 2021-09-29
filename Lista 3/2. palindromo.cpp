#include <stdio.h>
#define MAX_CARACTERES 100
#define MAX_PALAVRAS 10

void ler_palavras(char palavras[MAX_PALAVRAS][MAX_CARACTERES], int qtd_palavras,
                  int indice) {
  if (indice < qtd_palavras) {
    scanf("%s", palavras[indice]);
    ler_palavras(palavras, qtd_palavras, indice + 1);
  }
}

int contarTamanhoString(char string[MAX_CARACTERES], int tamanho_string,
                        int indice_contador) {
  if (string[indice_contador] != '\000') {
    return contarTamanhoString(string, tamanho_string + 1, indice_contador + 1);
  }
  return tamanho_string;
}

void inverter_string(char string[MAX_PALAVRAS][MAX_CARACTERES],
                     char palavras_temp[MAX_PALAVRAS][MAX_CARACTERES],
                     int indice, int indice_a, int tamanho_string) {

  if (indice_a <= tamanho_string) {
    palavras_temp[indice][indice_a] =
        string[indice][tamanho_string - indice_a - 1];
    indice_a = indice_a + 1;
    inverter_string(string, palavras_temp, indice, indice_a, tamanho_string);
  }
}

bool checkPalindromo(char string[MAX_PALAVRAS][MAX_CARACTERES],
                     char palavras_temp[MAX_PALAVRAS][MAX_CARACTERES],
                     int indice, int indice_a, int tamanho_string, int acertos,
                     bool CheckPalindromo) {
  if (indice_a <= tamanho_string) {
    if (string[indice][indice_a] == palavras_temp[indice][indice_a]) {
      acertos = acertos + 1;
      indice_a = indice_a + 1;
      checkPalindromo(string, palavras_temp, indice, indice_a, tamanho_string,
                      acertos, false);
    }
    if (indice_a == tamanho_string) {
      if (acertos == tamanho_string) {
        checkPalindromo(string, palavras_temp, indice, indice_a, tamanho_string,
                        acertos, true);
      } else {
        CheckPalindromo = false;
      }
    } else if (indice_a > tamanho_string) {
      CheckPalindromo = false;
    }
  }
  if (indice_a == true) {
    return true;
  } else {
    return false;
  }
}
void verificar_palindromo(char palavras[MAX_PALAVRAS][MAX_CARACTERES],
                          char palavras_temp[MAX_PALAVRAS][MAX_CARACTERES],
                          int qtd_palavras, int indice) {
  if (indice < qtd_palavras) {
    bool PalindromoCheck;
    int tamanho_string = contarTamanhoString(palavras[indice], 0, 0);
    inverter_string(palavras, palavras_temp, indice, 0, tamanho_string);
    PalindromoCheck = checkPalindromo(palavras, palavras_temp, indice, 0,
                                      tamanho_string, 0, false);
    if (PalindromoCheck == false) {
      printf("nao \n");
    } else {
      printf("palindromo \n");
    }
    indice = indice + 1;
    verificar_palindromo(palavras, palavras_temp, qtd_palavras, indice);
  }
}

int main() {
  int qtd_palavras;
  char palavras[MAX_PALAVRAS][MAX_CARACTERES];
  char palavras_temp[MAX_PALAVRAS][MAX_CARACTERES];
  scanf("%i", &qtd_palavras);

  ler_palavras(palavras, qtd_palavras, 0);
  verificar_palindromo(palavras, palavras_temp, qtd_palavras, 0);

  return 0;
}