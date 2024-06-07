#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r, long** M) {
	if (r == 0 || r == n)
		return 1;
	else {
		if (M[n - 1][r - 1] == 0)
			M[n - 1][r - 1] = comb(n - 1, r - 1, M);
		if (M[n - 1][r] == 0)
			M[n - 1][r] = comb(n - 1, r, M);
		return M[n - 1][r - 1] + M[n - 1][r];
	}
}


void pick(int arr[], int n, int bucket[], int m, int toPick, int memo[], int* memo_idx) {
	int i, lastIdx, smallest, team1;

	if (toPick == 0) { 
		team1 = 0;
		for (i = 0; i < m; i++) {
			team1 += arr[bucket[i]];
		}
		memo[*memo_idx] = team1;
		(*memo_idx)++;
		return;
	}

	lastIdx = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIdx] + 1;

	for (i = smallest; i < n; i++) { 
		bucket[lastIdx + 1] = i;
		pick(arr, n, bucket, m, toPick - 1, memo, memo_idx);
	}
}

void find_min(int team1, int total, int *min) {
	int team2, differ;

	team2 = total - team1;

	if (team2 > team1) {
		differ = team2 - team1;
	}
	else {
		differ = team1 - team2;
	}

	if ((*min) > differ) {
		(*min) = differ;
	}
}

int main() {
	int n, r, i, j, cnt, memo_idx, total, min;
	int* arr;
	int* bucket; // (n / 2)ÀÇ °ª
	long** M;
	int* memo;
	
	memo_idx = 0;
	total = 0;

	scanf("%d", &n);
	r = n / 2;

	arr = (int*)malloc(sizeof(int) * n);
	bucket = (int*)malloc(sizeof(int) * r);
	M = (long**)malloc(sizeof(long*) * (n + 1));
	for (i = 0; i <= n; i++) {
		M[i] = (long*)malloc(sizeof(long) * (r + 1));
	}
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= r; j++) {
			M[i][j] = 0;
		}
	}
	cnt = comb(n, r, M);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++) {
		total += arr[i];
	}
	min = total;
	
	memo = (int*)malloc(sizeof(int) * cnt);
	for (i = 0; i < cnt; i++) {
		memo[i] = 0;
	}

	pick(arr, n, bucket, r, r, memo, &memo_idx);
	
	for (i = 0; i < cnt; i++) {
		find_min(memo[i], total, &min);
	}

	printf("%d", min);

}