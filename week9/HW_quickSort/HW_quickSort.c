#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Student {
	int id; //학번
	int korean, english, math;//성적
};

void swap(struct Student* arr, int i, int j) {
	struct Student temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(struct Student* arr, int p, int r, int option) {
	//id만 오름차순
	int i, j;
	struct Student pivot;
	pivot = arr[r]; 

	i = p - 1; //시작 바로 왼쪽

	switch (option) {
	case 1:
		for (j = p; j < r; j++) {
			if (arr[j].korean >= pivot.korean) {
				i++;
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, r);
		return i + 1;

	case 2:
		for (j = p; j < r; j++) {
			if (arr[j].math >= pivot.math) {
				i++;
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, r);
		return i + 1;

	case 3:
		for (j = p; j < r; j++) {
			if (arr[j].english >= pivot.english) {
				i++;
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, r);
		return i + 1;

	case 4:
		for (j = p; j < r; j++) {
			if (arr[j].id <= pivot.id) {
				i++;
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, r);
		return i + 1;

	}
}

void quickSort(struct Student* arr, int p, int r, int option) {
	if (p < r) {
		int q = partition(arr, p, r, option);
		quickSort(arr, p, q - 1, option);
		quickSort(arr, q + 1, r, option);
	}
}


int main()
{
	int i, option;
	int n; //학생 수
	printf("학생 수를 입력하세요 : ");
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
		printf("학번 : %d\t영어 : %d\t수학 : %d\t국어: %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
	}

	do {
		printf("\n");
		printf("정렬 기준 선택(1: 국어, 2: 수학, 3: 영어, 4: id(오름차순), 0: 끝내기) : ");
		scanf("%d", &option);

		if (option != 0) {
			quickSort(s, 0, n - 1, option);
			for (i = 0; i < n; i++) {
				printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
			}
		}
	} while (option != 0);

	free(s);
}