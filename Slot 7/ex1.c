#include<stdio.h>

int main() {
	int quy, thang;
	printf("Nhap vao thang: ");
	if(scanf("%d",&thang) !=1 || (thang <1 || thang >12)){
		printf("Nhap sai!");
		return 0;
	} switch(thang) {
		case 1:
		case 2:
		case 3:
			quy = 1;
			break;
		case 4:
		case 5:
		case 6:
			quy = 2;
			break;
		case 7:
		case 8:
		case 9:
			quy = 3;
			break;
		case 10:
		case 11:
		case 12:
			quy = 4;
			break;
		default:
			printf("Nhap sai!");
			break;
	}
	printf("Thang %d thuoc quy %d",thang, quy);
	return 0;
}