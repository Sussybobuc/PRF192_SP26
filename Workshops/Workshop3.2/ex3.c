#include <stdio.h>

float calculate_salary(float hours) {
	float money = 0;
	if (hours > 40) {
		money = 40 * 22.700 
				+ ((hours - 40) * (22.700 * 1.5)) ;
	} else {
		money = hours * 22.700;
	}
	return money;
}

int main() {
	float hours;
	printf("Nhap so gio lam viec: ");
	if (scanf("%f", &hours) != 1 || hours < 0) {
		printf("Nhapsai\n");
		return 0;
	}
	float pay = calculate_salary(hours);
	printf("%-10s| %-10s|\n","Hours","Total");
	printf("%-10.1f| %-10.3f|\n",hours,pay);
	return 0;
}