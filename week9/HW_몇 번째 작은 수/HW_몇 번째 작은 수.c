#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int * arr, int i, int j) {
	int  temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int A[], int p, int r) {
	int i, j;
	int pivot;
	int t;

	i = p - 1; //시작 바로 왼쪽
	pivot = A[r];

	for (j = p; j < r; j++) {
		if (A[j] < pivot) {
			i++;
			swap(A, i, j);
		}
	}
	i++;
	swap(A, i, r);

	return i; //pivot의 위치를 반환함
}

int quickSort(int* A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int main() {
	int n, i, small, smallNumIdx;
	int arr[100];

	printf("Enter the number of numbers: ");
	scanf("%d", &n);
	printf("몇번째로 작은 수: ");
	scanf("%d", &small);

	for (i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	quickSort(arr, 0, n - 1);

	printf("%d번째 작은 수는 %d", small, arr[small - 1]);

	return 0;
}