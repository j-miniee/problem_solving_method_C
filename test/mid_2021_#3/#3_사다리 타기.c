#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() { 
	int width, height, n;
	scanf("%d %d", &width, &height);
	scanf("%d", &n);

	int arr[100][100];//arr는 int형

    for (int i = 0; i < height; i++) {
        char str[100]; //빈칸 없이 받으니까 &s로 받아야 함
        scanf("%s", str);

        for (int j = 0; j < width-1 ; j++) {
            arr[i][j] = str[j] - '0';//char-'0'
        }
    }
	int i = 0;
	
	for(int i = 0; i < height; i++){
		if(n == 0){
			if (arr[i][n] == 1)
				n++;
		}
		else if (n == width - 1) {
			if (arr[i][n - 1] == 1) {
				n--;
			}
		}
		else {
			if (arr[i][n] == 1) {
				n++;
			}
			else if (arr[i][n - 1] == 1) {
				n--;
			}
		}
	}

	printf("%d", n);
}