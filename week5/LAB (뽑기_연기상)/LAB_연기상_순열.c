#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>

void pick(char* item[], int n, int* bucket, int m, int toPick)
{
	int i, lastIdx;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			printf("%10s", item[bucket[i]]);
		}
		printf("\n");
		return;
	}

	lastIdx = m - toPick - 1;

	for (i = 0; i < n; i++) {
		int j = 0;
		int flag = 0;
		for (j = 0; j <= lastIdx; j++) {
			if (item[bucket[j]] == item[i])
				flag = 1;
		}
		if (flag == 1)
			continue;
		bucket[lastIdx + 1] = i;
		pick(item, n, bucket, m, toPick - 1);
	}
}

int main()
{
	char* item[5] = { "공유", "김수현", "송중기", "지성", "현빈" };

	int n;
	int* bucket;

	printf("상의 종류는? ");
	scanf("%d", &n);

	for (int j = 1; j <= n; j++) {
		printf("\t상 %d", j);
	}
	printf("\n");

	bucket = (int*)malloc(sizeof(int) * n);

	pick(item, 5, bucket, n, n);

	free(bucket);

	return 0;
}