#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    int k = atoi(argv[1]);
    float arr[10];
    float arr1[10];
    for(int i = 0; i < 10;i++){
        scanf("%f", &arr[i]);
    }
    if (k >= 0){
        for (int i = 0; i < 10; i++){
            if(i+k >= 10){
                arr1[i+k-10] = arr[i];
            }
            else{
                arr1[i+k]=arr[i];
            }
        }
    }
    else if( k < 0){
        for ( int i = 0; i<10; i++){
            if(i+k < 0){
                arr1[10+k+i] = arr[i];
            }
            else{
                arr1[i+k] = arr[i];
            }
        }
    }
    for(int i = 0; i < 10; i++){
        printf("%.2f ", arr1[i]);

    }
    

    return 0;
}