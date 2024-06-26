#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int n1, n2;
	int carry_count;
	int carry;

	scanf("%d", &n1);
	scanf("%d", &n2);

	carry_count = 0;
	carry = 0;

	while (n1 != 0 || n2 != 0) {
		int remainder_n1;
		int remainder_n2;

		remainder_n1 = n1 % 10;
		remainder_n2 = n2 % 10;

		if (remainder_n1 + remainder_n2 + carry > 9) {
			carry_count = carry_count + 1;
			carry = 1;
		}
		else {
			carry = 0;
		}

		n1 = n1 / 10;
		n2 = n2 / 10;
	}

	printf("%d\n", carry_count);

	return 0;
}