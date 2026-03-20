#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	printf("\nINPUT:\n");
	
	char str[101];
	if (fgets(str, 101, stdin)) {
		*(str + strcspn(str, "\n")) = 0;  
	}
	
	printf("\nOUTPUT:\n");

	int digits = 0;
	int letters = 0;
	int others = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isdigit(str[i])) {
			digits++;
		} else if (isalpha(str[i])) {
			letters++;
		} else {
			others++;
		}
	}
	printf("%d\n", digits);
	printf("%d\n", letters);
	printf("%d\n", others);

	printf("\n");
	system ("pause");
	return(0);
}
