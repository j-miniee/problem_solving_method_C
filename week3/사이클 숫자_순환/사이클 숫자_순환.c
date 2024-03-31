#include <stdio.h>

int get_cycle_number(int n) {
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		return get_cycle_number(n / 2) + 1;
	else
		return get_cycle_number(n * 3 + 1) + 1;

}

int main(void) {
	int n;

	n = 22;

	printf("%d", get_cycle_number(n));

	return 0;
}