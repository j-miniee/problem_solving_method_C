#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long H(int n, long long* m) {
	if (n < 2)
		return 1;
	else {

		long long ret = 0;
		int i;
		
		if (m[n] == 0) {
			for (i = 0; i < n; i++)
				ret = ret + H(i, m) * H(n - i - 1, m);
			m[n] = ret;
		}
		return m[n];
	}
}

int main() {
	int n, i;
	long long* m;


	scanf("%d", &n);

	m = (long long*)malloc(sizeof(long long) * (n + 1));
	for (i = 0; i < n + 1; i++)
		m[i] = 0;
	printf("%lld\n", H(n, m));

	return 0;

}