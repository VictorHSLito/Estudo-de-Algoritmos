# Estudo de Algoritmos

## O que são algoritmos? 
Algoritmos são procedimentos computacionais bem definidos que recebem um conjunto de valores como **entrada** e produz algum valor ou um conjunto de valores como **saída**. O que estudaremos aqui serão os algoritmos de ordenação, que tem como fundamento receber um conjunto de dados ordenados ou não e ordená-los conforme o algoritmo foi programado. Nesse README haverão os esboços da implementações desses algoritmos, para maior detalhamendo, recomendo olhar individualmente cada código. 

Dentre os algoritmos de ordenação, podemos classificá-los em três tipos:
- Por Trocas: Realizam trocas entre os elementos
- Por Seleção: Seleciona um elemento, geralmente o maior ou o menor, e o coloca em sua posição
- Por Inserção: Reoderna os elementos, inserindo em suas posições corretas

No estudo de algoritmos, costuma-se usar uma notação matemática chamada de **_Big O_**, essa notação, na computação, tem como serventia descrever e classificar a eficiência de um algoritmo e como ele se comporta em determinadas situações.

O primeiro algoritmo a ser estudado será o **Bubble Sort**, que opera através de trocas.

## [Bubble Sort](https://github.com/VictorHSLito/Estudo-de-Algoritmos/blob/main/Algoritmos/BubbleSort.c)
O Bubble Sort tem como fundamento realizar comparações entre os seus elementos adjacentes e reodená-los repetidas vezes até que todos os elementos estejam em suas devidas posições. Segue um esboço da implementação do Bubble Sort que ordena um vetor de forma crescente:
```
void bubbleSort(int vetor[], int TAM) {
    int aux = 0;
    for (int i = 0; i < TAM - 1; i++) { // Realiza N operações
        for (int j = 0; j < TAM - i - 1; j++) { // Realiza N - i operações
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
```
Se somarmos o número de interações que esse algoritmo faz, chegaremos na seguinte fórmula: N + (N - 1) + (N - 2) + ... + 1 = (N*(N-1))/2. Dizemos então que o algoritmo é de ordem N², ou seja a sua complexidade cresce de forma quadrática. 

| Algoritmo     | Complexidade Média | Complexidade Pior Caso |
| ------------- | ------------------ | ---------------------- |
| Bubble Sort   | O(n²)              | O(n²)                  |

## [Selection Sort](https://github.com/VictorHSLito/Estudo-de-Algoritmos/blob/main/Algoritmos/SelectionSort.c)
A ordenação do Selection Sort é feita através de comparações entre os elementos, buscando entre eles o maior ou menor valor, dependendo de como foi implementado. Esse processo se repete ao longo do programa até que todo o conjunto de dados esteja ordenado. Implementação do algorito que ordena de forma crescente: 
```
void selectionSort(int vetor[], int TAM) {
    int menor, aux;
    for (int i = 0; i < TAM - 1; i++) {
        menor = i;
        for (int j = i + 1; j < TAM; j++) { 
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        
        if (menor != i) {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}
```
Diferente do Bubble Sort, o número de interações do Selection Sort é dado pelo somatório de (N - 1) + (N - 2) + ... + 1 = (N*(N-1))/2, por que começa de N - 1 e não N? Você deve estar se perguntando agora. É simples, como o algoritmo "determina" o menor (ou maior) elemento, a partir da primeira interação do loop, esse elemento já será ordenado na posição correta. Em outras palavras, na primeira iteração, o algoritmo precisa comparar todos os N elementos menos um, ou seja, N - 1 comparações.
Perceba também que apesar desse algoritmo ter uma comparação a menos também é de ordem quadrática. Logo:

| Algoritmo     | Complexidade Média | Complexidade Pior Caso |
| ------------- | ------------------ | ---------------------- |
| Selection Sort   | O(n²)              | O(n²)                  |

## [Insertion Sort](https://github.com/VictorHSLito/Estudo-de-Algoritmos/blob/main/Algoritmos/InsertionSort.c)
O Insertion Sort funciona como se fossem cartas de baralhos sendo ordenadas na mesa, pois o que esse algoritmo faz nada menos é do que passar por cada um dos elementos do vetor, um de cada vez, e compara o elemento atual com os elementos da parte já ordenada do vetor. Em seguida, o elemento é inserido em sua posição correta, movendo os elementos maiores para a direita ou menores para esquerda. Implementação do algoritmo: 
```
void insertionSort(int vetor[], int TAM) {
    int i, j;
    for (i = 1; i < TAM; i++) {
        int aux = vetor[i];
        for (j = i - 1; j >= 0 && aux < vetor[j]; j--) {
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = aux;
    }
}
```
Perceba que esse algoritmo também realiza (N*(N-1))/2 interações, sendo assim mais um algoritmo de ordem quadrática, logo ele também possui os mesmos valores para Big O dos outros dois algoritmos apresentados anteriormente.

| Algoritmo     | Complexidade Média | Complexidade Pior Caso |
| ------------- | ------------------ | ---------------------- |
| Insertoin Sort   | O(n²)              | O(n²)                  |