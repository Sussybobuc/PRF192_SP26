#include<stdio.h>
int n;
void count() {
	int x = 1;
	while(x<=n) {
		printf("%d ",x);
		x++;
	}
}
void multi() {
	int x = 1;
	while(x <=10) {
		printf("\n%d x %d = %d",n,x,n*x);
		x++;
	}
}
int main() {
	printf("Nhap n: ");
	while(scanf("%d",&n)!=1 || n<=0 || n>=10) {
		printf("Nhap lai n: ");
		fflush(stdin);
	}
	count();
	multi();
	return 0;
}

