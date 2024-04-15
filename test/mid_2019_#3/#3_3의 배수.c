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
        int sum = 0;
        int temp = n;
        if (temp % 10 == 0) {
            int cnt_temp = 0;
            int cnt_sum = 0;
            while (temp != 0) {
                sum = sum * 10 + temp % 10;
                temp = temp / 10;
                cnt_temp++;
            }
            while (sum != 0) {
                if (i < N) {
                    arr[i++] = sum % 10;
                }
                sum = sum / 10;
                cnt_sum++;
            }
            int cnt = cnt_temp - cnt_sum;
            while (cnt != 0) {
                arr[i++] = 0;
                cnt--;
            }  
        }
        else {
            while (temp != 0) {
                sum = sum * 10 + temp % 10;
                temp = temp / 10;
            }
            while (sum != 0) {
                if (i < N) {
                    arr[i++] = sum % 10;
                }
                sum = sum / 10;
            }
        }
    
        n+=3;
    }

    printf("%d ", arr[N-1]);

    free(arr);

    return 0;
}
