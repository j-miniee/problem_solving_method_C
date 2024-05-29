#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //문자열 길이**

// 0~9 = 48~57, A~Z = 65~90, a~z = 97~122 
/*
	대문자-소문자-숫자
*/
void swap(char* arr, int i, int j) {
	int  temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(char A[], int p, int r) {
	int i, j;
	int pivot;
	int t;

	i = p - 1; //시작 바로 왼쪽

	pivot = A[r];

	for (j = p; j < r; j++) {
		if (A[j] < pivot) {
			i++;
			swap(A, i, j);
		}
	}
	i++;
	swap(A, i, j);

	return i; //pivot의 위치를 반환함
}

int quickSort(char* A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void find_number(char* A, char *new, int n) {
	int i, new_idx = 0;

	for (i = 0; i < n; i++) {
		if (A[i] >= '0' && A[i] <= '9') {
			new[new_idx++] = A[i];
		}
	}
	new[new_idx] = '\0';//중요
	quickSort(new, 0, new_idx - 1);
}

void find_alphabet(char* A, char* new, int n) {
	int i, new_idx = 0;

	for (i = 0; i < n; i++) {
		if ((A[i] >= 'A' && A[i] <= 'Z')|| (A[i] >= 'a' && A[i] <= 'z')) {
			new[new_idx++] = A[i];
		}
	}
	new[new_idx] = '\0';//중요
	quickSort(new, 0, new_idx - 1);
}

int main() {
	char str[500000];
	char *num, *alph;
	int len;

	scanf("%s", str);
	len = strlen(str);

	num = (char*)malloc(sizeof(char) * (len + 1));
	alph = (char*)malloc(sizeof(char) * (len + 1));

	find_number(str, num, len);
	find_alphabet(str, alph, len);
	strcat(alph, num);

	printf("%s", alph);

}