#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>



char is_palindrome_string(char* s) {
	size_t left = 0;
	size_t right = strlen(s);
	if (right == 0) {
		return 1;
	}
	--right;
	while (left < right) {
		if (s[left] != s[right]) {
			return 0;
		}
		++left;
		--right;
	}
	return 1;
}

int main() {
	printf("\nINPUT:\n");

	char *s = (char *)malloc(101 * sizeof(char));
	if (fgets(s, 101, stdin)) {
		*(s + strcspn(s, "\n")) = 0;
	}
	printf("\nOUTPUT:\n");

	int result = (is_palindrome_string(s));
	if (result == 1) {
		printf("Yes");
	} else {
		printf("No");
	}
	printf("\n");
	system ("pause");
	return(0);
}