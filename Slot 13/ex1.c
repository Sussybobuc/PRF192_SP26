#include <stdio.h>
#define MAX 100
//void doubleX(int *x) {
//	*x *= *x;
//}

void inputArr(int a[], int n) {
	for(int i = 0; i < n; i++) {
		printf("a[%d]", i);
		scanf("%d", &a[i]);
	}
}

void outputArr(int a[], int n) {
	for(int i = 0; i < n ; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}

int isPrime(int n) {
	if(n < 2) {
		return 0;
	}
	if(n == 2) {
		return 1;
	}
	if(n % 2 == 0) {
		return 0;
	}
	for(int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}


int countPrimes(int a[], int n) {
	int count = 0;
	for(int i = 0 ; i<n ; i++) {
		if(isPrime(a[i])) {
			count++;
		}
	}
	return count;
}

int main() {
	int n;
	int a[MAX];
	scanf("%d", &n);
	inputArr(a,n);
	outputArr(a,n);
	isPrime(n);
	int countPrime = countPrimes(a, n);
	printf("So nguyen to trong mang la: %d", countPrime);

//	int x = 10;
//	doubleX(&x);
//	printf("Gia tri x= %d",x);
//	int *p = &x;
//	printf("Dia chi duoc chua %u: ",p);
//	printf("\nGia tri cua vung nho ma p tro den: %d",*p);
////	x = x*x;
//	*p = (*p) + (*p);
//	printf("\nGia tri cua x la: %d", x);
//	printf("\nGia tri cua vung nho ma p tro den: %d",*p);
//	int y = 5;
//	p = &y;
//	printf("\nDia chi duoc chua %u ",p);
//	printf("\nGia tri cua vung nho ma p tro den: %d",*p);
//	printf("\nGia tri cua y la: %d",y);
	return 0;
}