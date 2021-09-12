#include <stdio.h>

void ciclo(int n)
{

	while (n != 1)
	{
		printf("%i >> ", n);

		if (n & 1)
			n = 3*n + 1;

		else
			n = n/2;
	}
	printf("%i ", n);
}

int incrementarR(int n){
    return 3*n + 1;
}
int dividirR(int n){
    return n/2;
}
void cicloR(int n)
{

	while (n != 1)
	{
		printf("%i >> ", n);

		if (n & 1)
			n = incrementarR(n);

		else
			n = dividirR(n);
	}
	printf("%i \n", n);
}

int main()
{
    int vlrCicloInicial;
    scanf("%i", &vlrCicloInicial);
	ciclo(vlrCicloInicial);
    cicloR(vlrCicloInicial);
    getchar();
    getchar();
    return 0;
}
