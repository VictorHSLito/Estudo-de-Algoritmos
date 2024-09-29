#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int *shellSortC(int vetor[]) {
    for (int gap = TAM/2; gap > 0; gap /= 2) { // Separa o vetor ao "meio" e faz a comparação dos elementos que estão "gap" posições distantes

        for (int i = gap; i < TAM; i++) { // Esse loop começa do meio do vetor até o final, no caso, começará com i = 3 e vai até i = 5
            int temp = vetor[i]; // Pega o elemento na posição 3
            int j;

            /*O segundo loop é o que será responsável por fazer "trocas" dos elementos*/
            for (j = i /*j começa com o valor de i*/; j >= gap && vetor[j - gap] > temp /*Enquanto j for >= 0 e o elemento "gap distante for maior que o temp o loop
            continuará"*/; j -= gap) {
                /*Suponha que o vetor seja [10, 5, 9, 1, 8, 4], inicialmente temp = 1, o elemento [j - gap], ou seja, vetor[0] é 10*/
                vetor[j] = vetor[j - gap];  /*Então o que acontece aqui? O vetor[3] passa a ser 10 e j = 3, mas lembre-se que j é decrementado ao final do for
                passando a valer 0*/
            }

            vetor[j] = temp; // Então como j vale 0, insere 1 na posição 0, depois o processo repete para i = 4 e i = 5

        }
    } // Depois de ter feito para gap = 3, volta-se ao loop inicial e gap passa a valer 1 e repete todo o processo

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
