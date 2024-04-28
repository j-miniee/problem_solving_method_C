#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*void pick(char sign[], int n, int item[], int bucket[], int m, int toPick, int* cnt);

int main() {
	int stu;
	scanf("%d", &stu);

	char sign[3] = { '+','-', '0'};
	int n = 3;

	int* money = (int*)malloc(sizeof(int) * stu);
	int* bucket = (int*)malloc(sizeof(int) * stu);

	for (int i = 0; i < stu; i++) {
		scanf("%d", &money[i]);
	}

	int cnt = 0;
	pick(sign, n, money, bucket, stu, stu, &cnt);

	printf("%d", cnt);

	free(money);
	free(bucket);
}

void pick(char sign[], int n, int item[], int bucket[], int m, int toPick, int *cnt) {
	int i, lastIdx;

	if (toPick == 0) {
		int sum = 0;

		for (i = 0; i < m; i++) {
			if (sign[bucket[i]] == '+')
				sum += item[i];
			else if (sign[bucket[i]] == '-')
				sum -= item[i];
			else if (sign[bucket[i]] == '0')
				sum += 0;
		}

		if (sum == 0) {
			(*cnt)++;
		}

		return;
	}

	lastIdx = m - toPick - 1;

	for (i = 0; i < n; i++) {
		bucket[lastIdx + 1] = i;
		pick(sign, n, item, bucket, m, toPick - 1, cnt);
	}
	
}
*/
int pick(char item[], int n, int bucket[], int m, int toPick, int* money);

int main() {
	char sign[] = { '+', '-', '0' };
	int* money;
	int n, i;
	int* bucket;

	scanf("%d", &n);

	money = (int*)malloc(sizeof(int) * n);
	bucket = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &money[i]);

	printf("%d\n", pick(sign, 3, bucket, n, n, money));

	free(bucket);
	return 0;
}

int pick(char item[], int n, int bucket[], int m, int toPick, int* money) {
	int i, lastIndex, count;
	if (toPick == 0) {
		int sum = 0;
		/*for(i=0; i<m; i++) {
			printf("%c ", item[bucket[i]]);
		}
		printf("\n");*/

		for (i = 0; i < m; i++) {
			if (item[bucket[i]] == '+')
				sum = sum + money[i];
			else if (item[bucket[i]] == '-')
				sum = sum - money[i];
		}

		if (sum == 0) {
			for (i = 0; i < m; i++) {
				printf("%c%d ", item[bucket[i]], i + 1);
			}
			printf("=%d\n", sum);
			return 1;
		}
		return 0;
	}

	lastIndex = m - toPick - 1;

	count = 0;
	for (i = 0; i < n; i++) {
		bucket[lastIndex + 1] = i;
		count = count + pick(item, n, bucket, m, toPick - 1, money);
	}

	return count;
}