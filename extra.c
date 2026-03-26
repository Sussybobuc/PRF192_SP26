#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() {
	system("cls");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	printf("INPUT:\n");

	int number, digit;
	int frequency[10] = {0};

	scanf("%d", &number);
	while (number > 0) {
		digit = number % 10;        // Extract rightmost digit
		frequency[digit]++;          // Increment frequency
		number = number / 10;        // Remove rightmost digit
	}
	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	for (int i = 0; i < 10; i++) {
		if(frequency[i] > 0) {
			printf("%d %d\n", i, frequency[i]);
		}
	}
	//@STUDENT: WRITE YOUR OUTPUT HERE:


	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}
