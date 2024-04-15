#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void ascending_order(int* arr, int len) {
	int i, j;

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void) {
	int i;
	int N, K;

	scanf("%d", &N);
	scanf("%d", &K);

	int* A = (int*)malloc(sizeof(int) * N); //Na 입력 받은 후에 메모리 할당
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int* B = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	ascending_order(A, N);
	ascending_order(B, N);
	
	int B_Idx = 0;
	for (i = N-K; i < N; i++) {
		B[B_Idx] = A[i];
		B_Idx++;
	}

	/*for (int m = 0; m < N; m++) {
		printf("%d ", B[m]);
	}
	printf("\n");*/

	int total = 0;
	for (i = 0; i < N; i++)
		total += B[i];
	printf("%d", total);

	return 0;
}