/*Esse algoritmo tem como princípio ordenar os valores através de trocas.
Essas trocas são feitas comparando-se um elemento ao seu sucessor,
caso o elemento comparado seja maior que o sucessor, eles serão permutados
até que todo o vetor esteja ordenado.*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int *bubbleSort(int vetor[]) {
    int aux = 0;
    for (int i = 0; i < TAM - 1; i++) { // Esse loop mais externo é o que percorrerá todo o vetor
        for (int j = 0; j < TAM - i - 1 /*A condinção de parada é definida para tal
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
