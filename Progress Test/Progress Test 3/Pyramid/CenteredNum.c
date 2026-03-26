#include <stdio.h>

int main() {
    int rows;
    
    // Input from user
    printf("INPUT:\n");
    scanf("%d", &rows);
    
    printf("\nOUTPUT:\n");
    
    // Loop for each row
    for (int i = 0; i < rows; i++) {
        // Print leading spaces for centering
        for (int space = 0; space < rows - i - 1; space++) {
            printf(" ");  // Space for alignment
        }
        
        // Print numbers
        for (int j = 0; j <= i; j++) {
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