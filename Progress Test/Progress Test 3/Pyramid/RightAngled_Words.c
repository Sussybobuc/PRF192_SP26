#include <stdio.h>

int main() {
    char startLetter;
    int rows;
    
    // Input from user
    printf("INPUT:\n");
    scanf("%c", &startLetter);
    scanf("%d", &rows);
    
    printf("\nOUTPUT:\n");
    
    // Loop for each row
    for (int i = 0; i < rows; i++) {
        // Loop for each column in the current row
        for (int j = 0; j <= i; j++) {
            // Print the letter (starting letter + current position)
            printf("%c", startLetter + j);
            
            // Add space between letters
            if (j < i) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}