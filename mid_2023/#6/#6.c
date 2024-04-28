#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

pick(int item[], int bucket[], int N, int M, int toPick, int* cnt) {
	int i, lastIdx, smallest;


	if (toPick == 0) {
		int sum = 0;

		for (i = 0; i < M; i++) {
			//printf("%d ", bucket[i]);
			sum += bucket[item[i]];
		}

		if (sum == 0)
			(*cnt)++;

		return;
	}

	lastIdx = M - toPick - 1;

	if (M == toPick)
		smallest = 0;
	else
		smallest = item[lastIdx] + 1;

	for (i = smallest; i < N; i++) {
		item[lastIdx + 1] = i;//item은 인덱스 담는 곳
		pick(item, bucket, N, M, toPick - 1, cnt);
	}

}

int main() {
	int N, M;
	int* bucket;
	int* item;
	int cnt = 0;

	scanf("%d", &N);
	scanf("%d", &M);

	bucket = (int*)malloc(sizeof(int) * N);
	item = (int*)malloc(sizeof(int) * M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &bucket[i]);
	}

	pick(item, bucket, N, M, M, &cnt);

	printf("%d", cnt);
}

