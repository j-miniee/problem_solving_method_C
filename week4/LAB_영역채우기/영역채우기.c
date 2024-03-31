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
		flood_fill(x, y + 1); // 오
		flood_fill(x + 1, y); // 아래
		flood_fill(x, y - 1); // 왼
		flood_fill(x - 1, y); // 위
	}

}

int main(void) {

	printf("미로:\n");
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			printf("%2d ", screen[i][j]);
		printf("\n");
	}

	flood_fill(1, 1);
	printf("\n");

	printf("시작점을 <0,0>으로 한 미로방문<순서 표기>:\n");
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			printf("%2d ", screen[i][j]);
		printf("\n");
	}

	return 0;
}