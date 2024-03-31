#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = {
		0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
		-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
		-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
		-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
		-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
		-1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
		-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
		-1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
		-1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
		-1,-1,-1,-1, 0, 0, 0, 0, 0, 0

};

void flood_fill(int x, int y, int *cnt) 
{
	if (x < 0 || x >=  HEIGHT || y<0 || y >= WIDTH ) {
		return;
	}

	if (screen[x][y] == 0) 
	{
		screen[x][y] = *cnt;
		(*cnt)++;

		flood_fill(x, y + 1, cnt); //오른
		flood_fill(x + 1, y, cnt);//아래
		flood_fill(x, y - 1, cnt); //왼
		flood_fill(x - 1, y, cnt); //위
	}

}

int main(void) {

	printf("미로:\n");
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			printf("%2d ", screen[i][j]);
		printf("\n");
	}
	
	int cnt = 1;
	flood_fill(0, 0 ,&cnt);
	printf("\n");

	printf("시작점을 <0,0>으로 한 미로방문<순서 표기>:\n");
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			printf("%2d ", screen[i][j]);
		printf("\n");
	}

	return 0;
}