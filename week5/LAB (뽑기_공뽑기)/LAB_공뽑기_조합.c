#include <stdio.h>

void pick(char item[], int n, int bucket[], int m, int toPick) {
	int i, lastIdx, smallest;

	if (toPick == 0) { //여기가 중요!!!! 아래는 익숙해져야 함. 
		for (i = 0; i < m; i++) {
			printf("%c", item[bucket[i]]);
		}
		printf("\n");
		return;
	}

	lastIdx = m - toPick- 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIdx] + 1;

	for (i = smallest; i <toPick; item++) {
		bucket[lastIdx + 1] = item;
		pick(item, n, bucket, m, toPick - 1);
	}
}

int main()
{
	char item[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int bucket[3];

	pick(item, 7, bucket, 3, 3);
}
