#include <stdio.h>
#include <stdlib.h>

int main() {

  int n;

  scanf("%d", &n);

  int **cubo_magico = new int *[n];
  
  for (int i = 0; i < n; i++) {
    cubo_magico[i] = new int[n];
  }

  for(int linha = 0; linha < n; linha++){
      for(int coluna = 0; coluna < n; coluna++){
          scanf("%d", &cubo_magico[linha][coluna]);
      }
  }

  int *soma_linha = new int[n];
  int *soma_coluna = new int[n];
  int soma_dp = 0;
  int soma_ds = 0;
  int vlrLinha = 1;
  int vlrColuna = 1;

  soma_dp = 0, soma_ds = 0;

  for(int linha = 0; linha < n; linha++){
      soma_linha[linha] = 0;
      for(int coluna = 0; coluna < n; coluna++){
          soma_linha[linha] += cubo_magico[linha][coluna];
      }
  }

  for(int coluna = 0; coluna < n; coluna++){
      soma_coluna[coluna] = 0;
      for(int linha = 0; linha < n; linha++){
          soma_coluna[coluna] += cubo_magico[linha][coluna];
      }
  }

  for(int i = 0; i < n; i++){
      soma_dp += cubo_magico[i][i];
  }
  
  
  for(int i = 0; i < n; i++){
      soma_ds += cubo_magico[i][n-i-1];
  }


   for(int j = 0; j < n-1; j++){
       if(soma_linha[j] != soma_linha[j+1])
        vlrLinha = 0;
   }

    for(int j = 0; j < n-1; j++){
        if(soma_coluna[j] != soma_coluna[j+1])
            vlrColuna = 0;
    }

    if((vlrLinha == 1 && vlrColuna == 1) && (soma_dp == soma_ds)){
        printf("Quadrada!");
    }else{
        printf("Nao!");
    }
    
  delete [] cubo_magico;
  delete [] soma_linha;
  delete [] soma_coluna;


  return 0;
}