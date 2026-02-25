#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int n,i;
float S = 0, temp = 1;

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  printf("\nINPUT:\n");
  scanf("%d", &n);
  for(i = 1; i <= n; i++){
  	temp *= i;
  	S += 1.0 / temp;
  }
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  if(n < 0){
  	printf("Error: n must be greater than 0.");
  	return 0;
  } else{
  	printf("%.3f", S);
  	return 0;
  }
  
  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
