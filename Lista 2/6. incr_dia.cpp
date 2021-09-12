/*
 Dada uma data no formato **dd/mm/aaaa**, escreva um programa que mostre a próxima data, 
 isto é, o dia seguinte à data fornecida.
 */

#include <stdio.h>

int main(void)
{

    struct
    {
        int dia;
        int mes;
        int ano;
    } data1, data2;

    printf("Insira a data. Ex: 30/06/2011 \n");
    scanf("%i/%i/%i", &data1.dia, &data1.mes, &data1.ano);

    data2 = data1;

    bool tem30Dias = (data2.mes == 4 || data2.mes == 6 || data2.mes == 9 || data2.mes == 11);

    bool ehBissexto = (data2.ano % 400 == 0 || (data2.ano % 4 == 0 && data2.ano % 100 != 0));

    data2.dia++;

    if (data2.dia == 32)
    {
        data2.dia = 1;
        data2.mes++;
    }

    else if (data2.dia == 31 && tem30Dias == true)
    {
        data2.dia = 1;
        data2.mes++;
    }

    else if (data2.dia == 29 && data2.mes == 2 && ehBissexto == false)
    {
        data2.dia = 1;
        data2.mes++;
    }
    else if (data2.dia == 30 && data2.mes == 2)
    {
        data2.dia = 1;
        data2.mes++;
    }

    if (data2.mes == 13)
    {
        data2.mes = 1;
        data2.ano++;
    }

    printf("%02d/%02d/%04d\n", data2.dia, data2.mes, data2.ano);
    return 0;
}