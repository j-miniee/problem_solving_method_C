#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char item[], int n, int bucket[], int m, int toPick);

int main(void) {
	char sign[2] = { '+', '-' };
	int n = 2;
	int m;
	int* bucket;

	scanf("%d", &m);
	bucket = (int*)malloc(sizeof(int) * m);

	pick(sign, n, bucket, m, m);
}

void pick(char item[], int n, int bucket[], int m, int toPick) {
	int i, lastIdx;
	if (toPick == 0) { //다 뽑았을 때 
		int sum = 0;
		for (i = 0; i < m; i++) {
			if (item[bucket[i]] == '+')
				sum += (i + 1);
			else if (item[bucket[i]] == '-')
				sum -= (i + 1);
		}
		for (i = 0; i < m; i++) {
			printf("%c%d ", item[bucket[i]], i + 1);
		}
		printf("= %d\n", sum);
		return;
	}
	lastIdx = m - toPick - 1;

	for (i = 0; i < n; i++) { //중복순열이라 0부터 시작해야 함.
		bucket[lastIdx + 1] = i; //lastIdx는 현재 뽑아야 하는 위치 계산하기 위해.
		// 	현재 위치에 부호의 인덱스 저장
		pick(item, n, bucket, m, toPick - 1);
	}
}