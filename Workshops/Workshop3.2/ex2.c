#include <stdio.h>

float calculate_taxi_fare(float S) {
	float money = 0;
	if (S <= 1) {
		money = 15;
	} else if (S < 31 && S > 1) {
		money = 15
		        + (S - 1) * 12;
	} else if (S >= 30) {
		money = 15
		        +  (S-(S - 30)-1)* 12
		        +  (S - 30) * 10;
	}
	return money;
}

int main() {
	float S;
	printf("Nhap so km da di: ");
	if (scanf("%f", &S) != 1 || S < 0) {
		printf("Nhapsai\n");
		return 0;
	}
	float fee = calculate_taxi_fare(S);
	printf("%-10s| %-10s|\n","Km","Total");
	printf("%-10.1f| %-10.3f|\n",S,fee);
	return 0;
}
