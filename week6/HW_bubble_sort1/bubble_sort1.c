#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Student {
	int id; //학번
	int korean, english, math;//성적
};

void bubbleSortDecendingByKorean(struct Student* arr, int n) {
	int i, j;
	struct Student temp;

	for (j = 0; j < n - 1; j++) {
		for (i = 0; i < n - 1 - j; i++) {
			if (arr[i].korean < arr[i + 1].korean) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

void bubbleSortAscendingById(struct Student* arr, int n) {
	int i, j;
	struct Student temp;

	for (j = 0; j < n - 1; j++) {
		for (i = 0; i < n - 1 - j; i++) {
			if (arr[i].id > arr[i + 1].id) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

int main() {
	int i;
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
		printf("학번: %d, 국어성적: %d, 영어성적: %d, 수학성적: %d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	}

	bubbleSortDecendingByKorean(s, n); //국어성적으로 내림차순
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("학번: %d, 국어성적: %d, 영어성적: %d, 수학성적: %d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	}

	bubbleSortAscendingById(s, n);//학번으로 오름차순
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("학번: %d, 국어성적: %d, 영어성적: %d, 수학성적: %d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	}

	free(s);

}