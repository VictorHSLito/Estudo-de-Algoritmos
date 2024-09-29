#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int *quickSortC(int *ptr, int left, int right) {
    int i, j, aux, meio;
    /*Lembre-se LEFT é passado como argumento formal da função e o seu valor é 0
    RIGHT também é passado como argumento e no exemplo usado vale 4*/
    i = left; 
    j = right;
    meio = ptr[(left + right)/2]; // define o pivo

    do
    {
        while (ptr[i] < meio && i < right) i++; // O loop executa até que ache um elemento MAIOR que o "pivô", i irá percorrer toda a parte esquerda antes do pivo
        while (meio < ptr[j] && j > left) j--; // Depois que o loop de cima termina, esse loop procurará um elemento MENOR que o "pivô", j irá percorrer toda a parte direita depois do pivo

        if (i <= j) { /*Se j for maior que o i, ou seja o elemento na posição i é MAIOR que o da posição J, então precisamos trocá-los de lugar
        *caso o j fosse menor que o i, isso significa que o elemento já está a esquerda do pivô*/ 
            aux = ptr[i];
            ptr[i] = ptr[j];
            ptr[j] = aux;
            i++; j--;
        } // realiza a troca dos elementos e avança os índices, se i ainda for menor que j, volta para os while's
        
    } while (i <= j); // O laço continuará até que i supere j, ou seja, i passe do pivo

    /*Depois de realocar os elementos menores a esquerda do pivo e os maiores a direita, ainda é preciso ordená-los,
    pois não foi feita uma verificação da troca dos elementos, apenas foram trocados de lugar*/

    if (left < j) { // Se o j ainda for maior que left (0), então ocorrerá a chamada recursiva da função para que ordene a parte esquerda do vetor
        quickSortC(ptr, left, j);
    }
    if (i < right) { // Se o i ainda for menor que right (4), então ocorrerá a chamada recursiva da função para que ordene a parte direita do vetor
        quickSortC(ptr, i, right);
    }
    /*Ao final dessas chamadas recursivas o vetor estará completamente ordenado*/
    return ptr;
}

int *quickSortD(int *ptr, int left, int right) {
    int i, j, aux, meio;
    /*Lembre-se LEFT é passado como argumento formal da função e o seu valor é 0
    RIGHT também é passado como argumento e no exemplo usado vale 4*/
    i = left; 
    j = right;
    meio = ptr[(left + right)/2]; // define o pivo

    do
    {
        while (ptr[i] > meio && i < right) i++; // O loop executa até que ache um elemento MAIOR que o "pivô", i irá percorrer toda a parte esquerda antes do pivo
        while (meio > ptr[j] && j > left) j--; // Depois que o loop de cima termina, esse loop procurará um elemento MENOR que o "pivô", j irá percorrer toda a parte direita depois do pivo

        if (i <= j) { /*Se j for maior que o i, ou seja o elemento na posição i é MAIOR que o da posição J, então precisamos trocá-los de lugar
        *caso o j fosse menor que o i, isso significa que o elemento já está a esquerda do pivô*/ 
            aux = ptr[i];
            ptr[i] = ptr[j];
            ptr[j] = aux;
            i++; j--;
        } // realiza a troca dos elementos e avança os índices, se i ainda for menor que j, volta para os while's
        
    } while (i <= j); // O laço continuará até que i supere j, ou seja, i passe do pivo

    /*Depois de realocar os elementos menores a esquerda do pivo e os maiores a direita, ainda é preciso ordená-los,
    pois não foi feita uma verificação da troca dos elementos, apenas foram trocados de lugar*/

    if (left < j) { // Se o j ainda for maior que left (0), então ocorrerá a chamada recursiva da função para que ordene a parte esquerda do vetor
        quickSortD(ptr, left, j);
    }
    if (i < right) { // Se o i ainda for menor que right (4), então ocorrerá a chamada recursiva da função para que ordene a parte direita do vetor
        quickSortD(ptr, i, right);
    }
    /*Ao final dessas chamadas recursivas o vetor estará completamente ordenado*/
    return ptr;
}

int main() {
    int *p = malloc(TAM*sizeof(int));

    for (int i = 0; i < TAM; i++) {
        *(p + i) = rand() % 10;
    }

    printf("Vetor:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", *(p + i));
    }

    p = quickSortC(p, 0, TAM - 1);

    printf("\nVetor ordenado de forma crescente:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", *(p + i));
    }

    p = quickSortD(p, 0, TAM - 1);

    printf("\nVetor ordenado de forma decrescente:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", *(p + i));
    }
    return 0;
}
