#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void play_game() {
	int n, g, tried = 0;
	srand(time(NULL));
	n = rand() % 100 +1;
	printf("Da khoi tao so ngau nhien tu 1-100!\n");
	do {
		printf("So ban doan la: ");
		if(scanf("%d", &g)!= 1 || g < 1 || g > 100) {
			printf("Khong hop le!");
			while(getchar() != '\n');
			continue;
		}
		if(g != n) {
			if(g > n) {
				printf("Nho hon!\n");
			} else if(g < n) {
				printf("Lon hon!\n");
			}
			tried++;
		} else if(tried < 6) {
			printf("Ban da doan dung so %d sau %d lan!",n,tried);
			break;
		}
	} while(tried <= 6);
	printf("Het luoc doan! So dung la: %d", n);
}

int main() {
	play_game();
	return 0;
}