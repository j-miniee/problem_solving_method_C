#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long bonacci(int n, long* m) {
	if (n <= 3) {
		return 1;
	}
	else {
		if (m[n - 1] == 0)
			m[n - 1] = bonacci(n - 1, m);
		if (m[n - 2] == 0)
			m[n - 2] = bonacci(n - 2, m);
		if (m[n - 3] == 0)
			m[n - 3] = bonacci(n - 3, m);
		return m[n - 1] + m[n - 2] + m[n - 3];
	}
}

int main() {
	int n, i;
	long* m;

	scanf("%d", &n);

	m = (long*)malloc(sizeof(long) * (n + 1));
	for (i = 0; i < n + 1; i++) {
		m[i] = 0;
	}
	printf("%ld\n", bonacci(n, m));

	return 0;
}