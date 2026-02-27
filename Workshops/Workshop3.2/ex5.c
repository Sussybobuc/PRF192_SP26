#include <stdio.h>

int is_prime(int n) {
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

int main() {
	int a, b, i;
	do {
		printf("Nhap so a: ");
		if(scanf("%d", &a) != 1 || a < 1) {
			printf("Nhap sai,\nNhap lai: ");
			while(getchar() != '\n');
			continue;
		}
		printf("Nhap so b: ");
		if(scanf("%d", &b) != 1 || a > b || b < 1) {
			printf("Nhap sai,\nNhap lai: ");
			while(getchar() != '\n');
			continue;
		}
		break;
	} while(1);
		printf("So nguyen to co trong [%d, %d]:\n", a, b);
	for(i = a; i <= b; i++) {
		if( i != 2 && i % 2 == 0) {
			continue;
		}
		if(is_prime(i) == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}