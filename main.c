#include <stdio.h>
#include <stdlib.h>

void imprimir_matriz(int **mat, int colunas, int linhas)
{
    if (linhas == 0 || colunas == 0)
    {
        printf("[matriz vazia]");
        return;
    }
    for (int l = 0; l < linhas; l++)
    {
        for (int c = 0; c < colunas; c++)
        {
            printf("%d", mat[l][c]);
            if (c < colunas - 1)
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}

void destroi_matriz(int **mat, int linhas)
{
    for (int l = 0; l < linhas; l++)
        free(mat[l]);
    free(mat);
}

int main()
{

    int lin, col;

    scanf("%d", &lin);
    scanf("%d", &col);

    int **matriz;

    matriz = (int **)malloc(lin * sizeof(int *));
    for (int i = 0; i < lin; i++)
        matriz[i] = (int *)malloc(col * sizeof(int));

    for (int l = 0; l < lin; l++)
    {
        for (int c = 0; c < col; c++)
        {
            scanf("%d", &matriz[l][c]);
        }
    }

    imprimir_matriz(matriz, col, lin);
    destroi_matriz(matriz, lin);

    return 0;
}
