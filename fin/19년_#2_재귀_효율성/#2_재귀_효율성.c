#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long memo(int n, long long* m) {
	int i;
	long long sum;

	sum = 0;

	if (n == 1) {
		return 1;
	}
	else {
		for (i = 1; i < n; i++) {
			if (m[n - i] == 0)
				m[n - i] = memo(n - i, m);

			sum += (i * m[n - i]); //���� �߿�: sum += (i * memo(n - i, m));���� �ϸ� �ȵ�
		}
		return sum;
	}
}

int main() {
	int n, i;
	long long* m;

	scanf("%d", &n);

	m = (long long*)malloc(sizeof(long long) * (n + 1));
	for (i = 0; i < n + 1; i++)
		m[i] = 0;

	printf("%lld\n", memo(n, m));

	return 0;
}