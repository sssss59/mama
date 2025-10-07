#include "../include/array_function.h"

void join_int_arrays(int *src1, size_t size_src1, int *src2, size_t size_src2, int *dest) {
    dest[size_src1+size_src2];
    for(int i = 0; i < size_src1; i++){
        dest[i] = src1[i];
    }
    for(int i = size_src1; i < size_src1+size_src2; i++){
        dest[i] = src2[i];
    }
}

void join_and_sort_int_arrays(int* src1, size_t size_src1, int* src2, size_t size_src2, int* dest) {
    dest[size_src1+size_src2];
    int array[size_src1+size_src2];
    int i = 0;
    int j = 0;
    int c = 0;
    while(i < size_src1 && j < size_src2){
        if(src1[i] <= src2[j]){
            array[c] = src1[i];
        }else{
            array[c] = src2[j];
        }
        i++;
        j++;
        c++;
    }
    while(i < size_src1){
        array[c] = src1[i];
        c++;
        i++;
    }
    while(j < size_src2){
        array[c] = src2[j];
        c++;
        j++;
    }
    for(int i = 0; i < size_src1+size_src2; i++){
        dest[i] = array[i];
    }
}

void get_min_and_max_from_int_array(int* src, size_t size, int* min, int* max) {
    *min = src[0];
    *max = src[0];
    for(size_t i = 1; i < size; i++){
        if(src[i] < *min){
            *min = src[i];
        }
    }
    for(size_t i = 1; i < size; i++){
        if(src[i] > *max){
            *max = src[i];
        }
    }

}

