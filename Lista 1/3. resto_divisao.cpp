#include <stdio.h>

int main()
{
    int inicial, final;
    scanf("%d %d", &inicial, &final);

    if (inicial > final)
    {
        int temp;
        temp = inicial;
        inicial = final;
        final = temp;
    }

    inicial++;

    int i;

    for (i = inicial; i < final; i++)
    {
        if (i % 5 == 2 || i % 5 == 3)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}