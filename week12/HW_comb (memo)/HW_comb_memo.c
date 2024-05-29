#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r, long** M) {
	if (r == 0 || r == n)
		return 1;
	else {
		if (M[n - 1][r - 1] == 0)
			M[n - 1][r - 1] = comb(n - 1, r - 1, M);
		if (M[n - 1][r] == 0)
			M[n - 1][r] = comb(n - 1, r, M);
		return M[n - 1][r - 1] + M[n - 1][r];
	}
}

int main() {
	int n, r, i, j;
	long** M;

	scanf("%d", &n);
	scanf("%d", &r);
	/*n = 32;
	r = 16;*/

	M = (long**)malloc(sizeof(long*) * (n + 1));
	for (i = 0; i <= n; i++) {
		M[i] = (long*)malloc(sizeof(long) * (r + 1));
	}

	for (i = 0; i <= n; i++)
		for (j = 0; j <= r; j++) {
			M[i][j] = 0;
		}

	printf("%ld\n", comb(n, r, M));
	return 0;
}