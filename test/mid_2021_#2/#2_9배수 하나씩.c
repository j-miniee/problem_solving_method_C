#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int reverse(int n, int* reverse_num) {//포인터로 주소 받아서 reverse
	int cnt = 0;
	int number, i;

	number = n; //891
	while (number != 0) {
		number = number / 10; 
		cnt++; 
	}

	number = n;
	i = cnt;
	while (number != 0) {
		i--;
		reverse_num[i] = number % 10; //reverse 시킴!! 
		number = number / 10;
	}
	return cnt;

}

int main() {
	int n, digit, i;
	int reverse_num[10] = { 0 };
	scanf("%d", &n);

	n = n * 9;

	digit = reverse(n, reverse_num);
	for (i = 0; i < digit; i++) {
		printf("%d ", reverse_num[i]);
	}
}