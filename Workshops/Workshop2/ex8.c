#include<stdio.h>
int a,b,r;
int main() {
	printf("Nhap hai so nguyen duong a, b: ");
	if(scanf("%d %d",&a,&b)!=2) {
		printf("Khong hop le!\n");
		while(getchar()!= '\n');
		return 1;
	} else if(b>a) {
		printf("DK: a>b!");
		while(getchar()!= '\n');
	}
	if(a <= 0 || b <= 0) {
		printf("Vui long nhap so nguyen duong!\n");
		return 1;
	}
	int base_a = a, base_b = b;
	while(1) {
		r = a%b;
		if(r == 0) {
			printf("Uoc chung lon nhat cua %d va %d: %d!",base_a,base_b,b);
			break;
		}
		a = b;
		b = r;
	}
	return 0;

}