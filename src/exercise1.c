#include <stdio.h>
#include <stdlib.h>

int get_second_max(int* arr, size_t size){
    int max1 = arr[0];
    int max2 = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max1){
            max1 = arr[i];
        }
    }
    for(int i = 1; i < size; i++){
        if(arr[i] > max2 && arr[i] < max2){
            max2 = arr[i];
        }
    }
    return max2;
}

int main(int argc, char* argv){
    int array[8] = {11, 22, 3, 5, 6, 7, 8, 10};
    int res = get_second_max(array, 8);
    printf("%d", res);
}