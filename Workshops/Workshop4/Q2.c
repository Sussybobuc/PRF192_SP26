#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
	system("cls");
	printf("INPUT:\n");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	float x1,y1,x2,y2, d;
	if(scanf("%f %f", &x1, &y1) != 2){
		printf("Invalid input");
		return 0;
	} fflush(stdin);
	if(scanf("%f %f", &x2, &y2) != 2){
		printf("Invalid input");
		return 0;
	}
	d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	// Fixed Do not edit anything here.
	printf("OUTPUT:\n");
	if(d == 0){
		printf("%.4f", d);
		printf("\nPoints are coincident");
		return 0;
	} else {
		printf("%.4f", d);
		return 0;
	}


	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	system ("pause");
	return(0);
}
