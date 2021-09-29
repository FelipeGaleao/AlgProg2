#include <cstdio>

double harmonica(int n) {
    if(n == 1){
        return 1;
    } else {
        return (float)1/n + harmonica(n - 1);
    }

}
    
int main(){
    float serie_harmonica;
    int n;
    scanf("%d", &n);
    serie_harmonica = harmonica(n);
    printf("%f", serie_harmonica);
    return 0;
    
}