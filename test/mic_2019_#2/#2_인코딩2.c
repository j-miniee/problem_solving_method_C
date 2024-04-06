#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char arr[100];

	scanf("%s", arr);

	int len = strlen(arr);

	if ((arr[len - 1] - '0') % 2 == 0)
		printf("1");
	else
		printf("0");

	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i] - '0';
	}
	if (sum % 3 == 0)
		printf("1");
	else
		printf("0");
	
	int num = 0;
	for (int i = 0; i < len; i++) {
		num = num * 10 + (arr[i] - '0');
	}
	if(num % 4 == 0)
		printf("1");
	else
		printf("0");

	if (((arr[len - 1] - '0') % 5 == 0) || ((arr[len - 1] - '0') % 5 == 5))
		printf("1");
	else
		printf("0");

}