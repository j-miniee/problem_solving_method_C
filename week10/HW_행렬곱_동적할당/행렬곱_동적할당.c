#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int** a, int r, int c);
void printMatrix(int** a, int r, int c);
void matrixMultiplication(int** a, int** b, int** x, int x_r, int x_c, int a_c);
void matrixTranspose(int** a, int **c, int a_r, int a_c);

int main() {
	int** a, ** b, ** x, **c;
	int i, a_r, a_c, b_r, b_c;

	printf("��� A�� ��� ���� ����: ");
	scanf("%d %d", &a_r, &a_c); // A�� ��, ��
	printf("��� B�� ��� ���� ����: ");
	scanf("%d %d", &b_r, &b_c);

	//A�� ���� ���� = B�� ���� ����

	a = (int**)malloc(sizeof(int*) * a_r);
	b = (int**)malloc(sizeof(int*) * b_r);
	x = (int**)malloc(sizeof(int*) * a_r);
	c = (int**)malloc(sizeof(int*) * a_c);

	for (i = 0; i < a_r; i++) {
		a[i] = (int*)malloc(sizeof(int) * a_c);
		x[i] = (int*)malloc(sizeof(int) * b_c);
	}
	for (i = 0; i < b_r; i++) {
		b[i] = (int*)malloc(sizeof(int) * b_c);
	}

	for (i = 0; i < a_c; i++) {
		c[i] = (int*)malloc(sizeof(int) * a_r);
	}

	printf("%d x %d ��� A �Է�: \n", a_r, a_c);
	readMatrix(a, a_r, a_c);
	printf("\n");
	printf("%d x %d ��� B �Է�: \n", b_r, b_c);
	readMatrix(b, b_r, b_c);
	printf("\n");

	printf("��İ�: \n");
	matrixMultiplication(a, b, x, a_r, b_c, a_c);
	printMatrix(x, a_r, b_c);
	printf("\n");
	
	printf("��ġ���: \n");
	matrixTranspose(a, c, a_r, a_c);
	printMatrix(c, a_c, a_r);

	for (i = 0; i < a_r; i++) {
		free(a[i]);
		free(x[i]);
	}

	for (i = 0; i < b_r; i++) {
		free(b[i]);
	}

	free(a);
	free(b);
	free(x);

	return 0;
}

void readMatrix(int** a, int r, int c) {
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}

void printMatrix(int** a, int r, int c) {
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void matrixMultiplication(int** a, int** b, int** x, int x_r, int x_c, int a_c) { //A�� ��, B�� ��
	int i, j, k;

	for (i = 0; i < x_r; i++) {
		for (j = 0; j < x_c; j++) {
			x[i][j] = 0;
			for(k = 0; k < a_c; k++)
				x[i][j] += (a[i][k] * b[k][j]);
		}
	}
}

void matrixTranspose(int** a, int **c, int a_r, int a_c) {
	int i, j;

	for (i = 0; i < a_r; i++) {
		for (j = 0; j < a_c; j++) {
			c[j][i] = a[i][j];
		}
	}
}
