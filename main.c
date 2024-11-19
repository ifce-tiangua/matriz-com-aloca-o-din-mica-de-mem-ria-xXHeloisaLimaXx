#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz;
    int linha, coluna;
    int i, j;

    scanf("%d", &linha);
    scanf("%d", &coluna);

    matriz = (int **)malloc(linha * sizeof(int *));
    for (i = 0; i < linha; i++) {
        matriz[i] = (int *)malloc(coluna * sizeof(int));
    }

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            printf("%d", matriz[i][j]);
            if (j < coluna - 1) {
                printf(" ");
            }
        }
        if ( linha == 1) {
            printf("\\n");
        }
    }

    for (i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}