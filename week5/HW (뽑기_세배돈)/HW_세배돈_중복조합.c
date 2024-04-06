#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int item[], int n, int bucket[], int m, int toPick, int target_money);

int main(void) {
	int money[] = { 1000, 5000, 10000, 0 }; //나머지는 0으로 채워
	int target_money, m;
	int* bucket;

	scanf("%d", &target_money);
	m = target_money / 1000;
	bucket = (int*)malloc(sizeof(int) * m);

	pick(money, 4, bucket, m, m, target_money);
	free(bucket);
	return 0;
}

void pick(int item[], int n, int bucket[], int m, int toPick, int target_money) {
	int i, lastIdx, smallest;
	if (toPick == 0) { //다 뽑았을 때 	
		int sum = 0;
		for (i = 0; i < m; i++) {
			if (item[bucket[i]] != 0)
				sum += item[bucket[i]];
		}
		if (sum == target_money) { //출력만 안하는거지, 6000원이 아닌 모든 경우를 구하고 있음.
			for (i = 0; i < m; i++) {
				if (item[bucket[i]] != 0)
					printf("%d ", item[bucket[i]]);
			}
			printf("\n");
		}
		return;
	} //pick을 호출하지 않아도 되는 부분 어떻게 코드 짤 것인지.?!
	lastIdx = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIdx];

	for (i = smallest; i < n; i++) { //중복조합은 마지막에 뽑히는 얘 알고, 후보 아이템의 min 값 담을 변수 필요.
		bucket[lastIdx + 1] = i; //lastIdx는 현재 뽑아야 하는 위치 계산하기 위해.
		pick(item, n, bucket, m, toPick - 1, target_money);
	}
}