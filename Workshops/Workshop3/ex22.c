#include<stdio.h>
#include<math.h>

int main() {
	float n;
	int count = 5;
	do {

		printf("Nhap vao n: ");
		while(scanf("%f",&n)!=1 || n<= 0 || n>1000) {
			printf("\nNhap lai n: ");
			fflush(stdin);
		}
		printf("Can bac 2 la: %.2f\n", sqrt(n));
		count--;
		if(count == 0) {
			printf("Da xong");
			break;
		}
	} while(1);
	return 0;
}
