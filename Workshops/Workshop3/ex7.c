#include<stdio.h>
int i = 1;
int n;
int Cp = 0;
int Checked = 1;
void Input() {
	if(scanf("%d", &n) != 1 ) {
		printf("Nhap sai!\n");
		while(getchar()!= '\n');
		Checked = 0;
	} else if(n < 0) {
		printf("Khong phai so chinh phuong!");
		while(getchar()!= '\n');
		Checked = 0;
	} else if(n==0) {
		printf("So chinh phuong");
		Checked = 0;
	}
}
int main() {
	Input();
	if(Checked == 0){
		return 0;
	}
	do {
		if(i * i ==n) {
			printf("So chinh phuong");
			Cp = 1;
			break;
		}
		i++;
	} while(i * i <=n);
	if(Cp == 0) {
		printf("Khong phai so chinh phuong!");
	}
	return 0;
}
