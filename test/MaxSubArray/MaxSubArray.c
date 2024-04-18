#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max_subarray(int* A, int left, int right);
int	right_max_sum(int* A, int left, int right);
int left_max_sum(int* A, int left, int right);

int main() {
	//int A[] = { -2, 1 ,-3 ,4, -1, 2 ,1 ,-5, 4 };
	int array_size, lastIndex, max, i;
	int* A;
	scanf("%d", &array_size);
	A = (int*)malloc(sizeof(int) * array_size);
	for (i = 0; i < array_size; i++)
		scanf("%d", &A[i]);
	lastIndex = array_size - 1;
	max = max_subarray(A, 0, lastIndex);
	printf("%d\n", max);
	free(A);
	return 0;
	
}
int max_subarray(int* A, int left, int right) {
	if (left == right) {
		return A[left];
	}

	int mid, left_max, right_max, mid_max;

	mid = (left + right) / 2;
	
	left_max = max_subarray(A, left, mid);
	right_max = max_subarray(A, mid + 1, right);
	mid_max = left_max_sum(A, left, mid) + right_max_sum(A, mid + 1, right);

	if (left_max > right_max && left_max > mid_max)
		return left_max;
	else if (right_max > left_max && right_max > mid_max)
		return right_max;
	else
		return mid_max;
}
int	right_max_sum(int* A, int left, int right) {
	int i, max, sum;
	max = A[left];
	sum = A[left];

	for (i = left + 1; i <= right; i++) {
		sum += A[i];
		if (max < sum)
			max = sum;
	}
	return max;
}
int left_max_sum(int* A, int left, int right) {
	int i, max, sum;
	max = A[right];
	sum = A[right];

	for (i = right - 1; i >= left; i--) {
		sum += A[i];
		if (max < sum)
			max = sum;
	}
	return max;

}