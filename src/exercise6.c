#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* get_max_length_string(char* str) {
    if (str == NULL) return NULL;
    
    char* max_word = NULL;
    int max_length = 0;
    char* current = str;
    
    while (*current) {
        while (*current && isspace(*current)) current++;
        
        if (*current == '\0') break;
        char* word_start = current;
        int word_length = 0;
        while (*current && !isspace(*current)) {
            word_length++;
            current++;
        }
        if (word_length > max_length) {
            max_length = word_length;
            max_word = word_start;
        }
    }
    if (max_word != NULL) {
        char* result = (char*)malloc(max_length + 1);
        if (result != NULL) {
            strncpy(result, max_word, max_length);
            result[max_length] = '\0';
            return result;
        }
    }
    
    return NULL;
}
int main(int argc, char* argv[]) {
    char str6[] = "The quick brown fox jumps";
    char* longest = get_max_length_string(str6);
    printf("%s\n", longest);
    free(longest);
}