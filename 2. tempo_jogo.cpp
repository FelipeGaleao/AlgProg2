/*
Leia a hora inicial e a hora final de um jogo. A seguir calcule a duração do jogo,
sabendo que o mesmo pode começar em um dia e terminar em outro, 
tendo uma duração mínima de 1 hora e máxima de 24 horas.
*/

#include <stdio.h>

int main()
{
    int hora_inicio, hora_fim, valor_temp;

    scanf("%d %d", &hora_inicio, &hora_fim);

    if (hora_fim < hora_inicio)
    {
        valor_temp = 24 - hora_inicio;
        valor_temp = valor_temp + hora_fim;
    }

    if (hora_inicio == hora_fim)
    {
        valor_temp = 24;
    }

    if (hora_fim > hora_inicio)
    {
        valor_temp = hora_fim - hora_inicio;
    }

    printf("O JOGO DUROU %d HORA(S)", valor_temp);
    return 0;
}