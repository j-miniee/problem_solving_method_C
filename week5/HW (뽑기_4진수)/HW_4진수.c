#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int bucket[], int m, int toPick);

int main() {
	//int item[] = { 0, 1, 2, 3 }; index���� �����ϹǷ� ���ڴ�.
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
	if (toPick == 0) { //�� �̾��� �� 
		for (i = 0; i < m; i++) {
			printf("%d", bucket[i]);
		}
		printf("\n");
		return;
	}
	lastIdx = m - toPick - 1;

	for (i = 0; i < n; i++) { //�ߺ������̶� 0���� �����ؾ� ��.
		bucket[lastIdx + 1] = i; //lastIdx�� ���� �̾ƾ� �ϴ� ��ġ ����ϱ� ����.
		pick(n, bucket, m, toPick - 1);
	}
}