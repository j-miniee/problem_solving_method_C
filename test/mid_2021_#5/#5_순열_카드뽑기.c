#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int *card, int n, int *bucket, int m, int toPick, int *cnt);

int main() {
	int n;
	scanf("%d", &n); //카드 개수 

	int* card = (int*)malloc(sizeof(int) * n);
	int* bucket = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}
	int cnt = 0;
	pick(card, n, bucket, n, n, &cnt);//카드 3장 있으면 2장만 뽑음

	printf("%d", cnt);

	free(card);
	free(bucket);

}

void pick(int *card, int n, int *bucket, int m, int toPick, int *cnt) {
	int i, lastIdx;

	if (toPick == 0) {
		int sum = 0;
		for (i = 0; i < m - 1; i++) {
			sum = sum * 10 + card[bucket[i]];
		}

		if (sum % card[bucket[i]] == 0)
			(*cnt)++;
		
		return;
	}

	lastIdx = m - toPick - 1; //가장 최근에 뽑힌 수가 저장된 위치의 인덱스

	for (i = 0; i < n; i++) { //n=3 (카드 3장)
		int flag = 0;
		for (int j = 0; j <= lastIdx; j++) {
			if (i == bucket[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) { //bucket에 같은 수 없으면
			bucket[lastIdx + 1] = i;// bucket은 인덱스 넣는 곳
			pick(card, n, bucket, m, toPick - 1, cnt);
		}
	}
}