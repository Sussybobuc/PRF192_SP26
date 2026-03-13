// function swap 2 int
// function swap 3 int [ 1 to 3, 2 to 1, 3 to 2 ]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int swap2(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int swap3(int *a, int *b, int *c) {
	int temp = *a;
	int temp2 = *b;
	*a = *c;
	*b = temp;
	*c = temp2;


}
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	swap2(&a,&b);
	printf("%d %d", a, b);
	swap3(&a,&b,&c);
	printf("\n%d %d %d", a, b, c);

}