#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_palindrome(char* str) {
    if (str == NULL) return 0;
    
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        while (left < right && isspace(str[left])) left++;
        while (left < right && isspace(str[right])) right--;
        if (tolower(str[left]) != tolower(str[right])) {
            return 0;
        }
        
        left++;
        right--;
    }
    return 1;
}
int main(int argc, char* argv[]) {
    char str3[] = "A man a plan a canal Panama";
    printf("%d\n", is_palindrome(str3));
}