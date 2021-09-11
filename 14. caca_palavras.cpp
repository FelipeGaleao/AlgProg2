#include <stdio.h>
#define MAX_LINHAS 15
#define MAX_COLUNAS 10
#define MAX_CARACTERES 15

void ler_matriz(int n_linhas,
                int n_colunas,
                char matriz_a[MAX_LINHAS][MAX_COLUNAS]){
    char letra;
    int i; int j;
     for(int i = 0 ; i < n_linhas ; i++) {
        for (int j = 0; j < n_colunas; j++) {
            scanf(" %c", &letra);
            matriz_a[i][j] = letra;
        }
    }
}

void criar_matriz_pontos(int n_linhas,
                         int n_colunas,
                         char matriz_b[MAX_LINHAS][MAX_COLUNAS]){
    int i, j;
    for(int i = 0 ; i <= n_linhas ; i++) {
        for (int j = 0; j < n_colunas; j++) {
            matriz_b[i][j] = '.';
        }
}
}

void marcar_ocorrencia_horizontal(char palavra[MAX_CARACTERES],
        char matriz_a[MAX_LINHAS][MAX_COLUNAS],
        char matriz_b[MAX_LINHAS][MAX_COLUNAS],
        int m, int n, int i, int j)
{   
    int z = 0;
    for(int k = j; k < n; k++){
        if(matriz_a[i][k] == palavra[z]){
            matriz_b[i][k] = palavra[z];
            z++;
        }
    }
    if(z < 3){
    z = 0;
    for(int k = n; k >= 0; k--){
            if(matriz_a[i][k] == palavra[z]){
                matriz_b[i][k] = palavra[z];
                z++;
            }
        }
    }
 }

void marcar_ocorrencia_diagonal(char palavra[MAX_CARACTERES],
        char matriz_a[MAX_LINHAS][MAX_COLUNAS],
        char matriz_b[MAX_LINHAS][MAX_COLUNAS],
        int m, int n, int i, int j)
{  
     int z = 0;
    for(int k = j; k < m; k++){
        if(matriz_a[k][j] == palavra[z]){
            matriz_b[k][j] = palavra[z];
            z++;
            j++;
        }
    }
    if(z < 3){
        z = 0;
         for(int k = m; k >= 0; k--){
        if(matriz_a[k][j] == palavra[z]){
            matriz_b[k][j] = palavra[z];
            z++;
            j++;
        }
    }
    }

}

void marcar_ocorrencia_vertical(char palavra[MAX_CARACTERES],
        char matriz_a[MAX_LINHAS][MAX_COLUNAS],
        char matriz_b[MAX_LINHAS][MAX_COLUNAS],
        int m, int n, int i, int j)
{  
    
  int z = 0;
    for(int k = j; k < m; k++){
        if(matriz_a[k][j] == palavra[z]){
            matriz_b[k][j] = palavra[z];
            z++;
        }
    }
    if(z < 3){
    z = 0;
    for(int k = m; k >= 0; k--){
            if(matriz_a[k][j] == palavra[z]){
                matriz_b[k][j] = palavra[z];
                z++;
            }
        }
    }
 }


void marcar_ocorrencias(char palavra[MAX_CARACTERES],
        char matriz_a[MAX_LINHAS][MAX_COLUNAS],
        char matriz_b[MAX_LINHAS][MAX_COLUNAS],
        int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            marcar_ocorrencia_horizontal(palavra, matriz_a, matriz_b, m, n, i, j);
            marcar_ocorrencia_vertical(palavra, matriz_a, matriz_b, m, n, i, j);
            marcar_ocorrencia_diagonal(palavra, matriz_a, matriz_b, m, n, i, j);
        }
    }
}

int main(){
    char matriz_a[MAX_LINHAS][MAX_COLUNAS];
    char matriz_b[MAX_LINHAS][MAX_COLUNAS];
    char palavra[MAX_CARACTERES];
    int qtdPalavras, n_colunas, n_linhas;
    scanf("%i %i", &n_linhas, &n_colunas);

    ler_matriz(n_linhas, n_colunas, matriz_a);
    criar_matriz_pontos(n_linhas, n_colunas, matriz_b);

    scanf("%i", &qtdPalavras);

    for(int i = 0; i < qtdPalavras; i++){
        scanf("%s", &palavra);
        marcar_ocorrencias(palavra, matriz_a, matriz_b, n_linhas, n_colunas);
    }

      for (int i = 0; i < n_linhas; i++) {
        for (int j = 0; j < n_colunas; j++) {
            printf("%c ", matriz_b[i][j]);
        }
        printf("\n");
    }
    scanf("%c");
    return 0;
}