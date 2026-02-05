#include<stdio.h>

int main() {
	int sum = 0;
	int num;
	while(num!=0) {
		printf("Nhap cac so nguyen duong\n");
		if(scanf("%d", &num) != 1 || num < 0) {
			printf("Nhap sai!\n");
			while(getchar()!= '\n');
		}
		else {
			sum += num;
		}
	}
	printf("\n%d",sum);
	return 0;
}
