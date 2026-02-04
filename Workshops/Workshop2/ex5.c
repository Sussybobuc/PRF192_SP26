#include<stdio.h>

int main() {
	int sum = 0;
	int num;
	while(num!=0) {
		if(scanf("%d", &num) != 1 || num < 0) {
			printf("Nhap sai!\n");
			fflush(stdin);
		}
		if(num>0) {
			sum += num;
		}
	}
	printf("\n%d",sum);
	return 0;
}