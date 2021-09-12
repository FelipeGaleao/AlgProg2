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
    int N = (1461 * f(d1.ano, d1.mes)) / 4 + (153 * g(d1.mes)) / 5 + d1.dia;
    return N;
}

int main(void)
{
    data data1, data2;

    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

    int n1 = computaN(data1);
    int n2 = computaN(data2);

    printf("%d\n", n2 - n1);
    return 0;
}