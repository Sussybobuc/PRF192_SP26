#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
	system("cls");
	printf("INPUT:\n");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int n, invalid = 0, found = 0;
	if(scanf("%d", &n) != 1 || n <= 0) {
		invalid = 1;
	}
	int a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		found = 0;
	}
	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	if(invalid == 1) {
		printf("Invalid input");
		return 0;
	}
	for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 0) {
			printf("%d ", i);
			found = 1;
			
		} 
	}
	if(found == 0) {
		printf("Not found");
		return 0;
	}
	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}
