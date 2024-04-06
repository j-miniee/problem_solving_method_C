#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int bucket[], int m, int toPick);

int main() {
	//int item[] = { 0, 1, 2, 3 }; index값과 동일하므로 빼겠다.
	int n = 4;
	int m;
	int* bucket;

	scanf("%d", &m);

	bucket = (int*)malloc(sizeof(int) * m);
	pick(n, bucket, m, m);
	free(bucket);
	return 0;
}

void pick(int n, int bucket[], int m, int toPick) {
	int i, lastIdx;
	if (toPick == 0) { //다 뽑았을 때 
		for (i = 0; i < m; i++) {
			printf("%d", bucket[i]);
		}
		printf("\n");
		return;
	}
	lastIdx = m - toPick - 1;

	for (i = 0; i < n; i++) { //중복순열이라 0부터 시작해야 함.
		bucket[lastIdx + 1] = i; //lastIdx는 현재 뽑아야 하는 위치 계산하기 위해.
		pick(n, bucket, m, toPick - 1);
	}
}