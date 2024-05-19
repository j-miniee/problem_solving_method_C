#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* arr, int i, int j) {
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
	swap(A, i, j);

	return i; //pivot의 위치를 반환함
}

int quickSort(int *A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void printList(int A[], int s, int e) {
	int i;

	for (i = s; i < e; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main() {
	int* arr;
	int n, i;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	
	srand(time(NULL));

	for (i = 0; i < n; i++) 
		arr[i] = rand() % 100;

	printList(arr, 0, n);
	quickSort(arr, 0, n - 1);
	printList(arr, 0, n);
	
	free(arr);

	return 0;
}