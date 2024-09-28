#include <stdio.h>
#include <stdlib.h>

#define TAM 6

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void criaHeap(int arr[], int n, int i) {
    int maior = i; // Inicializa o maior como raiz
    int esquerda = 2 * i + 1; // Filho da esquerda
    int direita = 2 * i + 2; // Filho da direita

    // Se o filho da esquerda for maior que a raiz
    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    // Se o filho da direita for maior que o maior até agora
    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    // Se o maior não for a raiz
    if (maior != i) {
        troca(&arr[i], &arr[maior]);

        // Recursivamente cria o heap afetado
        criaHeap(arr, n, maior);
    }
}

int *HeapSort(int vet[]) {
    // Constrói o heap (reorganiza o array)
    for (int i = TAM / 2 - 1; i >= 0; i--)
        criaHeap(vet, TAM, i);

    // Extrai um elemento por vez do heap
    for (int i = TAM - 1; i >= 0; i--) {
        // Move a raiz atual para o final
        troca(&vet[0], &vet[i]);

        // Chama a função criaHeap no heap reduzido
        criaHeap(vet, i, 0);
    }
    return vet;
}

int main() {
    int *p = malloc(TAM*sizeof(int));
    
    for (int i = 0; i < TAM; i++) {
        p[i] = rand() % 100;
    }
    printf("Vetor:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", p[i]);
    }

    p = HeapSort(p);

    printf("\nVetor Ordenado:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", p[i]);
    }
    return 0;
}
