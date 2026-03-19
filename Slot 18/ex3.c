#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct {
	int id;
	char name[100];
	int price;
} Book;

int main() {
	system("cls");
	printf("INPUT:\n");

	int n;
	scanf("%d", &n);
	Book bk[n];
	for (int i = 0; i < n; i++) {
		printf("\nNhap id: ");
		scanf("%d", &bk[i].id);

		getchar();
		printf("Nhap name: ");
		fgets(bk[i].name, sizeof(bk[i].name), stdin);
		bk[i].name[strcspn(bk[i].name, "\n")] = 0;

		printf("Nhap price: ");
		scanf("%d", &bk[i].price);
	}

	printf("\nOUTPUT:\n");

	int maxIndex = 0;
	int maxPrice = bk[0].price;
	for(int i = 1; i < n; i++) {
		int price = bk[i].price;
		if(price>maxPrice) {
			maxPrice = price;
			maxIndex = i;
		}
	}
	printf("Max price: %d Index: %d Name: %s", maxPrice, maxIndex, bk[maxIndex].name);

	printf("\nNhap id:");

	int x;
	scanf("%d", &x);
	int found = 0;
	for (int i = 0; i < n; i++) {
		if (x == bk[i].id) {
			printf("%d", i);
			found = 1;
			break;
		}
	}
	if (!found) {
		printf("Not found");
	}
	//@STUDENT: WRITE YOUR OUTPUT HERE:

	//--FIXED PART - DO NOT EDIT ANYTHING HERE
	printf("\n");
	system("pause");
	return 0;
}