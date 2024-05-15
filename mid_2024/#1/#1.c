#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, i, j;
	int arr[100] = { 0 };
	int best[100] = { 0 };
	
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	
	int max = arr[0];
	best[0] = max;
	
	for (j = 1; j < N; j++) {
		if (arr[j] > best[j - 1])
			max = arr[j];
		else
			max = best[j - 1];
		
		//printf("%d", max);

		best[j] = max;
	}


	for (i = 0; i < N; i++) {
		printf("%d ", best[i]);
	}
}