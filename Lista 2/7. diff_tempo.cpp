/*
 Dada uma data no formato **dd/mm/aaaa**, escreva um programa que mostre a próxima data, 
 isto é, o dia seguinte à data fornecida.
 */

#include <stdio.h>

int main(void)
{
    struct
    {
        int hora;
        int min;
        int seg;
    } hora1, hora2, hora3;

    scanf("%d:%d:%d", &hora1.hora, &hora1.min, &hora1.seg);
    scanf("%d:%d:%d", &hora2.hora, &hora2.min, &hora2.seg);

    int seg1 = (hora1.hora * 3600) + (hora1.min * 60) + hora1.seg;
    int seg2 = (hora2.hora * 3600) + (hora2.min * 60) + hora2.seg;
    int subtr = seg2 - seg1;

    hora3.hora = subtr / 3600;
    hora3.min = subtr % 3600;
    hora3.min = hora3.min / 60;
    hora3.seg = (subtr % 3600) % 60;

    printf("%02d:%02d:%02d\n", hora3.hora, hora3.min, hora3.seg);

    return 0;
}