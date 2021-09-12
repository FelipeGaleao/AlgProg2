#include <stdio.h>
#define MAX_ALUNOS 100


float calcularMedia(int qtdNotas){
    int i;
    float nota = 0;
    float media = 0;

    for(i = 0; i < qtdNotas; i++){
        scanf("%f", &nota);
        media += nota;
    }
    media = media/qtdNotas;
    return media;
}

void ler_np(float P[MAX_ALUNOS], int n){
    int i;
    for(i = 0; i < n; i++){
       P[i] = calcularMedia(3);
    }
}

void ler_nt(float T[MAX_ALUNOS], int n){
    int i;
    for(i = 0; i < n; i++){
       T[i] = calcularMedia(2);
    }
}


float obterValorMax(float vetor[MAX_ALUNOS], int n){
    int i;
    float maximo = vetor[0];
    for(i = 0; i < n; i++){
        if(maximo < vetor[i]){
            maximo = vetor[i];
        }
    }
    return maximo;
}
float corrigirNotaT(float vetor[MAX_ALUNOS], int vlrMaxNota, int qtd_alunos){
    int i;
    for (i = 0; i < qtd_alunos; i++){
        vetor[i] = (vetor[i]*10)/vlrMaxNota;
    }
}

float corrigirNotaP(float vetor[MAX_ALUNOS], int vlrMaxNota, int qtd_alunos){
    int i;
    for (i = 0; i < qtd_alunos; i++){
        vetor[i] = 1.1*vetor[i];
    }
}

float calcularNotaFinal(float P[MAX_ALUNOS], float T[MAX_ALUNOS], int qtd_alunos){
    int i;
    for(i = 0; i < qtd_alunos; i++){
        P[i] = (P[i]+T[i])/2;
    }
}

void imprimirNotaFinal(float P[MAX_ALUNOS], int qtd_alunos){
    int i;
    for(i = 0; i < qtd_alunos; i++){
        printf("%.1f \n", P[i]);
    }
}

float calcularMedia(float vetor[MAX_ALUNOS], int qtd_alunos){
    int i;
    float soma = 0;
    float media = 0;
    for(i = 0; i < qtd_alunos; i++){
     soma += vetor[i];
    }
    media = soma/qtd_alunos;
    return media;
}
void imprimirNotas(float P[MAX_ALUNOS], int nEstudantes){
    int i;
    for(i = 0; i < nEstudantes; i++){
        printf("%.1f \n", P[i]);
    }
}
int main(){

    int nEstudantes;
    float P[MAX_ALUNOS], T[MAX_ALUNOS], mediaNotaP, mediaNotaT;
    float maxVlrNotaP = 0;
    float maxVlrNotaT = 0;

    scanf("%d", &nEstudantes);
    ler_np(P, nEstudantes);
    ler_nt(T, nEstudantes);

    maxVlrNotaP = obterValorMax(P, nEstudantes);
    maxVlrNotaT = obterValorMax(T, nEstudantes);

    corrigirNotaP(P, maxVlrNotaP, nEstudantes);
    corrigirNotaT(T, maxVlrNotaT, nEstudantes);
    
    maxVlrNotaP = obterValorMax(P, nEstudantes);
    maxVlrNotaT = obterValorMax(T, nEstudantes);
    
    calcularNotaFinal(P, T, nEstudantes);
    

    imprimirNotas(P, nEstudantes);

    printf("Max P: %.1f \n", maxVlrNotaP);
    printf("Max T: %.1f \n", maxVlrNotaT);
    printf("Media P: %.1f \n", calcularMedia(P, nEstudantes));
    printf("Media T: %.1f \n", calcularMedia(T, nEstudantes));


}