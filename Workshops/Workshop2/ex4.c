#include<stdio.h>
int n;
int Rev = 0;

int main() {
	if(scanf("%d", &n) != 1) {
		printf("Nhap sai!\n");
		fflush(stdin);
	}
	while(n!=0) {
		Rev = Rev * 10 + (n%10);
		n = n/10;
		printf("So dao nguoc: %d", Rev);
	}
	return 0;
}
