#include <stdio.h>

#define R 4
#define C 5

typedef struct {
    int row;
    int col;
    int value;
} Element;

void sparseToCompact(int matris[R][C]) {
    int nonZeroCount = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matris[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    Element sparseMatrix[nonZeroCount];
    int k = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matris[i][j] != 0) {
                sparseMatrix[k].row = i;
                sparseMatrix[k].col = j;
                sparseMatrix[k].value = matris[i][j];
                k++;
            }
        }
    }

    printf("Satir\tSutun\tDeger\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
    }
}

int main() {
    int matris[R][C] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    sparseToCompact(matris);

    return 0;
}