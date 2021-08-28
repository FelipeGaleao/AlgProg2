#include <stdio.h>

int main()
{

    // definições de variáveis
    int codigo, numpecas, i;
    float valor_unit, valor_total;

    // repetição para gerar duas entradas e fazer o processamento do valor_total
    for (i = 0; i < 2; i++)
    {
        scanf("%d %d %f", &codigo, &numpecas, &valor_unit);
        valor_total += valor_unit * numpecas;
    }

    // saídas

    printf("VALOR A PAGAR: R$ %.2f", valor_total);
    return 0;
}