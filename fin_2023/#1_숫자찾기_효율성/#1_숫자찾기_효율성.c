#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* A, int n) {
	int i, j, k, temp;

	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++)
			if (A[i] < A[j])
				break;

		temp = A[i];

		for (k = i; k > j; k--)
			A[k] = A[k - 1];

		A[j] = temp;
	}
}

int check(int* m_arr, int* n_arr, int m, int n, int* cnt) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (n_arr[i] == m_arr[j]) {
				(*cnt)++;
				break;
			}
		}
	}

}

int main() {
	int m, n, i, cnt = 0;

	scanf("%d", &m);
	int* m_arr = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++) {
		scanf("%d", &m_arr[i]);
	}
	insertion_sort(m_arr, m);

	scanf("%d", &n);
	int* n_arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &n_arr[i]);
	}
	insertion_sort(n_arr, n);

	check(m_arr, n_arr, m, n, &cnt);
	printf("%d", cnt);

	free(m_arr);
	free(n_arr);

	return 0;
}