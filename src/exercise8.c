#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char* RLO(char* str) {
    if (str == NULL || *str == '\0') {
        char* empty = (char*)malloc(1);
        if (empty != NULL) empty[0] = '\0';
        return empty;
    }
    int total_length = 0;
    int i = 0;
    
    while (str[i]) {
        char current_char = str[i++];
        int count = 0;
        while (str[i] && isdigit(str[i])) {
            count = count * 10 + (str[i] - '0');
            i++;
        }
        
        total_length += count;
    }

    char* result = (char*)malloc(total_length + 1);
    if (result == NULL) return NULL;
    int result_index = 0;
    i = 0;
    
    while (str[i]) {
        char current_char = str[i++];
        int count = 0;
        while (str[i] && isdigit(str[i])) {
            count = count * 10 + (str[i] - '0');
            i++;
        }
        for (int j = 0; j < count; j++) {
            result[result_index++] = current_char;
        }
    }
    
    result[result_index] = '\0';
    return result;
}
char* RLE(char* str) {
    if (str == NULL || *str == '\0') {
        char* empty = (char*)malloc(1);
        if (empty != NULL) empty[0] = '\0';
        return empty;
    }
    int max_length = strlen(str) * 2 + 1;
    char* result = (char*)malloc(max_length);
    if (result == NULL) return NULL;
    
    int result_index = 0;
    int i = 0;
    
    while (str[i]) {
        char current_char = str[i];
        int count = 1;
        while (str[i + count] && str[i + count] == current_char) {
            count++;
        }
        result[result_index++] = current_char;
        char count_str[20];
        int count_len = 0;
        int temp_count = count;
        
        while (temp_count > 0) {
            count_str[count_len++] = '0' + (temp_count % 10);
            temp_count /= 10;
        }
        for (int j = count_len - 1; j >= 0; j--) {
            result[result_index++] = count_str[j];
        }
        
        i += count;
    }
    
    result[result_index] = '\0';
    return result;
}
int main(int argc, char* argv[]) {
    char str7[] = "AAABBBCC";
    char* encoded = RLE(str7);
    char* decoded = RLO(encoded);
    printf("%s\n", decoded);
    free(encoded);
    free(decoded);
}