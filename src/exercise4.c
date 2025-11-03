#include <stdio.h>
#include <stdlib.h>

int get_greater_freq(int* arr, size_t size){
    // сначала у чего а потом сколько
    int temp[2] = {0, 0};
    for(int i = 0; i < size; i++){
        int c = 0;
        for(int j = 0; j < size; j++){
            if(arr[i] == arr[j]){
                c++;
            }
        }
        if(c > temp[1]){
            temp[0] = arr[i];
        }
    }
    return temp[0];
}

int main(int argc, char* argv){
    int array[11] = {11, 22, 3, 5, 6, 7, 8, 10, 11 , 11, 11};
    printf("%d", get_greater_freq(array, 11));
}