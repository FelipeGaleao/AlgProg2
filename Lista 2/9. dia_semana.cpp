/*
 Dada uma data no formato **dd/mm/aaaa**, escreva um programa que mostre a próxima data, 
 isto é, o dia seguinte à data fornecida.
 */

#include <stdio.h>

struct data
{
    int dia;
    int mes;
    int ano;
};

int f(int ano, int mes)
{
    if (mes <= 2)
    {
        return ano - 1;
    }
    else
    {
        return ano;
    }
}

int g(int mes)
{
    if (mes <= 2)
    {
        return mes + 13;
    }
    else
    {
        return mes + 1;
    }
}

int computaN(data d1)
{
    int N = ((1461 * f(d1.ano, d1.mes)) / 4) + ((153 * g(d1.mes)) / 5) + d1.dia;
    return N;
}

int main(void)
{
    data data1;

    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);

    int n1 = computaN(data1);
    int d = ((n1 - 621049) % 7)-1;
    switch(d){
        case 0:
            printf("domingo");
            break;
        case 1:
            printf("terca-feira");
            break;
        case 2:
            printf("quarta-feira");
            break;
        case 3:
            printf("quinta-feira");
            break;
        case 4:
            printf("sexta-feira");
            break;
        case 5:
            printf("sabado");
            break;
        case 6:
            printf("domingo");
            break;
    }
    printf("%d\n", d);
    return 0;
}