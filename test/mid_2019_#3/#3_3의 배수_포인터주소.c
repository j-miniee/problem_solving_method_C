#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int get_reverse_number(int n, int* arr) { 
	//*arr 포인터(주소 가져와)
	//n은 배수인 수, *arr는 그 주소
	int count = 0;
	int number, i;

	number = n;
	while (number != 0) { // 3의 배수의 자리수 구함
		count++;
		number = number / 10;
	}

	number = n;
	i = count;
	while (number != 0) {// 뒤에부터 채워넣음
		i--;
		arr[i] = number % 10;
		number = number / 10;
	}
	return count; //자리수 반환
}

int main() {
	int N, i;
	int reverse_number[10] = { 0 };
	int digits;

	i = 0;

	scanf("%d", &N);

	while (1) {
		i += 3;
		digits = get_reverse_number(i, reverse_number); //자리 채워짐 
		if (N > digits) {
			N = N - digits;
			continue;
		}
		else  { 
			printf("%d", reverse_number[N - 1]);
			break;
		}
	}
	return 0;
}