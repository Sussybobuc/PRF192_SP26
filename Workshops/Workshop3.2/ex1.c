#include <stdio.h>


int is_leap_year(int year) {
	if(year % 400 == 0) {
		return 1;
	}
	if(year % 100 == 0) {
		return 0;
	}
	if(year % 4 == 0) {
		return 1;
	}
	return 0;
}

int get_days_in_month(int month, int year) {
	int day = 31;
	switch(month) {
		case 2:
			if(is_leap_year(year) == 1) {
				day = 29;
			} else {
				day = 28;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day = 30;
			break;
		default:
			day = 31;
			break;
	}
	return day;
}

int inputMonth() {
	int month;
	printf("Nhap thang: ");
	while(scanf("%d", &month) != 1 || month > 12 || month < 1 ) {
		printf("Nhap sai!\nNhap Lai: ");
		while (getchar()!= '\n');
	} fflush(stdin);
	return month;
}
int inputYear() {
	int year;
	printf("Nhap nam: ");
	while(scanf("%d", &year) != 1 || year <= 0 ) {
		printf("Nhap sai!\nNhap Lai: ");
		while (getchar()!= '\n');
	}
	return year;
}

int main() {
	int month = inputMonth();
	int year = inputYear();
	int kq = get_days_in_month(month, year);
	printf("Thang %d Nam %d co %d ngay!", month, year, kq);
	return 0;
}