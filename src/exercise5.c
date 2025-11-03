#include <stdio.h>
#include <stdlib.h>

int get_greater_series(int* arr, size_t size){
    int cur_el = arr[0];
    int max_el = arr[0];
    int cur_len = 1;
    int max_len = 1;
    for(int i = 1; i < size; i++){
        if(arr[i] == cur_el){
            cur_len++;
        }
        else{
            if(cur_len > max_len){
                max_len = cur_len;
                max_el = cur_el;
            }
            cur_el = arr[i];
            cur_len = 1;
        }
        
    }
    if(cur_len > max_len){
        max_el = cur_el;
    }
    return max_el;
}

int main(int argc, char* argv){
    int arr1[10] = {1,1,1,2,2,3,4,4,4,4};
    printf("%d", get_greater_series(arr1, 10));
}