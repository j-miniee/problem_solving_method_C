#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int get_reverse_number(int n, int* arr) {
	int count = 0;
	int number, i;

	number = n;
	while (number != 0) {
		count++;
		number = number / 10;
	}

	return count; //자리수 반환
}

int main() {
	int N, K, i;
	int digit = 0;
	int reverse_number[10] = { 0 };

	scanf("%d", &N);
	scanf("%d", &K);

	for (i = K; i < N; i += K) {
		digit +=  get_reverse_number(i, reverse_number);
	}

	printf("%d", digit);

}
