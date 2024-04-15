#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int* A, int n) {
	int i, j, k, temp;

	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++)
			if (A[i] < A[j])
				break;

		temp = A[i];

		for (k = i; k > j; k--)
			A[k] = A[k - 1];

		A[j] = temp;
	}
}

int main() {
	int* arr;
	int n, i;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 1000; //무작위 함수 생성

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	insertion_sort(arr, n); //선택 정렬함
	/*선택정렬: 가장 큰 값 찾아서 맨 오른쪽으로 보내고,
	다음 루프에서 고려사항 배제시킨다. */

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);
	return 0;
}