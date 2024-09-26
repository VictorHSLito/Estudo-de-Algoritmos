#include <stdio.h>

// Função para mesclar dois subarrays de arr[]
void merge(int arr[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Cria arrays temporários
    int L[n1], R[n2];

    // Copia dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    // Mescla os arrays temporários de volta em arr[esquerda..direita]
    i = 0; // Índice inicial de L[]
    j = 0; // Índice inicial de R[]
    k = esquerda; // Índice inicial do subarray mesclado

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort que divide e ordena
void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        // Mescla as duas metades ordenadas
        merge(arr, esquerda, meio, direita);
    }
}

// Função para imprimir um array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    imprimirArray(arr, tamanho);

    mergeSort(arr, 0, tamanho - 1);

    printf("\nArray ordenado: \n");
    imprimirArray(arr, tamanho);

    return 0;
}
