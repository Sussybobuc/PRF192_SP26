#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int x,y,i,sum = 0;

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  printf("\nINPUT:\n");
  scanf("%d", &x);
  scanf("%d", &y);
  for (i = x; i <= y; i++){
  	if(i%2 != 0){
  		sum += i;
	}
  }
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  if(x > y){
  return 0;
  } else{
  		printf("%d",sum);
  		return 0;
  }
  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
