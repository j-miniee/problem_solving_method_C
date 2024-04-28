#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int get_reverse_number(int n, int* arr) { 
	//*arr ������(�ּ� ������)
	//n�� ����� ��, *arr�� �� �ּ�
	int count = 0;
	int number, i;

	number = n;
	while (number != 0) { // 3�� ����� �ڸ��� ����
		count++;
		number = number / 10;
	}

	number = n;
	i = count;
	while (number != 0) {// �ڿ����� ä������
		i--;
		arr[i] = number % 10;
		number = number / 10;
	}
	return count; //�ڸ��� ��ȯ
}

int main() {
	int N, i;
	int reverse_number[10] = { 0 };
	int digits;

	i = 0;

	scanf("%d", &N);

	while (1) {
		i += 3;
		digits = get_reverse_number(i, reverse_number); //�ڸ� ä���� 
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