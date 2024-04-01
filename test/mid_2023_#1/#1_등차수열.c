#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <stdlib.h>

int main() {
	int N;
	int* p;
	scanf("%d", &N);
	p = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}
	int differ = p[1]-p[0];
	for (int i = 2; i < N; i++) {
		int check = p[i] - p[i - 1];
		if (check != differ) {
			printf("0");
			free(p);
			return 0;
		}
	}
	printf("1");
	free(p);
	return 0;
}
