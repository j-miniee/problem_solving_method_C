#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int* A, int p, int q, int r, int *temp) {//p = ����, r= ��
	int i, j, t; //i�� ���� loop, j�� ������ loop, t�� �����ϴ� ��

	i = p;
	j = q + 1;
	t = p;

	while (1) {
		if (i > q || j > r)
			break; //�̷� ���� Ż����Ѽ� ������Ѿ� ��

		if (A[i] < A[j]) {
			temp[t] = A[i++];
		}
		else {
			temp[t] = A[j++];
		}
		t++;
	}

	if (i > q) {//���� sub�� ������ => ������ sub�� ���� �ܿ� item ����
		for (; j <= r; j++, t++) { //j������ �����ϸ� �Ǳ� ������ �ʱ�ȭ �� �ʿ� ����.
			temp[t] = A[j];
		}
	}
	else {
		for (; i <= q; i++, t++) {
			temp[t] = A[i];
		}
	}
	for (i = p; i <= r; i++) { //���� ��Ű�� �ڵ�
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