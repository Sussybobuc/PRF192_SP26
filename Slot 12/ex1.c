#include <stdio.h>

int Sum(int n){
	int sum = 0, i;
	for(i = 1; i <= n; i++){
		if(n % i == 0){
			sum += i;
		}
	} return sum;
}

int inputInt(){
	int intNum;
	printf("Nhap so int: ");
	while(scanf("%d", &intNum) != 1 || intNum <= 0){
		printf("Nhap sai!\nNhap Lai: ");
		fflush(stdin);
	} return intNum;
}

int main(){
	int n;
	n = inputInt();
	int kq = Sum(n);
	printf("%d", kq);
	return 0;
}