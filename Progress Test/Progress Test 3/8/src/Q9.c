#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
void upper(char *s) {
    int in_word = 0;
    int word_char_count = 0;
    
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] != ' ') {
            if(!in_word) {
                in_word = 1;
                word_char_count = 0;
            }
            
            if(word_char_count < 2) {
                s[i] = toupper(s[i]);
                word_char_count++;
            }
        } 
        else {
            in_word = 0;
            word_char_count = 0;
        }
    }
}
int main() {

	printf("\nINPUT:\n");
	char *s = (char *)malloc(101 * sizeof(char));
	if (fgets(s, 101, stdin)) {
		*(s + strcspn(s, "\n")) = 0;
	}

	printf("\nOUTPUT:\n");
	upper(s);
	printf("%s", s);
	printf("\n");
	system ("pause");
	return(0);
}
	