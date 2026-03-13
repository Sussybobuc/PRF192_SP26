#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
	system("cls");
	char str[101];
	//@STUDENT:ADD YOUR CODE FOR INPUT HERE:
	printf("\nINPUT:\n");
	if (fgets(str, sizeof(str), stdin)) {
		str[strcspn(str, "\n")] = 0;
	}
	int len = strlen(str);

	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	printf("Reverse string: ");
	for(int i = len - 1; i >=0; i--) {
		if(str[i] != ' ') {
			printf("%c", str[i]);
		}
	}

	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}