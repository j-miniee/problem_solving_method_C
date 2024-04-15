#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pick(char sign[], int n, int bucket[], int m, int toPick, int* cnt, char item[]);

int main() {
	int N;
	scanf("%d", &N);

	char sign[2] = { '+','-' };
	int n = 2;

	int* bucket = (int*)malloc(sizeof(int) * N);
	char* item = (char*)malloc(sizeof(char) * (N+1));

	int cnt = 0;
	pick(sign, n, bucket, N, N, &cnt, item);

	printf("%d", cnt);

	free(bucket);
	free(item);
}

void pick(char sign[], int n, int bucket[], int m, int toPick, int* cnt, char item[]) {
	int i, j, lastIdx;

	if (toPick == 0) {
		int sum = 0;

		for (i = 0; i < m; i++) {
			if (sign[bucket[i]] == '+')
				sum += (i + 1);
			else if (sign[bucket[i]] == '-')
				sum -= (i + 1);

			if (sum == m) {
				if ((*cnt) == 0) {
					for (j = 0; j <= i; j++) {
						item[j] = bucket[j] + '0';
					}
					item[j] = '\0';
					(*cnt)++;
					//printf("Ã¹ ¹øÂ°:%s\n", item);
				}
				else {
					char* check = (char*)malloc(sizeof(char) * (m+1));
					for (j = 0; j <= i; j++) {
						check[j] = bucket[j] + '0';
					}
					check[j] = '\0';
					if (strcmp(check, item) != 0) {
						(*cnt)++;
						strcpy(item, check);
						//printf("%s\n", item);
					}
					free(check);
				}
			}
		}

		return;
	}

	lastIdx = m - toPick - 1;


	for (i = 0; i < n; i++) {
		bucket[lastIdx + 1] = i;
		pick(sign, n, bucket, m, toPick - 1, cnt, item);
	}
}