#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include < stdlib.h >

int main() {
	int n;

	scanf("%d", &n);

	int* p = (int*)malloc(sizeof(int) * 100);

	int i = 0;
	int num = n;
	int flag = 0;
	while (num != 0) {
		int sum = (num % 10) * 9 + flag;
		if (sum >= 10) {
			p[i++] = sum % 10;
			if (num / 10 == 0) {
				p[i] = sum / 10;
				break;
			}
			else {
				flag = sum / 10;
			}
		}
		else {
			flag = 0;
			p[i++] = sum;
		}
		num = num / 10;
	}

	for (int j = i; j >= 0; j--) { 
		printf("%d ", p[j]);
	}

	free(p);

}