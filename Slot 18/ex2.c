#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct Point {
	int x;
	int y;
} Point;

void nhapDiem(int n, Point p[]) {
	for ( int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}
}
void inDiem(int n, Point p[]) {
	for(int i = 0; i < n; i++) {
		if(p[i].y > p[i].x) {
			printf("%d %d", p[i].x, p[i].y);
			printf("\n");
		}
	}
}
int main() {
	system("cls");
	printf("INPUT:\n");
	//INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int n;
	scanf("%d", &n);
	Point p[n];

	nhapDiem(n, p );
//	for ( int i = 0; i < n; i++) {
//		scanf("%d %d", &p[i].x, &p[i].y);
//	}


	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
//	for(int i = 0; i < n; i++) {
//		if(p[i].y > p[i].x) {
//			printf("%d %d", p[i].x, p[i].y);
//			printf("\n");
//		}
//	}
	inDiem(n, p);
	//@STUDENT: WRITE YOUR OUTPUT HERE:


	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system ("pause");
	return(0);
}