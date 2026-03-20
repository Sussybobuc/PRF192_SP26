#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int findLargestEvenNumber(int a[], int n) {
	int max_even = 0;
	int i, found = 0;
	for (i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			if (!found) {
				max_even = a[i];
				found = 1;
			} else {
				if (a[i] > max_even) {
					max_even = a[i];
				}

			}
		}
	}
	return max_even;
}

int main() {
	system("cls");
	printf("INPUT:\n");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int n, flag = 0;
	if(scanf("%d", &n) != 1 || n < 0) {
		flag = 1;
		n = 0;
	}
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	if(flag == 1) {
		printf("Invalid input");
	} else {
		int result = findLargestEvenNumber(a, n);
		if(result != 0) {
			printf("%d", result);
		} else {
			printf("There are no even numbers in %d elements", n);
		}

	}



	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}
