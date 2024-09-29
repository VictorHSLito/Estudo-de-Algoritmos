#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int* insertionSortC(int vetor[]) {
    int i, j;
    for (i = 1; i < TAM; i++) { // Começa a partir do segundo elemento até o final do vetor
        int aux = vetor[i];
        for (j = i - 1 /*Começa sempre um elemento antes*/; j >= 0 && aux < vetor[j] /*Analisa se o elemento antes é maior
        que o elemento do primeiro for*/; j--) {  /*Esse loop fica rodando até que ache um elemento maior que o aux*/
            vetor[j+1] = vetor[j]; // Desloca todos os elementos para uma posição a direita que são maiores que o aux
        }
        vetor[j+1] = aux; /*Você deve estar se perguntando, por que j + 1 e não j? A resposta é porque quando o laço for
        termina a sua execução ele é decrementado mais uma única vez para ser comparado com a condição de parada. Esse é
        o motivo para ser j + 1*/ 
    }

    return vetor;
}

int* insertionSortD(int vetor[]) {
    int i, j;
    for (i = 1; i < TAM; i++) { // Começa a partir do segundo elemento até o final do vetor
        int aux = vetor[i];
        for (j = i - 1 /*Começa sempre um elemento antes*/; j >= 0 && aux > vetor[j]/*Analisa se o elemento antes é menor
        que o elemento do primeiro for*/; j--) {  /*Esse loop fica rodando até que ache um elemento menor que o aux*/
            vetor[j+1] = vetor[j]; // Desloca todos os elementos para uma posição a direita que são menores que o aux
        }
        vetor[j+1] = aux; 
    }

    return vetor;
}

int main() {
    int *p = (int*) malloc(TAM*sizeof(int));

    printf("Digite 6 valores: ");
    for (int i = 0; i < TAM; i++) {
        scanf("%d", (p+i));
    }
    
    printf("Vetor digitado: \n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", *(p+i));
    }

    p = insertionSortC(p);

    printf("\nVetor ordenado de forma crescente: \n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", *(p+i));
    }
    p = insertionSortD(p);

    printf("\nVetor ordenado de forma decrescente: \n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", *(p+i));
    }
    return 0;
}
