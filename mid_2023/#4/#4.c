#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int inSequence(int a[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		if (a[i] % 2 == 0) {
			int n2 = a[i] / 2;
			//printf("n2 = %d\n", n2);
			if (i + 1 < size) {
				if (a[i + 1] != n2) {
					return 0;
				}
			}
		}
		else {
			int n3 = a[i] * 3 + 1;
			//printf("n3 = %d\n", n3);
			if (i + 1 < size) {
				if (a[i + 1] != n3) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int main() {
	int N;
	int a[1000];

	scanf("%d", &N);
	for (int z = 0; z < 4; z++) {
		for (int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		printf("%d ", inSequence(a, N));
	}
	printf("\n");
}