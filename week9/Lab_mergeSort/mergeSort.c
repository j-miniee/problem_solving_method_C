#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int* A, int p, int q, int r, int *temp) {//p = 시작, r= 끝
	int i, j, t; //i는 왼쪽 loop, j는 오른쪽 loop, t는 저장하는 곳

	i = p;
	j = q + 1;
	t = p;

	while (1) {
		if (i > q || j > r)
			break; //이런 경우는 탈출시켜서 복사시켜야 함

		if (A[i] < A[j]) {
			temp[t] = A[i++];
		}
		else {
			temp[t] = A[j++];
		}
		t++;
	}

	if (i > q) {//왼쪽 sub가 끝났다 => 오른쪽 sub에 남은 잔여 item 복사
		for (; j <= r; j++, t++) { //j값부터 복사하면 되기 때문에 초기화 할 필요 없다.
			temp[t] = A[j];
		}
	}
	else {
		for (; i <= q; i++, t++) {
			temp[t] = A[i];
		}
	}
	for (i = p; i <= r; i++) { //원복 시키는 코드
		A[i] = temp[i];
	}
}

void mergeSort(int *A, int p, int r, int *temp) {
	if (p < r) {
		int q = (p + 2) / 2;
		mergeSort(A, p, q, temp);
		mergeSort(A, q + 1, r, temp);
		merge(A, p, q, r, temp);
	}
	return;
}

void printList(int A[], int s, int e) {
	int i;
	for (i = s; i <= e; i++) {
		printf("%d", A[i]);
	}
	printf("\n");
}

int main() {
	int* arr, *temp;
	int n, i;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	temp = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 10000;

	printList(arr, 0, n - 1);
	mergeSort(arr, 0, n - 1, temp);
	printList(arr, 0, n - 1);
	
	free(arr);
	free(temp);

	return 0;
}