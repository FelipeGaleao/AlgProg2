#include <stdio.h>
#define MAX 100000

int recursive_binary_search(int valores[MAX], int begin, int end, int item)
{
    /* Índice representando o meio do sub-vetor begin->end */
    int i = (begin + end) / 2;

    if (begin > end) {  /* Ponto de parada. Item não está no vetor */
        return -1;
    }

    if (valores[i] == item) {  /* Item encontrado */
        if(i == valores[i]){
            return valores[i];
        }
    }

    if (valores[i] < item) {  /* Item está no sub-vetor à direita */
        return recursive_binary_search(valores, i+1, end, item);


    } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
        return recursive_binary_search(valores, begin, i-1, item);
    }
}    



int main(){
    int qtdValores;
    int valores[MAX];
    bool Achei;
    int VlEncontrado;
    scanf("%i", &qtdValores);
    
    for(int i = 0; i < qtdValores; i++){
        scanf("%i", &valores[i]);
    }

    for(int i = 0; i < qtdValores; i++){
       int Vl = recursive_binary_search(valores, 0, qtdValores, valores[i]);
       if(Vl == i){
           VlEncontrado = Vl;
           Achei = true;
           break;
       }
    }

    if(Achei == true){
        printf("%i", valores[VlEncontrado]);
    }else{
        printf("not found");
    }
    


    return 0;
}