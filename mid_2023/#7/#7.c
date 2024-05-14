#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int code[], int n, int bucket[], int m, int toPick, int* cnt) {
	int i, j, lastIdx, smallest, sum ;

	if (toPick == 0) {
		sum = 0;
		for (i = 0; i < m; i++) {
			sum += code[bucket[i]];
		}
		if (sum == 0) {
			(*cnt)++;
			/*for (i = 0; i < m; i++) {
				printf("%d ", code[bucket[i]]);
			}
			printf("\n");*/
		}
		return;
		
	}

	lastIdx = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIdx] + 1;

	for (i = smallest; i < n; i++) {
		bucket[lastIdx + 1] = i;
		pick(code, n, bucket, m, toPick - 1, cnt);
	}

}

int main() {
	int n, i, cnt;

	scanf("%d", &n);

	int* code = (int*)malloc(sizeof(int) * n);
	int* bucket = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &code[i]);
	}

	cnt = 0;

	for (i = 1; i <= n; i++) {
		pick(code, n, bucket, i, i, &cnt);
	}

	printf("%d", cnt);

	free(code);
	free(bucket);

	return 0;
	
}
