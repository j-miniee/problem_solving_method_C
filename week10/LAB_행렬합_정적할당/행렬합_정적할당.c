#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void readMatrix(int a[][3]);
void matrixAdd(int a[][3], int b[][3], int x[][3]);
void printMatrix(int a[][3]);

int main() {
    int a[3][3], b[3][3], x[3][3];

    printf("��� A �Է�:\n");
    readMatrix(a);

    printf("��� B �Է�:\n");
    readMatrix(b);

    matrixAdd(a, b, x);

    printf("�����:\n");
    printMatrix(x);

    return 0;
}

void readMatrix(int a[][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void matrixAdd(int a[][3], int b[][3], int x[][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            x[i][j] = a[i][j] + b[i][j];
        }
    }
}

void printMatrix(int a[][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}