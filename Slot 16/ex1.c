#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int VowelCount(char input[]) {
	int vowels = 0;
	int len = strlen(input);
	for(int i = 0; i < len; i++) {
		char c = tolower(input[i]);
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o') {
			vowels++;
		}
	}
	return vowels;
}

int main() {
	system("cls");
	char str[101];
	//@STUDENT:ADD YOUR CODE FOR INPUT HERE:
	printf("\nINPUT:\n");
	if (fgets(str, sizeof(str), stdin)) {
		str[strcspn(str, "\n")] = 0;
	}

	int vowels = VowelCount(str);

	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:

	printf("Vowels: %d\n", vowels);

	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}