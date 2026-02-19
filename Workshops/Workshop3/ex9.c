#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
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
		} else {
			printf("Ban da doan dung so %d sau %d lan!",n,tried);
			return 0;
		}
	} while(1);
	return 0;
}	

