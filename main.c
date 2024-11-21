#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz; // Ponteiro para ponteiro para armazenar a matriz
    int linha, coluna;
    int i, j;

    // Leitura do número de linhas e colunas
    printf("Digite o número de linhas e colunas: ");
    scanf("%d %d", &linha, &coluna);

    // Alocação dinâmica da matriz (array de ponteiros)
    matriz = (int **)malloc(linha * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas.\n");
        return 1;
    }

    // Alocação das colunas para cada linha
    for (i = 0; i < linha; i++) {
        matriz[i] = (int *)malloc(coluna * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para a linha %d.\n", i);
            return 1;
        }
    }

    // Preenchendo a matriz com valores fornecidos pelo usuário
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Exibindo a matriz
    printf("Matriz:\n");
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberando a memória alocada
    for (i = 0; i < linha; i++) {
        free(matriz[i]); // Libera cada linha
    }
    free(matriz); // Libera o array de ponteiros

    return 0;
} 
