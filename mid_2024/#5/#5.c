#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void makeSequence(int a, int* new, int size) {
	int i, num;

	num = a;
	new[0] = num;

	for (i = 1; i < size; i++) {
		if (num % 2 == 0) {
			num = num / 2;
		}
		else {
			num = num * 3 + 1;
		}
		new[i] = num;
	}
}
int checkSequence(int a[], int* new, int size) {
	int a_idx, new_idx;

	for (new_idx = 0; new_idx < size; new_idx++) {
		for (a_idx = 0; a_idx < size; a_idx++) {
			if (new[new_idx] == a[a_idx])
				break;
		}
		if (a_idx == size)
			return 0;
	}
	return 1;
}

void inSequence(int a[], int *new, int size) {
	int i;

	for (i = 0; i < size; i++) {
		makeSequence(a[i], new, size);
		int check = checkSequence(a, new, size);

		if (check == 1) {
			return;
		}
	}
}

int main() {
	int N;
	int a[1000];
	int new[1000];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	inSequence(a, new, N);

	for (int i = 0; i < N; i++) {
		printf("%d ", new[i]);
	}
}