#include <stdio.h>

void pick(int, int, int[], int);

int main() {

	int picked[4];
	pick(7, 4, picked, 4);

	return 0;
}

void pick(int n, int m, int picked[], int toPick) {
	int smallest, lastIdx, i;

	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%d ", picked[i]);
		printf("\n");
		return;
	}

	lastIdx = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = picked[lastIdx] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIdx + 1] = i;
		pick(n, m, picked, toPick - 1);
	}
}
