#include <stdio.h>
#include <string.h>

void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main(int argc, char* argv[]) {
    char s[] = "Hello World";
    printf("Было: %s\n", s);
    reverse_string(s);
    printf("Стало: %s\n", s);
    return 0;
}