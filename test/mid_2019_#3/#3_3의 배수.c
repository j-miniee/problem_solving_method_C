#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int i = 0;
    int n = 0;

    while (i != N) { //N = 6
        i++; //   1, 2, 3, 4, 
        n += 3;// 3, 6, 9, 12, 

        if (n >= 10) {
            int temp = n;
            if (i == N) {
                n = temp / 10;
            }
            else if (i + 1 == N) {
                i++;
                n = temp % 10;
            }
            else {
                i++;
            }
        }
    }
    printf("%d", n);

}