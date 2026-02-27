#include <stdio.h>

void printASCIITable() {
	printf("Ma ASCII | Ky tu\n");
	printf("-----------------\n");
	for (int i = 65; i <= 90; i++) {
		printf("%8d | %c\n", i, (char)i);
	}
}
int main() {
	printASCIITable();
	return 0;
}