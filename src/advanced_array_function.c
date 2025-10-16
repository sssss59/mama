#include "../include/advanced_array_function.h"
#include <stdio.h>
#include <stdlib.h>

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
    if(numsSize == 0){
        return 0;
    }
    int temp_c = 1;
    int c = 1;
    for(int i = 0; i < numsSize; i++){
        if(nums[i]<nums[i+1]){
            if(i == numsSize-1 && temp_c > c){
                c = temp_c;
            }
            temp_c+=1;
        }else{
            if(temp_c > c){
                c = temp_c;
            }
            temp_c = 1;
        }
    }
    return c;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // bubble sort
    for (int i = 0; i < intervalsSize - 1; i++) {
        for (int j = 0; j < intervalsSize - i - 1; j++) {
            if (intervals[j * 2] > intervals[(j + 1) * 2]) {

                int tempStart = intervals[j * 2];
                int tempEnd = intervals[j * 2 + 1];
                
                intervals[j * 2] = intervals[(j + 1) * 2];
                intervals[j * 2 + 1] = intervals[(j + 1) * 2 + 1];
                
                intervals[(j + 1) * 2] = tempStart;
                intervals[(j + 1) * 2 + 1] = tempEnd;
            }
        }
    }
    
    // временный массив для результатика
    int** tempResult = (int**)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++) {
        tempResult[i] = (int*)malloc(2 * sizeof(int));
    }
    
    int resultSize = 0;
    tempResult[resultSize][0] = intervals[0];
    tempResult[resultSize][1] = intervals[1];
    
    // алгоритм объединения
    for (int i = 1; i < intervalsSize; i++) {
        int currentStart = intervals[i * 2];
        int currentEnd = intervals[i * 2 + 1];
        int lastEnd = tempResult[resultSize][1];
       
        if (currentStart <= lastEnd) {
            if (currentEnd > lastEnd) {
                tempResult[resultSize][1] = currentEnd;
            }
        } else {
            resultSize++;
            tempResult[resultSize][0] = currentStart;
            tempResult[resultSize][1] = currentEnd;
        }
    }
    
    resultSize++;
    
    // Теперь все в один массив
    int* flatResult = (int*)malloc(resultSize * 2 * sizeof(int));
    for (int i = 0; i < resultSize; i++) {
        flatResult[i * 2] = tempResult[i][0];
        flatResult[i * 2 + 1] = tempResult[i][1];
        free(tempResult[i]);
    }
    free(tempResult);
    
    *returnSize = resultSize;
    return flatResult;
}

