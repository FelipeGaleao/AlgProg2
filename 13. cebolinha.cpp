#include <stdio.h>
#define MAX 100

int main(){
    char string[MAX];
    scanf("%s", &string);

    int i = 0;
    for(int i = 0 ; string[i] != '\0' ; i++) {

        if(string[i] == 'R'){
            string[i] = 'L';
        }
    i++;
    }
    printf("\n%s", string);

}