#include<stdio.h>
int n;
void count() {
	int x = 1;
	do {
		printf("%d ",x);
		x++;
	} while(x<=n);
}
void multi() {
	int x = 1;
	do {
		printf("\n%d x %d = %d",n,x,n*x);
		x++;
	} while(x <=10);
}
int main() {
	printf("Nhap n: ");
	do {
		printf("Nhap lai n: ");
		fflush(stdin);
	} while(scanf("%d",&n)!=1 || n<=0 || n>=10);
	count();
	multi();
	return 0;
}

