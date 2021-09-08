#include <stdio.h>
#define MAX_LINHAS 10
#define MAX_COLUNAS 10
#define MAX_CARACTERES 50

void preencherMatriz(int n_linhas, int n_colunas, char matriz[MAX_LINHAS][MAX_COLUNAS]){
    char letra;
    int i; int j;
     for(int i = 0 ; i <= n_linhas ; i++) {
        for (int j = 0; j < n_colunas; j++) {
            scanf(" %c", &letra);
            matriz[i][j] = letra;
        }
    }
}

int main(){
    char matriz[MAX_LINHAS][MAX_COLUNAS];
    char palavra[MAX_CARACTERES];
    int qtdPalavras, n_colunas, n_linhas;
    scanf("%i %i", &n_linhas, &n_colunas);
    preencherMatriz(n_linhas, n_colunas, matriz);
    scanf("%i", &qtdPalavras);
    scanf("%c", &palavra);

}