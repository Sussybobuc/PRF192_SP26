#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf("\nINPUT:\n");
	
	int n;
	if(scanf("%d", &n) != 1 || n <= 0 || n > 10){
		fprintf(stderr, "Invalid input\n");
		return 1;
	}	
	char names[10][51];  
	
	for (int i = 0; i < n; i++){
		scanf("%50s", names[i]);  
	}
	
	printf("\nOUTPUT:\n");

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(names[j], names[j + 1]) > 0) {
				char temp[51];
				strcpy(temp, names[j]);
				strcpy(names[j], names[j + 1]);
				strcpy(names[j + 1], temp);
			}
		}
	}

	for (int i = 0; i < n; i++){
		printf("%s\n", names[i]);
	}

	printf("\n");
	system ("pause");
	return(0);
}
