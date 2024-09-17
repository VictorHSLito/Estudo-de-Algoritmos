#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int *bubbleSort(int vetor[]) {
    int aux = 0;
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - i - 1 /*A condinção de para é definida para tal
        pois evita comparações desnecessárias, mas nada impede de ser TAM - 1*/; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    return vetor;
}

int main() {
    int *p = malloc(TAM*sizeof(int));
    
    printf("Digite 6 numeros: ");
    for (int i = 0; i < TAM; i++) {
        scanf("%d", (p+i));
    }

    printf("Vetor digitado: ");
    for(int i = 0; i <TAM; i++) {
        printf("%d ", *(p+i));
    }

    p = bubbleSort(p);

    printf("\nVetor ordenado: ");
    for(int i = 0; i <TAM; i++) {
        printf("%d ", *(p+i));
    }

    free(p);
    p = NULL;
    return 0;
}
