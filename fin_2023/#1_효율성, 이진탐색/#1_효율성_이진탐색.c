#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int m, n, i, cnt;

	scanf("%d", &m);
	int* m_arr = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++) {
		scanf("%d", &m_arr[i]);
	}

	scanf("%d", &n);
	int* n_arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &n_arr[i]);
	}
	

}