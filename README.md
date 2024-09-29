# Estudo de Algoritmos

## O que são algoritmos? 
Algoritmos são procedimentos computacionais bem definidos que recebem um conjunto de valores como **entrada** e produz algum valor ou um conjunto de valores como **saída**. O que estudaremos aqui serão os algoritmos de ordenação, que tem como fundamento receber um conjunto de dados ordenados ou não e ordená-los conforme o algoritmo foi programado. Nesse README haverão os esboços da implementações desses algoritmos, para maior detalhamendo, recomendo olhar individualmente cada código. 

Dentre os algoritmos de ordenação, podemos classificá-los em três tipos:
- Por Trocas: Realizam trocas entre os elementos
- Por Seleção: Seleciona um elemento, geralmente o maior ou o menor, e o coloca em sua posição
- Por Inserção: Reoderna os elementos, inserindo em suas posições corretas

No estudo de algoritmos, costuma-se usar uma notação matemática chamada de **_Big O_**, essa notação, na computação, tem como serventia descrever e classificar a eficiência de um algoritmo e como ele se comportar em determinadas situações.

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
