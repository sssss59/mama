#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_anagram(char* str1, char* str2) {
    if (str1 == NULL || str2 == NULL) return 0;
    int count[256] = {0};
    char* p = str1;
    while (*p) {
        if (!isspace(*p)) {
            count[tolower(*p)]++;
        }
        p++;
    }
    p = str2;
    while (*p) {
        if (!isspace(*p)) {
            count[tolower(*p)]--;
        }
        p++;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char* argv[]) {
    char str9a[] = "listen";
    char str9b[] = "silent";
    printf("%d\n", is_anagram(str9a, str9b));
}