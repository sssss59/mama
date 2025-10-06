#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    float arr[10];
    for(int i=0; i < 10; i++){
        scanf("%f", &arr[i]);
    }
    for(int j = 9; j >= 0; j--){
        printf("%.3f ", arr[j]);
    }
    return 0;
}