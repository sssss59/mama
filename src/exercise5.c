#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int string_to_int(char* str) {
    if (str == NULL) return 0;
    
    int result = 0;
    int sign = 1;
    int i = 0;
    while (isspace(str[i])) i++;
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return result * sign;
}
int main(int argc, char* argv[]) {
    printf("%d\n", string_to_int(" -456 "));
}