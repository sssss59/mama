#include "../include/array_function.h"

void join_int_arrays(int *src1, size_t size_src1, int *src2, size_t size_src2, int *dest) {
    for(size_t i = 0; i < size_src1; i++){
        dest[i] = src1[i];
    }
    for(size_t i = size_src1; i < size_src1+size_src2; i++){
        dest[i] = src2[i-size_src1];
    }
}

void join_and_sort_int_arrays(int* src1, size_t size_src1, int* src2, size_t size_src2, int* dest) {
    int array[size_src1+size_src2];
    if (size_src1 > size_src2){
        for(size_t i = 0; i < size_src2; i++){
            if(src1[i] < src2[i]){
                array[i] = src1[i];
            }else if(src1[i] == src2[i]){
                array[i] = src1[i];
                array[i+1] = src2[i];
                i++;
            }else if(src1[i] > src2[i]){
                array[i] = src2[i];
            }
        }
        size_t m = size_src1 - size_src2;
        for(size_t i = 0; i < m; i++){
            array[size_src2 + i] = src1[size_src2 + i];
        }
    }else if(size_src1 == size_src2){
        for(size_t i = 0; i < size_src2; i++){
            if(src1[i] < src2[i]){
                array[i] = src1[i];
            }else if(src1[i] == src2[i]){
                array[i] = src1[i];
                array[i+1] = src2[i];
                i++;
            }else if(src1[i] > src2[i]){
                array[i] = src2[i];
            }
        }
    }else if(size_src1 < size_src2){
        for(size_t i = 0; i < size_src1; i++){
            if(src2[i] < src1[i]){
                array[i] = src2[i];
            }else if(src1[i]==src2[i]){
                array[i] = src1[i];
                array[i+1] = src2[i];
                i++;
            }else if(src2[i]>src1[i]){
                array[i] = src1[i];
            }
        }
        size_t m = size_src2 - size_src1;
        for(size_t i = 0; i < m; i++){
            array[size_src1 + i] = src1[size_src1 + i];
        }
    }
    for(int i = 0; i < sizeof(array)/sizeof(int); i++){
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

