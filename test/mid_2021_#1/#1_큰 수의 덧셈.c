#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int* arr;
    scanf("%d", &N);
    arr = (int*)malloc(sizeof(int) * N);

    int n = 3;
    int i = 0;
    while (i < N) {
        if (n % 3 == 0) {
            if (n < 10)
                arr[i++] = n;
            else {
                int quotient = n / 10;
                int remainder = n % 10;
                arr[i++] = quotient;
                if (i < N)
                    arr[i++] = remainder;
            }
        }
        n++;
    }

    printf("%d", arr[N - 1]);

    free(arr);

    return 0;
}