#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Filters the string to keep only vowel characters.
 * @param str: The input string to be processed in-place.
 */
void filterString(char str[]) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        // Chuyển ký tự hiện tại sang chữ thường để kiểm tra
        char c = tolower(str[i]);
        
        // Kiểm tra xem có phải nguyên âm không
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            str[j++] = str[i]; // Giữ lại nguyên âm tại vị trí mới
        }
    }
    str[j] = '\0'; // Quan trọng: Kết thúc chuỗi mới
}

int main() {
    system("cls");
    char input[101]; // 100 ký tự + 1 cho null terminator

    printf("INPUT:\n");
    // Sử dụng fgets thay vì scanf để cho phép nhập chuỗi có khoảng trắng
    if (fgets(input, sizeof(input), stdin)) {
        // Loại bỏ ký tự xuống dòng '\n' do fgets thu thập
        input[strcspn(input, "\n")] = 0;
    }

    // Thực hiện lọc chuỗi
    filterString(input);

    printf("OUTPUT:\n");
    printf("%s\n", input);

    //--FIXED PART
    printf("\n");
    system("pause");
    return(0);
}