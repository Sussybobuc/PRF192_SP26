#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

float a,b;

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  printf("\nINPUT:\n");
  scanf("%f", &a);
  fflush(stdin);
  scanf("%f", &b);
	
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  if(a == 0){
  	printf("Error: Division by zero");
  	return 0;
  } else{
  	b = -b;
  	printf("%.3f", cbrt(b / a));
  	return 0;
  }
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
