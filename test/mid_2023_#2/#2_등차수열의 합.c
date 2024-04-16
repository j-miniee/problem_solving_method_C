#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void ascending_order(int* arr, int len) {
	int i, j;

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void) {
	int i, j, k;
	int Na, Nb;
	int differ;
	
	scanf("%d", &Na);
	int* A = (int*)malloc(sizeof(int) * Na); //Na 입력 받은 후에 메모리 할당
	for (i = 0; i < Na; i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &Nb);
	int* B = (int*)malloc(sizeof(int) * Nb);
	for (i = 0; i < Nb; i++) {
		scanf("%d", &B[i]);
	}

	int* C = (int*)malloc(sizeof(int) * Nb);
	ascending_order(A, Na);
	ascending_order(B, Nb);
	
	for (i = 0; i < Na; i++) {
		C[i] = A[i];
	}

	k = 0;
	for (i = Na; i < Nb; i++) {
		C[i] = B[k++];
	}
	ascending_order(C, Nb);


	/*for (j = 0; j < Na; j++) {
		for (i = 0; i < Nb; i++) {
			if (B[i] > A[j]) {
				for (k = Nb - 1; k > i; k--) {
					B[k] = B[k - 1];
				}
				B[k] = A[j];
				break;
			}
			else if (B[i] == A[j])
				break;
		}
		if (i == Nb && B[i - 1] < A[j]) {
			for (k = 1; k < i; k++)
				B[k] = B[k - 1];
			//B[Nb-1] = A[j];
		}
	}
	*/

	for (int m = 0; m < Nb; m++) {
		printf("%d ", C[m]);
	}
	printf("\n");

	differ = C[1] - C[0];
	for (i = 1; i < Nb - 1; i++) {
		int num = C[i + 1] - C[i];
		if (num != differ) {
			printf("-1");
			return 0;
		}
	}

	int total = 0;
	for (i = 0; i < Nb; i++)
		total += C[i];
	printf("%d", total);

	return 0;
}