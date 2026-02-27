#include <stdio.h>

long a, b;
float kq;
int input;

void show_menu() {
	printf("\n===== Menu =====\n");
	printf("1. Cong (+)\n");
	printf("2. Tru  (-)\n");
	printf("3. Nhan (*)\n");
	printf("4. Chia (/)\n");
	printf("0. Thoat\n");
	printf("================\n");
	printf("Nhap lua chon: ");

	while (scanf("%d", &input) != 1 || input < 0 || input > 4) {
		printf("Nhap sai!\nNhap lai: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
}

void inputAB() {
	printf("Nhap a: ");
	while (scanf("%ld", &a) != 1) {
		printf("Nhap sai!\nNhap lai: ");
		while (getchar() != '\n');
	}
	printf("Nhap b: ");
	while (scanf("%ld", &b) != 1) {
		printf("Nhap sai!\nNhap lai: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
}

void processor() {
	inputAB();
	switch (input) {
		case 1:
			kq = a + b;
			printf("Ket qua: %ld + %ld = ", a, b);
			break;
		case 2:
			kq = a - b;
			printf("Ket qua: %ld - %ld = ", a, b);
			break;
		case 3:
			kq = a * b;
			printf("Ket qua: %ld * %ld = ", a, b);
			break;
		case 4:
			if (b == 0) {
				printf("Khong the chia cho 0!\n");
				return;
			}
			kq = (float)a / b;
			printf("Ket qua: %ld / %ld = ", a, b);
			break;
	}
	if (kq - (int)kq != 0) {
		printf("%.2f\n", kq);
	} else {
		printf("%d\n", (int)kq);
	}
}

int main() {
	do {
		show_menu();
		if (input != 0) {
			processor();
		}
	} while (input != 0);

	printf("Tam biet!\n");
	return 0;
}