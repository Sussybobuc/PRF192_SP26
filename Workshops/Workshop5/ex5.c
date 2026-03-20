#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(){
	
	printf("\nINPUT:\n");

	char *ptr = (char *)malloc(101 * sizeof(char));
	if (fgets(ptr, 101, stdin)) {
		*(ptr + strcspn(ptr, "\n")) = 0;
	}
	char findC, replaceC;
	scanf("%c", &findC);
	fflush(stdin);
	scanf("%c", &replaceC);
	

	printf("\nOUTPUT:\n");
	int count = 0;
	for(int i = 0; ptr[i] !='\0'; i++){
		if(ptr[i] == findC){
			ptr[i] = replaceC;
			count++;
		}
	}
	printf("%d", count);
	printf("\n%s", ptr);

	printf("\n");
	system ("pause");
	return(0);
}
