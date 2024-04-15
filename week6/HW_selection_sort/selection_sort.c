#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Student {
	int id; //학번
	int korean, english, math;//성적
};

void selection_sort(struct Student* arr, int n) {
	
	int i, j;
	int min, min_idx;
	struct Student temp;
	
	for (j = 0; j < n - 1; j++) {//n-1번 수행
		min = arr[0].korean;
		min_idx = 0;
		for (i = 1; i < n - j; i++) {
			if (min > arr[i].korean) {
				min = arr[i].korean;
				min_idx = i;
			}
		}

		temp = arr[min_idx];
		arr[min_idx] = arr[i-1];
		arr[i-1] = temp;
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

	selection_sort(s, n);

	
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("학번: %d, 국어성적: %d, 영어성적: %d, 수학성적: %d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	}

	free(s);
	

}