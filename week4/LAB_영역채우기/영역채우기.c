#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = {
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		-1,-1, 0, 0,-1,-1,-1, 0,-1,-1,
		-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
		-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,
		-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
		-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
		-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
		-1,-1,-1, 0,-1, 0, 0, 0,-1,-1,
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

void flood_fill(int x, int y) {

	if (screen[x][y] == -1)
		return;

	if (screen[x][y] == 0)
	{
		screen[x][y] = 9;
		flood_fill(x, y + 1); // ��
		flood_fill(x + 1, y); // �Ʒ�
		flood_fill(x, y - 1); // ��
		flood_fill(x - 1, y); // ��
	}

}

int main(void) {

	printf("�̷�:\n");
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			printf("%2d ", screen[i][j]);
		printf("\n");
	}

	flood_fill(1, 1);
	printf("\n");

	printf("�������� <0,0>���� �� �̷ι湮<���� ǥ��>:\n");
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			printf("%2d ", screen[i][j]);
		printf("\n");
	}

	return 0;
}