#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int* insertionSort(int vetor[]) {
    int i, j;
    for (i = 1; i < TAM; i++) {
        int aux = vetor[i];
        for (j = i - 1; j >= 0 && aux < vetor[j]; j--) {
            vetor[j+1] = vetor[j];
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

    p = insertionSort(p);

    printf("\nVetor ordenado: \n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", *(p+i));
    }
    return 0;
}
