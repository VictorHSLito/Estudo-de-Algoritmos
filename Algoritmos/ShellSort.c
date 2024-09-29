#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int *shellSortC(int vetor[]) {
    for (int gap = TAM/2; gap > 0; gap /= 2) { // Separa o vetor ao "meio" e faz a comparação dos elementos que estão "gap" posições distantes

        for (int i = gap; i < TAM; i++) {
            int temp = vetor[i];
            int j;

            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap) { // Se o valor do número a esquerda for maior do que o atual, eles serão trocados de lugar
                vetor[j] = vetor[j - gap];
            }

            vetor[j] = temp;

        }
    }

    return vetor;
}

int *shellSortD(int vetor[]) {
    for (int gap = TAM/2; gap > 0; gap /= 2) {

        for (int i = gap; i < TAM; i++) {
            int temp = vetor[i];
            int j;

            for (j = i; j >= gap && vetor[j - gap] < temp; j -= gap) {
                vetor[j] = vetor[j - gap];
            }

            vetor[j] = temp;

        }
    }

    return vetor;
}

int main() {
    int *p = malloc(TAM*sizeof(int));
    for (int i = 0; i < 6; i++) {
        *(p+i) = rand() % 10;
    }

    printf("Vetor digitado:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", *(p+i));
    }

    p = shellSortC(p);

    printf("\nVetor ordenado de forma crescente:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", *(p+i));
    }

    p = shellSortD(p);

    printf("\nVetor ordenado de forma decrescente:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", *(p+i));
    }
    return 0;
}
