#include <stdio.h>
#include <stdlib.h>

void remove_gt_one(float* arr, size_t size){
    int res[size];
    //mod
    for(int i = 0; i < size; i++){
        if(arr[i]< 0){
            arr[i] = (-1) * arr[i];
        }
    }
    //algorithm
    int c_of_zero = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] <= 1){
            arr[i] = 0;
        }
        if(arr[i] == 0){
            c_of_zero += 1;
        }
    }
    int normal_num = size - c_of_zero;
    int temp_n = 0;
    int temp_z = c_of_zero;
    int i = 0;
    while(i < size && temp_n < normal_num){
        if(arr[i] > 1){
            res[temp_n] = arr[i];
            temp_n++;
        }
        i++;
    }
    i = size - c_of_zero + 1;

    while(i < size){
        res[i] = 0;
        i++;
    }
    for(int i = 0; i < size; i++){
        printf("%d\n", res[i]);
    }
}

int main(int argc, char* argv){
    float array[7] = {-0.99, -2, -5, 6, -0.5, 2 ,4};
    remove_gt_one(array, 7);
}