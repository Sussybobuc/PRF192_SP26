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
            printf(" ");
        }
        
        // Print asterisks
        for (int j = 0; j <= i; j++) {
            printf("*");
            
            // Add space between asterisks
            if (j < i) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}