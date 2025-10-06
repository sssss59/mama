#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    float arr[10];
    float s = 0;
    for (int i = 0; i<10;i++){
        scanf("%f", &arr[i]);
    }
    for(int i = 0; i < 10; i++){
        s += arr[i];
    }
    float res = s/10;
    printf("%.2f", res);

    return 0;
}