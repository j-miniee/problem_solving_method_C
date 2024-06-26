#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>

void pick(char *item[], int n, int *bucket, int m, int toPick) 
{
	int i, lastIdx, smallest;

	if (toPick == 0) { 
		for (i = 0; i < m; i++) {
			printf("%10s", item[bucket[i]]);
		}
		printf("\n");
		return;
	}

	lastIdx = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIdx] + 1;

	for (i = smallest; i < n; i++) {
		bucket[lastIdx + 1] = i;
		pick(item, n, bucket, m, toPick - 1);
	}
}

int main()
{
	char *item[5] = {"공유", "김수현", "송중기", "지성", "현빈"};

	int n;
	int* bucket;

	printf("인기상 몇명?");
	scanf("%d", &n);

	bucket = (int*)malloc(sizeof(int) * n);

	pick(item, 5, bucket, n, n);
	
	free(bucket);

	return 0;
}																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																