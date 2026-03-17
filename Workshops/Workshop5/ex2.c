#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
	system("cls");
	//@STUDENT:ADD YOUR CODE FOR INPUT HERE:
	printf("\nINPUT:\n");
	char *ptr = (char *)malloc(101 * sizeof(char));
	if (fgets(ptr, 101, stdin)) {
		*(ptr + strcspn(ptr, "\n")) = 0;
	}
	int len = strlen(ptr);

	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	for(int i = len - 1; i >=0; i--) {
		printf("%c", *(ptr + i));
	}

	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}