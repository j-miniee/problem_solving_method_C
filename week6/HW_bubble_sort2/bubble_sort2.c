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

void bubbleSort(struct Student* arr, int n, int option) { //성적은 내림차순,id는 내림차순으로 정렬
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
	int n; //학생 수
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
		printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기) : ");
		scanf("%d", &option);//성적은 내림차순으로, id는 오름차순으로 정렬.

		if (option != 0) {
			bubbleSort(s, n, option);
			for (i = 0; i < n; i++) {
				printf("학번 : %d\t영어 : %d\t수학 : %d\t국어: %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
			}
		}
	} while (option != 0);

	free(s);
}