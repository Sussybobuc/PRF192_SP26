#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() {
	system("cls");
	printf("INPUT:\n");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int n, checked = 1, found = 0;
	if(scanf("%d", &n) != 1 || n < 0) {
		checked = 0;
	}
	int a[n];
	if(checked != 0) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
	}
	// Fixed Do not edit anything here.
	printf("OUTPUT:\n");
	if(checked == 0) {
		printf("Invalid input");
		return 0;
	}

	for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 0) {
			int dup = 0;
			for(int k = 0; k < i; k++) {
				if(a[i] == a[k]) {
					dup = 1;
					break;
				}
			}
			if(!dup) {
				int count = 0;
				for(int j = 0; j < n; j++) {
					if(a[i] == a[j])
						count++;
				}
				printf("%d-%d\n", count, a[i]);
				found = 1;
			}

		}
	}



	if(found == 0) {
		printf("Not found");
		return 0;
	}

	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	system ("pause");
	return(0);
}
