#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int *bubbleSortC(int vetor[]) {
    int aux = 0;
    for (int i = 0; i < TAM - 1; i++) { // Esse loop mais externo é o que percorrerá todo o vetor
        for (int j = 0; j < TAM - i - 1 /*A condinção de parada é definida para tal, pois a cada vez que o for finaliza, 
        o maior elemento já estará ordenado, por isso dessa forma evita comparações desnecessárias, mas nada impede de ser
        TAM - 1*/; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    return vetor;
}

int *bubbleSortD(int vetor[]) {
    int aux = 0;
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - i - 1; j++) {
            if (vetor[j] < vetor[j+1]) {
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

    printf("Vetor digitado:\n");
    for(int i = 0; i <TAM; i++) {
        printf("%d ", *(p+i));
    }

    p = bubbleSortC(p);

    printf("\nVetor ordenado de forma crescente:\n");
    for(int i = 0; i <TAM; i++) {
        printf("%d ", *(p+i));
    }

    p = bubbleSortD(p);

    printf("\nVetor ordenado de forma decrescente:\n");
    for(int i = 0; i <TAM; i++) {
        printf("%d ", *(p+i));
    }

    free(p);
    p = NULL;
    return 0;
}
