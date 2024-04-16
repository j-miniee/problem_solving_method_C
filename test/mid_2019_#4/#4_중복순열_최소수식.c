#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char sign[], int n, int bucket[], int m, int toPick, int* cnt, int item);

int main() {
	int N;
	scanf("%d", &N);

	char sign[2] = { '+','-' };
	int n = 2;

	int* bucket = (int*)malloc(sizeof(int) * N);

	int cnt = 0;
	for(int i = 1; i <= N; i++)
		pick(sign, n, bucket, i, i, &cnt, N);

	printf("%d", cnt);

	free(bucket);
}

void pick(char sign[], int n, int bucket[], int m, int toPick, int* cnt, int item) {
	int i, j, lastIdx;

	if (toPick == 0) {
		int sum = 0;

		for (i = 0; i < m; i++) {
			if (sign[bucket[i]] == '+')
				sum += (i + 1);
			else if (sign[bucket[i]] == '-')
				sum -= (i + 1);
		}
		if (sum == item)
			(*cnt)++;
		return;
	}

	lastIdx = m - toPick - 1;


	for (i = 0; i < n; i++) {
		bucket[lastIdx + 1] = i;
		pick(sign, n, bucket, m, toPick - 1, cnt, item);
	}
}