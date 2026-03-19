#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int x;
	int y;
}
Point;

int main() {
	system("cls");
	printf("INPUT:\n");
	
	Point pt;
	pt.x = 5;
	pt.y = 10;
	Point pt2;
	scanf("%d%d", &pt2.x, &pt2.y);
	printf("\nOUTPUT:\n");
	printf("%d, %d\n", pt.x, pt.y);
	printf("%d, %d", pt2.x, pt2.y);
	
	
	
	printf("\n");
	system ("pause");
	return(0);

}