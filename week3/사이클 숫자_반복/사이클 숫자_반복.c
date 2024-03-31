#include <stdio.h>

int get_cycle_number(int n) {
	int cnt = 1;
	
	while (n != 1) {
		if (n % 2 == 0)
			n = n / 2;
		else
			n = n * 3 + 1;
		cnt++;
	}
	return cnt;

}

int main(void) {
	int n;

	n = 22;

	printf("%d", get_cycle_number(n));

	return 0;
}