#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void find_max(int* bucket, char* str1, char* str2, int len1, int len2, int* max) {
	int i, sum, b_idx, n1, n2;
	char* a1 = (char*)malloc(sizeof(char) * len1);
	char* a2 = (char*)malloc(sizeof(char) * len2);

	for (i = 0; i < len1; i++) {
		b_idx = str1[i] - 'A';
		a1[i] = bucket[b_idx] + '0';
	}
	a1[i] = '\0';
	n1 = atoi(a1);

	for (i = 0; i < len2; i++) {
		b_idx = str2[i] - 'A';
		a2[i] = bucket[b_idx] + '0';
	}
	a2[i] = '\0';
	n2 = atoi(a2);

	sum = n1 + n2;

	if (sum > *max) {
		(*max) = sum;
	}

}

void pick(int* bucket, int n, int m, int toPick, char* str1, char* str2, int len1, int len2, int* max) {
	int i, lastIdx;

	if (toPick == 0) {
		find_max(bucket, str1, str2, len1, len2, max);
		return;
	}

	lastIdx = m - toPick - 1; //가장 최근에 뽑힌 수가 저장된 위치의 인덱스

	for (i = 1; i <= n; i++) {
		int flag = 0;
		for (int j = 0; j <= lastIdx; j++) {
			if (i == bucket[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) { //bucket에 같은 수 없으면
			bucket[lastIdx + 1] = i;// bucket은 인덱스 넣는 곳
			pick(bucket, n, m, toPick - 1, str1, str2, len1, len2, max);
		}
	}
}

int main() {
	char str1[100], str2[100];
	int len1, len2, max = 0;
	int n = 5;
	int m = 5;

	scanf("%s", str1);
	scanf("%s", str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	int* bucket = (int*)malloc(sizeof(int) * m);

	pick(bucket, n, m, m, str1, str2, len1, len2, &max);

	printf("%d", max);

}