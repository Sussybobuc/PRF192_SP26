#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() {

	printf("\nINPUT:\n");

	char *ptr = (char *)malloc(101 * sizeof(char));
	if (fgets(ptr, 101, stdin)) {
		*(ptr + strcspn(ptr, "\n")) = 0;
	}


	printf("\nOUTPUT:\n");
	int count = 0;
	int in_word = 0;  
	for(int i = 0; ptr[i] != '\0'; i++) {
		if(ptr[i] != ' ') {
			if(!in_word) {
				count++;
				in_word = 1;
			}
		} else {
			in_word = 0;
		}
	}
	

	printf("%d", count);

	printf("\n");
	system ("pause");
	return(0);
}