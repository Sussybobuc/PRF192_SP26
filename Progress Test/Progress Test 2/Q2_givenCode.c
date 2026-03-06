#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Function to check if a number is a prime number
int isPrime(int n) {
	//@STUDENT: WRITE YOUR CODE HERE
	if(n < 2) {
		return 0;
	}
	if(n == 2) {
		return 1;
	}
	if(n % 2 == 0) {
		return 0;
	}
	for(int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;

}

// Function to count prime number numbers in an array
int countPrimes(int arr[], int size) {
	//@STUDENT: WRITE YOUR CODE HERE
	int count = 0;
	for(int i = 0; i < size; i++) {
		if( arr[i] != 2 && arr[i] % 2 == 0) {
			continue;
		}
		if(isPrime(arr[i]) == 1) {
			count++;
		}
	}
	return count;

}

int main() {
	system("cls");

	// Fixed Do not edit anything here.
	printf("INPUT:\n");
	//@STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int n, invalid = 0;
	if(scanf("%d", &n) != 1 || n <= 0) {
		invalid = 1;
	}
	int a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int result = countPrimes(a,n);
	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	if(invalid == 1) {
		printf("Invalid input");
		return 0;
	}
	if(invalid == 0) {
		printf("%d", result);
		return 0;
	}


	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}