#include<stdio.h>
long long Total = 100000000;
long long Withdraw;
long long Took = 0;
char stop;
int main() {
	do {
		printf("Nhap so tien muon rut(S de dung): ");

		if(scanf("%lld", &Withdraw) == 1 ) {
			if(Withdraw <= 0) {
				printf("Khong hop le!\n");
				while(getchar()!= '\n');
				continue;
			}
			if(Withdraw > Total) {
				printf("So du khong kha dung!\n");
				while(getchar()!= '\n');
				continue;
			}
			Total -= Withdraw;
			Took += Withdraw;
			printf("Rut thanh cong! So du con lai: %d\n",Total);
		} else {
			if(scanf(" %c",&stop)== 1) {
				if(stop == 'S') {
					printf("Ket thuc giao dich\n");
					break;
				}
			} else {
				printf("Ky tu khong hop le!\n");
			}
			while(getchar() != '\n');
		}
	} while(Total > 0);
	printf("So tien da rut: %lld",Took);
	printf("\nSo du kha dung: %d", Total);
	return 0;
}
