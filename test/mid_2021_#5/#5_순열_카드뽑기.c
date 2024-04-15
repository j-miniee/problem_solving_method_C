#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int *card, int n, int *bucket, int m, int toPick, int *cnt);

int main() {
	int n;
	scanf("%d", &n); //ī�� ���� 

	int* card = (int*)malloc(sizeof(int) * n);
	int* bucket = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}
	int cnt = 0;
	pick(card, n, bucket, n, n, &cnt);//ī�� 3�� ������ 2�常 ����

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

	lastIdx = m - toPick - 1; //���� �ֱٿ� ���� ���� ����� ��ġ�� �ε���

	for (i = 0; i < n; i++) { //n=3 (ī�� 3��)
		int flag = 0;
		for (int j = 0; j <= lastIdx; j++) {
			if (i == bucket[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) { //bucket�� ���� �� ������
			bucket[lastIdx + 1] = i;// bucket�� �ε��� �ִ� ��
			pick(card, n, bucket, m, toPick - 1, cnt);
		}
	}
}