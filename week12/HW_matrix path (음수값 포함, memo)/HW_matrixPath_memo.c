#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int mat_opt1(int** matrix, int i, int j, int** M, int** check) {
	if (i == 0 && j == 0)
		return matrix[0][0];

	else if (i == 0) { //천장
		if (check[i][j - 1] == 0)
			M[i][j - 1] = mat_opt1(matrix, i, j - 1, M, check);
		check[i][j] = 1;
		return M[i][j - 1] + matrix[i][j];
	}
	else if (j == 0) { //왼쪽 벽
		if (check[i - 1][j] == 0)
			M[i - 1][j] = mat_opt1(matrix, i - 1, j, M, check);
		check[i][j] = 1;
		return M[i - 1][j] + matrix[i][j];
	}
	else {
		if (check[i][j - 1] == 0)
			M[i][j - 1] = mat_opt1(matrix, i, j - 1, M, check);

		if (check[i - 1][j] == 0)
			M[i - 1][j] = mat_opt1(matrix, i - 1, j, M, check);
		check[i][j] = 1;
		return ((M[i][j - 1] < M[i - 1][j]) ? M[i][j - 1] : M[i - 1][j]) + matrix[i][j];
	}
}

int main() {
	int** m, ** M, **check, i, j;
	int r, c;
	r = 4; c = 4;

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	check = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
		check[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < r; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;//얘가 memo 역할
			check[i][j] = 0; // 방문했던건지 확인
		}

	printf("%d\n", mat_opt1(m, r - 1, c - 1, M, check));
	return 0;
}