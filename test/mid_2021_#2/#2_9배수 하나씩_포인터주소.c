#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int reverse(int n, int* reverse_num) {//포인터로 주소 받아
	int cnt = 0;
	int number, i;

	number = n; 
	while (number != 0) { //자리수 구함
		number = number / 10; 
		cnt++; 
	}

	number = n;
	i = cnt;
	while (number != 0) { //뒤에부터 채워넣음
		i--; //인덱스니까
		reverse_num[i] = number % 10;
		number = number / 10;
	}
	return cnt;

}

int main() {
	int n, digit, i;
	int reverse_num[10] = { 0 };
	scanf("%d", &n);

	n = n * 9;

	digit = reverse(n, reverse_num); //자릿수 반환

	for (i = 0; i < digit; i++) {
		printf("%d ", reverse_num[i]);
	}
}