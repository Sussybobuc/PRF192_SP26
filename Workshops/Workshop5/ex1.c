#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	printf("\nINPUT:\n");

	char *ptr = (char *)malloc(101 * sizeof(char));
	if (fgets(ptr, 101, stdin)) {
		*(ptr + strcspn(ptr, "\n")) = 0;
	}
	
	
	printf("\nOUTPUT:\n");
	int count = 0;
	for(int i = 0; i < 101; i++){
		if(*(ptr+i)!= '\0'){
			count++;
		} else{
			break;
		}
	}
	printf("%d", count);


	printf("\n");
	system ("pause");
	return(0);
}
