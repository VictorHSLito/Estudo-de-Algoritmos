#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int *selectionSortC(int vetor[]) {
    int menor, aux;
    for (int i = 0; i < TAM - 1; i++) {
        menor = i; // Começa assumindo que o menor é o próprio 'i'
        for (int j = i + 1; j < TAM; j++) { // Busca o menor na parte não ordenada
            if (vetor[j] < vetor[menor]) {
                menor = j; // Atualiza o índice do menor elemento
            }
        }
        // Faz a troca do menor elemento encontrado com o elemento atual 'i'
        if (menor != i) {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
    return vetor;
}

int *selectionSortD(int vetor[]) {
    int maior, aux;
    for (int i = 0; i < TAM - 1; i++) {
        maior = i; // Começa assumindo que o maior é o próprio 'i'
        for (int j = i + 1; j < TAM; j++) { // Busca o maior na parte não ordenada
            if (vetor[maior] < vetor[j]) {
                maior = j; // Atualiza o índice do maior elemento
            }
        }
        // Faz a troca do maior elemento encontrado com o elemento atual 'i'
        if (maior != i) {
            aux = vetor[i];
            vetor[i] = vetor[maior];
            vetor[maior] = aux;
        }
    }
    return vetor;
}

int main() {
    int *p = malloc(TAM * sizeof(int));

    printf("Digite 6 numeros: ");
    for (int i = 0; i < TAM; i++)
    {
       scanf("%d", (p+i));
    }
    
    printf("Vetor digitado: ");
    for (int i = 0; i < TAM; i++)
    {
       printf("%d ", *(p+i));
    }

    p = selectionSortC(p);

    printf("\nVetor ordenado de forma crescente:\n");
    for (int i = 0; i < TAM; i++)
    {
       printf("%d ", *(p+i));
    }

    p = selectionSortD(p);

    printf("\nVetor ordenado de forma decrescente:\n");
    for (int i = 0; i < TAM; i++)
    {
       printf("%d ", *(p+i));
    }

    free(p);
    p = NULL;
    return 0;
}
