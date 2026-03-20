#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
void find_max_min_even(int* arr, int n, int* max_even, int* min_even, int* pos_max, int* pos_min) {
	int i, found = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			if (!found) {
				*max_even = *min_even = arr[i];
				*pos_max = *pos_min = i + 1;
				found = 1;
			} else {
				if (arr[i] > *max_even) {
					*max_even = arr[i];
					*pos_max = i + 1;
				}
				if (arr[i] < *min_even) {
					*min_even = arr[i];
					*pos_min = i + 1;
				}
			}
		}
	}
}
void swap(int* pos_max, int* pos_min) {
	int temp = *pos_max;
	*pos_max = *pos_min;
	*pos_min = temp;
}
int main() {
	system("cls");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	printf("INPUT:\n");
	int n, flag = 0;
	int max_even, min_even, pos_max, pos_min;

	if(scanf("%d", &n) != 1 || n < 0) {
		flag = 1;
		n = 0;
	}
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	max_even = 0;
	min_even = 0;
	pos_max = -1;
	pos_min = -1;
	find_max_min_even(arr, n, &max_even, &min_even, &pos_max, &pos_min);
	if(flag == 1) {
		printf("Invalid input");
	} else {
		swap(&arr[pos_max - 1],&arr[pos_min - 1]);
		for( int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
	}

	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}
