#include<stdio.h>
int n;
void Convert(int n){
	if(n>0){
		Convert(n / 2);
		printf("%d", n%2);
	}
}
int main() {
	if(scanf("%d", &n) != 1 || n < 0) {
		printf("Nhap sai!\n");
		while(getchar()!= '\n');
	}
	if(n==0){
		printf("0");
	} else{
		Convert(n);
	}
	printf("\n");
	return 0;
}

