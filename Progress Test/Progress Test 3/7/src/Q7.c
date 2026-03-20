#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int is_prime(int n) {
    int i;
    if (n < 2) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
	system("cls");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	printf("INPUT:\n");

	int n, flag = 0;
	if(scanf("%d", &n) != 1|| n < 0|| n > 100){
		flag = 1;
	}

	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	if(flag == 1){
		printf("Invalid input");
	}else {
		int count = 0;
		int i = n + 1;
		while(count < 4) {
			if(is_prime(i) == 1) {
				printf("%d ", i);
				count++;
			}
			i++;
		}
	}


	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}
