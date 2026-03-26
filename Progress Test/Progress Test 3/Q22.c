#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
	system("cls");
	printf("INPUT:\n");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	
	float r, pi = 3.14159;
	scanf("%f", &r);
	


	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	printf("%.3f", (2 * pi * r));
	printf("\n%.3f", (pi * (r * r)));


	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}
