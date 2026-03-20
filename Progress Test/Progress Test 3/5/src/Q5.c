#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int findDifference(int arr[], int n) {
//@STUDENT:ADD YOUR CODE
	int max = 0, min = 0, result;
	for (int i = 0; i < n; i++) {
		if(max < arr[i]) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
		result = max - min;
	} return result;

}

int main() {
	system("cls");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	printf("INPUT:\n");
	int n, flag = 0;
	if(scanf("%d", &n) != 1 || n < 0) {
		flag = 1;
		n = 0;
	}
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:

	if(flag == 1) {
		printf("Invalid input");
	} else{
		printf("%d", findDifference(arr,n));
	}

	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}
