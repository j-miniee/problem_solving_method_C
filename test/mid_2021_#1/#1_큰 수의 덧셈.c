#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char n[], int len) {
	for (int i = 0; i < len / 2; i++) {
		int temp = n[i];
		n[i] = n[len - i - 1];
		n[len - i - 1] = temp;
	}
}
int main() {
	char n1[100], n2[100];

	scanf("%s", n1);
	scanf("%s", n2);

	int len1 = strlen(n1);
	int len2 = strlen(n2);

	int len = len1 > len2 ? len1 : len2;

	reverse(n1, len1);
	reverse(n2, len2);

	if (len1 > len2) {
		for (int i = len2; i < len1; i++) {
			n2[i] = '0';
		}
	}
	else if (len1 < len2) {
		for (int i = len1 ; i < len2; i++) {
			n1[i] = '0';
		}
	}

	int carry_cnt = 0;
	int flag = 0; 

	for (int i = 0; i < len; i++) {
		int num = (n1[i]-'0') + (n2[i]-'0') + flag;
		
		if (num >= 10) {
			flag = 1;
			carry_cnt++;
		}
		else {
			flag = 0;
		}
	}

	printf("%d", carry_cnt);

	
}