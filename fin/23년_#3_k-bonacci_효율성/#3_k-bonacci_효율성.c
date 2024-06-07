#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long bonacci(int n, int k, long* m) {
	int i;
	long sum = 0;

	if (n <= k) {
		return 1;
	}
	else {
		for (i = 1; i <= k; i++) {
			if (m[n - i] == 0)
				m[n - i] = bonacci(n - i, k, m);

			sum += m[n - i];
		}
		return sum;
	}
}

int main() {
	int n, k, i;
	long* m;

	scanf("%d", &n);
	scanf("%d", &k);

	m = (long*)malloc(sizeof(long) * (n + 1));
	for (i = 0; i < n + 1; i++)
		m[i] = 0;

	printf("%ld\n", bonacci(n, k, m));

	return 0;
}
