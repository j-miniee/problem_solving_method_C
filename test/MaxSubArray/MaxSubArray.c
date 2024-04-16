#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max_subarray(int* A, int left, int right);

int main() {
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	int lastIndex = sizeof(A) / sizeof(int) - 1; //마지막 요소의 인덱스
	int max = max_subarray(A, 0, lastIndex);//max = 6
	printf("max value = %d\n", max);
	
}
int max_subarray(int* A, int left, int right) {
	int i, max, sum, mid;
	mid = (left + right) / 2;
	max = A[mid];
	sum = A[mid];

	for(i = mid; i < )

}