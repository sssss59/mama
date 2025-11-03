#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* int_to_string(int number) {
    int temp = number;
    int length = 0;
    if (temp <= 0) {
        length = 1;
        temp = -temp;
    }
    
    while (temp > 0) {
        length++;
        temp /= 10;
    }
    
    char* result = (char*)malloc(length + 1);
    if (result == NULL) return NULL;
    int index = 0;
    
    if (number < 0) {
        result[index++] = '-';
        number = -number;
    } else if (number == 0) {
        result[index++] = '0';
    }
    char buffer[20];
    int buffer_index = 0;
    
    while (number > 0) {
        buffer[buffer_index++] = '0' + (number % 10);
        number /= 10;
    }
    for (int i = buffer_index - 1; i >= 0; i--) {
        result[index++] = buffer[i];
    }
    
    result[index] = '\0';
    return result;
}
int main(int argc, char* argv[]) {
    char* str4 = int_to_string(-12345);
    printf("%s\n", str4);
    free(str4);
}