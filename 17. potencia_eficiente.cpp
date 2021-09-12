#include <cstdio>
#include <cmath>

int potencia(int x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return pow(pow(x, (n / 2)), 2);
    } else {
        return x * pow(x, n-1);
    }
}

int main() {
    printf("teste");
    int x, n;
    scanf("%d %d", &x, &n);
    printf("%d", potencia(x, n));

    return 0;
}