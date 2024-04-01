#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <stdlib.h>

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int* p = (int*)(malloc)(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int n = p[i];
		while (n != 0) {
			int remainder = n % 10;
			if (remainder == K)
				cnt++;
			n = n / 10;
		}
	}
	printf("%d", cnt);


}