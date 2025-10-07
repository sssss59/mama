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
    size_t i = 0, j = 0, k = 0;
    while (i < size_src1 && j < size_src2) {
        if (src1[i] <= src2[j]) {
            dest[k] = src1[i];
            k++;
            i++;
        } else {
            dest[k] = src2[j];
            k++;
            j++;
        }
    }
    while (i < size_src1) {
        dest[k] = src1[i];
        k++;
        i++;
    }
    while (j < size_src2) {
        dest[k] = src2[j];
        k++;
        j++;
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

