#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void inSequence(int a[], int new[], int size) {
	int i, j, lastIdx;
	int new_idx;

	for(i = 0; i <size; i++ ){
		int flag = 1;
		new_idx = 0;
		new[new_idx++] = a[i];
		
		//printf("a = %d, i = %d\n", a[i], i);
		while (new_idx < size) {
			if (new[new_idx - 1] % 2 == 0) {
				int n2 = a[i] / 2;

				for (int k = 0; k < size; k++) {
					if (n2 == a[k])
						flag = 0; //같은거 있으니까 넣을 수 있음
				}
				if (flag == 0) {
					if (new_idx + 1 <= size)
						new_idx++;
					new[new_idx] = n2;
					//printf("new(n2) = %d, new_idx = %d\n", new[new_idx], new_idx);
					if (new_idx == size)
						return;
				}
				if (flag == 1) {
					break;
				}

			}
			else {
				int n3 = a[i] * 3 + 1;

				for (int k = 0; k < size; k++) {
					if (n3 == a[k])
						flag = 0; //같은거 있으니까 넣을 수 있음
				}
				if (flag == 0) {
					if (new_idx + 1 <= size)
						new_idx++;

					new[new_idx] = n3;
	
					if (new_idx == size)
						return;
					//printf("new(n3) = %d, new_idx = %d\n", new[new_idx], new_idx);
				}
				if (flag == 1) {
					break;
				}
			}
		}
		
	}

	
}

int main() {
	int N;
	int a[1000];
	int new[1000];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	inSequence(a, new, N);

	for (int i = 0; i < N; i++) {
		printf("%d ", new[i]);
	}
}