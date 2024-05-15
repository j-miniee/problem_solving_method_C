#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Student {
	int id; //�й�
	int korean, english, math;//����
};

void swap(struct Student* arr, int i, int j) {
	struct Student temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(struct Student* arr, int p, int r) {
	int i, j;
	struct Student pivot;
	pivot = arr[r]; 

	i = p - 1; //���� �ٷ� ����

	for (j = p; j < r; j++) {
		if (arr[j].korean >= pivot.korean) {
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, r);
	return i + 1;

}

void quickSort(struct Student* arr, int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}

int main()
{
	int i, option;
	int n; //�л� ��
	printf("�л� ���� �Է��ϼ��� : ");
	scanf("%d", &n);

	struct Student* s = (struct Student*)malloc(sizeof(struct Student) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		s[i].id = i + 1;
		s[i].korean = rand() % 100;
		s[i].english = rand() % 100;
		s[i].math = rand() % 100;
	}

	for (i = 0; i < n; i++) {
		printf("�й� : %d\t���� : %d\t���� : %d\t����: %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
	}

	printf("���� �������� ����\n");
	quickSort(s, 0, n - 1);
	for (i = 0; i < n; i++) {
		printf("�й� : %d\t���� : %d\t���� : %d\t���� : %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
	}

	free(s);
}