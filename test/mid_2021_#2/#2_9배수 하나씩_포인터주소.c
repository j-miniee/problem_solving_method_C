#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int reverse(int n, int* reverse_num) {//�����ͷ� �ּ� �޾�
	int cnt = 0;
	int number, i;

	number = n; 
	while (number != 0) { //�ڸ��� ����
		number = number / 10; 
		cnt++; 
	}

	number = n;
	i = cnt;
	while (number != 0) { //�ڿ����� ä������
		i--; //�ε����ϱ�
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

	digit = reverse(n, reverse_num); //�ڸ��� ��ȯ

	for (i = 0; i < digit; i++) {
		printf("%d ", reverse_num[i]);
	}
}