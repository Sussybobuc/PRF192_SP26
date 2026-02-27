#include <stdio.h>

int inputInt() {
	int intNum;
	while (scanf("%d", &intNum) != 1 || intNum <= 0) {
		printf("Nhap sai!\nNhap Lai: ");
		fflush(stdin);
	}
	return intNum;
}

int findMax(int a, int b, int c) {
	int max;
	max = a;
	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}
	return max;
}

int main() {
	int a, b, c, kq;
	printf("Nhap a: ");
	a = inputInt();
	printf("Nhap b: ");
	b = inputInt();
	printf("Nhap c: ");
	c = inputInt();
	kq = findMax(a, b, c);
	printf("So lon nhat trong %d, %d, %d la %d\n",a,b,c, kq);
	return 0;
}