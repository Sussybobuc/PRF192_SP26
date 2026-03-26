#include <stdio.h>

int main() {
    char startLetter;
    int rows;
    
    // Input from user
    printf("INPUT:\n");
    scanf("%d", &rows);
    
    printf("\nOUTPUT:\n");
    
    // Loop for each row
    for (int i = 0; i < rows; i++) {
        // Loop for each column in the current row
        for (int j = 0; j <= i; j++) {
            // Print number that cycles 1, 2, 3
            printf("%d", (j % 3) + 1);
            
            // Add space between numbers
            if (j < i) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}