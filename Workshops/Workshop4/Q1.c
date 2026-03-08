#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
	system("cls");
	printf("INPUT:\n");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	float a, b;
	int check = 0;
	if(scanf("%f %f", &a, &b) != 2){
		check = 1;
	}

	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	if(check == 1){
		printf("Invalid input");
		return 0;
	}
	float result = (float)(pow(a, 2) + pow(b, 2));
	printf("%.2f", cbrt(result));
	return 0;


	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}

