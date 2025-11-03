#include <stdio.h>
#include <string.h>

char* my_strstr(char* str, char* substr) {
    if (*substr == '\0') return str;
    
    char* start = str;
    while (*start) {
        char* s1 = start;
        char* s2 = substr;
        
        while (*s1 && *s2 && *s1 == *s2) {
            s1++;
            s2++;
        }
        
        if (*s2 == '\0') return start;
        start++;
    }
    
    return NULL;
}
int main(int argc, char* argv){
    char str1[] = "Hello World";
    printf("%s\n", my_strstr(str1, "World"));
}