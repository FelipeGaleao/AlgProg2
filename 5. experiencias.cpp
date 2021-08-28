#include <stdio.h>

int main (){

    int qtd_teste = 0, quantia = 0;
    float qtd_coelho = 0, qtd_rato = 0, qtd_sapo = 0;
    char tipo;

    scanf("%d", &qtd_teste);
    for(int i = 0; i < qtd_teste; i++){
        scanf("%i %c", &quantia, &tipo);

        switch(tipo){
            case 'C':
            qtd_coelho += quantia;
            break;

            case 'S':
            qtd_sapo += quantia;
            break;
      
            case 'R':
            qtd_rato += quantia;
            break;
            
            default:
            printf("Opção invalida, tente novamente! \n");
            break;
        }

    }
    int total = qtd_coelho + qtd_rato + qtd_sapo;
 
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %f\n", qtd_coelho);
    printf("Total de ratos: %f\n", qtd_rato);
    printf("Total de sapos: %f\n", qtd_sapo);
    printf("Percentual de coelhos: %.2f \% \n", (qtd_coelho/total)*100);
    printf("Percentual de ratos: %.2f \% \n", (qtd_rato/total)*100);
    printf("Percentual de sapos: %.2f \% \n", (qtd_sapo/total)*100);

 return 0;
}