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

void bubbleSort(struct Student* arr, int n, int option) { //������ ��������,id�� ������������ ����
	int i, j;

	for (j = 0; j < n - 1; j++) {
		for (i = 0; i < n - 1 - j; i++) {
			switch (option) {
			case 1:
				if (arr[i].korean < arr[i + 1].korean)
					swap(arr, i, i + 1);
				break;
			case 2:
				if (arr[i].math < arr[i + 1].math)
					swap(arr, i, i + 1);
				break;
			case 3:
				if (arr[i].english < arr[i + 1].english)
					swap(arr, i, i + 1);
				break;
			case 4:
				if (arr[i].id > arr[i + 1].id)
					swap(arr, i, i + 1);

				break;
			}
		}
	}
}

int main()
{
	int i, option;
	int n; //�л� ��
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

	do {
		printf("\n");
		printf("���� ���� ����(1:����, 2:����, 3:����, 4:id(��������), 0:������) : ");
		scanf("%d", &option);//������ ������������, id�� ������������ ����.

		if (option != 0) {
			bubbleSort(s, n, option);
			for (i = 0; i < n; i++) {
				printf("�й� : %d\t���� : %d\t���� : %d\t����: %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
			}
		}
	} while (option != 0);

	free(s);
}