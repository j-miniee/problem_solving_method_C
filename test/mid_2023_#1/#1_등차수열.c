#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <stdlib.h>

int main() {
	int N;
	int* p;
	scanf("%d", &N);
	p = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}
	int differ = p[1]-p[0];
	for (int i = 2; i < N; i++) {
		int check = p[i] - p[i - 1];
		if (check != differ) {
			printf("0");
			free(p);
			return 0;
		}
	}
	printf("1");
	free(p);
	return 0;
}

/*
int is_arithmetic_sequence(int arr[], int len) {
    if (len <= 2)
        return 1;

    // 등차 수열인지 확인
    int diff = arr[1] - arr[0];
    for (int i = 2; i < len; i++) {
        if (arr[i] - arr[i-1] != diff)
            return 0;
    }
    return 1;
}

int main() {
    int N;
    int A[100] = {0};

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int result = is_arithmetic_sequence(A, N);
    printf("%d", result);

    return 0;
}*/
