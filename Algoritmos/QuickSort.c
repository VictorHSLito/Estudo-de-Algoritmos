#include <stdio.h>
#include <stdlib.h>

int *quickSort(int *ptr, int left, int right) {
    int i, j, aux, meio;

    i = left;
    j = right;
    meio = ptr[(left + right)/2];

    do
    {
        while (ptr[i] < meio && i < right) i++;
        while (meio < ptr[j] && j > left) j--;

        if (i <= j) {
            aux = ptr[i];
            ptr[i] = ptr[j];
            ptr[j] = aux;
            i++; j--;
        }
        
    } while (i <= j);
    if (left < j) {
        quickSort(ptr, left, j);
    }
    if (i < right) {
        quickSort(ptr, i, right);
    }
    return ptr;
}

int main() {
    int *p = malloc(5*sizeof(int));

    for (int i = 0; i < 5; i++) {
        *(p + i) = rand() % 10;
    }

    printf("Vetor:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    p = quickSort(p, 0, 5 -1);
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    return 0;
}
