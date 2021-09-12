#include <stdio.h>
#define MAX 100

int main(){
    char string[MAX];
    char string_temp[MAX];
    scanf("%s", &string);
    int k = 0;
    for(int i = 0 ; string[i] != '\0' ; i++) {

        string_temp[k] = string[i];
        if (string_temp[k] == 'R'){
            string_temp[k] = 'L';
            if (string[i+1] == 'R'){
                i++;
            }
        }
    k++;
    }
    string_temp[k]='\0';
    printf("\n%s", string_temp);

}