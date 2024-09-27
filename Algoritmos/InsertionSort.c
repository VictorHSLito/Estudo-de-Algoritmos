/*Esse algoritmo tem como princípio ordenar os valores através de inserções.
Essas inserções são feitas buscando o "lugar" correto do elemento e reordenando
todos os outros para outras posições. O código abaixo procura colocar o elemento
na posição correta e reoderna todos os outros uma posição a frente.*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int* insertionSort(int vetor[]) {
    int i, j;
    for (i = 1; i < TAM; i++) { // Começa a partir do segundo elemento até o final do vetor
        int aux = vetor[i];
        for (j = i - 1 /*Começa sempre um elemento antes*/; j >= 0 && aux < vetor[j] /*Analisa se o elemento antes é maior
        que o elemento do primeiro for*/; j--) { 
            vetor[j+1] = vetor[j]; // Desloca todos os elementos para uma posição a direita que são maiores que o aux
        }
        vetor[j+1] = aux; // armazena o elemento na posição correta
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

    p = insertionSort(p);

    printf("\nVetor ordenado: \n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", *(p+i));
    }
    return 0;
}
