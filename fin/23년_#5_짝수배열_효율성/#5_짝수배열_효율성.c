#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void find_even_number(int* card, int limit, int len, int* cnt) {
	int i, even;

	even = 0;

	for (i = 0; i < len; i++) {
		if (card[i] % 2 == 0)
			even++;
	}

	if (even >= limit) {
		(*cnt)++;
	}
}

void pick(int* card, int n, int limit, int len, int toPick, int* cnt) {
	int i, lastIdx, smallest, even;

	if (toPick == 0) {
		find_even_number(card, limit, len, cnt);
		return;
	}

	lastIdx = len - toPick - 1; //가장 최근에 뽑힌 수가 저장된 위치의 인덱스

	if (len == toPick)
		smallest = 1;
	else
		smallest = card[lastIdx] + 1;

	for (i = smallest; i <= n; i++) {
		card[lastIdx + 1] = i;
		pick(card, n, limit, len, toPick - 1, cnt);
	}

}

int main() {
	int n, len, limit;

	scanf("%d %d %d", &n, &len, &limit);

	int* card = (int*)malloc(sizeof(int) * len);
	int cnt = 0;
	pick(card, n, limit, len, len, &cnt);

	printf("%d", cnt);

	free(card);
}