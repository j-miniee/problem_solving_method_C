#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void make_array(int n, int* arr, int digit, int* lastIdx) {
	int count = 0;
	int number, i;

	number = n;
	while (number != 0) { // �ڸ��� ����
		count++;
		number = number / 10;
	}
	*lastIdx += count;
	
	number = n;
	i = *lastIdx; //�����ͷ� �ѱ��
	while (number != 0) {// �ڿ����� ä������
		i--;
		arr[i] = number % 10;
		number = number / 10;
	}
}

int get_reverse_number(int n, int *new_arr) {
	int count = 0;
	int number, i;

	number = n;
	while (number != 0) {
		count++;
		number = number / 10;
	}

	number = n;
	i = count;
	while (number != 0) {
		i--;
		new_arr[i] = number % 10;
		number = number / 10;
	}

	return count; //�ڸ��� ��ȯ
}

int find_num(int *arr, int new_arr[], int digit, int new_arr_digit) {
	int i, j;

	for (i = 0; i <= digit - new_arr_digit; i++) {
		int found = 1;
		for (j = 0; j < new_arr_digit; j++) {
			if (arr[i + j] != new_arr[j]) {
				found = 0;
				break;
			}
		}
		if (found == 1) 
			return i + 1;
	}

	return -1;
}

int main() {
	int N, K, M, i;
	int digit = 0;
	int new_arr_digit;
	int lastIdx = 0;
	int new_arr[10];

	scanf("%d", &N);
	scanf("%d", &K);
	scanf("%d", &M);

	for (i = K; i < N; i += K) { //�� ������ �ڸ���
		digit += get_reverse_number(i, new_arr);
	}
	printf("%d\n", digit);

	int* bucket = (int*)malloc(sizeof(int) * digit);

	for (i = K; i < N; i += K) {
		make_array(i, bucket, digit, &lastIdx);
	}

	/*for (i = 0; i < digit; i++) { // bucket �迭 ���
		printf("%d ", bucket[i]);
	}*/

	new_arr_digit = get_reverse_number(M, new_arr);

	/*for (i = 0; i < new_arr_digit; i++) {
		printf("%d ", new_arr[i]);
	}*/

	printf("%d", find_num(bucket, new_arr, digit, new_arr_digit));

}

