#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
	system("cls");
	printf("INPUT:\n");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int n, space, k = 0, checked = 1;
	if(scanf("%d", &n) != 1 || n < 2) {
		checked = 0;
	}


	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	if(checked == 0) {
		printf("Invalid input");
		return 0;
	}
	for(int i = 1; i <= n; ++i, k = 0) {
		for(space = 1; space <= n - i; ++space) {
			printf(" ");
		}
		while( k != 2* i -1) {
			printf("*");
			++k;
		}
		printf("\n");
	}




//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}
