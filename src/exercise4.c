#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    float arr[10];
    float arr1[10];
    float x = atoi(argv[1]);
    int k = atoi(argv[2]);
    for( int i = 0;i < 10; i++){
        scanf("%f", &arr[i]);
    }
    for(int i = 0; i < 10; i++){
        if (i < k){
            arr1[i] = arr[i];
        }else if( i == k){
            arr1[i] = x;
        }
        else{
            arr1[i] = arr[i-1]; 
        }
    }
    for(int i = 0; i < 10; i++){
        printf("%.2f ", arr1[i]);
    }
    return 0;
}