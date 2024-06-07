#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int bucket[], int n, int max, int m, int toPick, int*cnt) {
	int i, lastIdx, smallest, sum;

	sum = 0;

	if (toPick == 0) { //다 뽑았을 때
		(*cnt) = 0;
		for (i = 0; i < m; i++) {
			sum += (bucket[i] * bucket[i]);
			(*cnt)++;
		}
		//printf("sum: %d, cnt: % d\n", sum, *cnt);
		if (sum == n) {
			return 0;
		}
		return -1;
	} 
	lastIdx = m - toPick - 1;

	if (m == toPick)
		smallest = 1;
	else
		smallest = bucket[lastIdx];

	for (i = smallest; i <= max; i++) {
		bucket[lastIdx + 1] = i; 
		if (pick(bucket, n, max, m, toPick - 1, cnt) == 0) {
			return 0; 
		}
	}
}

int main() {
	int n, i, max, cnt;
	int* bucket;

	scanf("%d", &n);
	cnt = 0;

	for (i = 1; i < n; i++) {
		if (i * i > n) {
			break;
		}
	}
	max = i - 1; //가능한 최대 제곱수

	bucket = (int*)malloc(sizeof(int) * n);

	for (i = 1; i <= n; i++) {
		if (pick(bucket, n, max, i, i, &cnt) == 0) {
			break;
		}
	}
	printf("%d", cnt);
}