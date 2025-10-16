#include "../include/advanced_array_function.h"

int max_subarray_sum(int* nums, int size) {
    int max_sum = -2147483648;
    if(size == 0){
        return 0;
    }
    for(int l = 0; l < size; l++){
        for(int r = l; r < size; r++){
            int temp_sum = 0;
            int temp = l;
            while(temp <= r){
                temp_sum+= nums[temp];
                temp++;
            }
            if(temp_sum > max_sum){
                max_sum = temp_sum;
            }
        }
    }
    return max_sum;
}

int length_of_lis(int* nums, int numsSize) {
    int c = 1;
    int temp_s = 1;
    for(int l = 0; l < numsSize - 1; l++){
        if(nums[l] < nums[l+1]){
            temp_s+=1;
        }
        else{
            temp_s=1;
            if(temp_s > c){
                c = temp_s;
            }
        }
    }
    return c;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    printf("hz");
    return NULL;

}

