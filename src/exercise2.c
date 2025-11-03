#include <stdio.h>
#include <stdlib.h>

int is_alternating(int* arr, size_t size){
    /*
    я прогуглил и если я правильно понял, 
    занкопеременный ряд это когда в последовательности есть числа разного знака
    не важно в каком количестве и в каком порядке
    */
   int count_of_pol_num = 0;
   int count_of_otr_num = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > 0){
            count_of_pol_num += 1;
        }
        else{
            count_of_otr_num += 1;
        }
    }
    if(count_of_otr_num > 0 && count_of_pol_num > 0){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char* argv){
    int array1[5] = {1, 2, 3, 5, 6};
    int array2[5] = {1, 2, 3, 5, -6};
    int array3[5] = {-1, -2, -3, -5, -6};
    printf("%d\n", is_alternating(array1, 5));
    printf("%d\n", is_alternating(array2, 5));
    printf("%d\n", is_alternating(array3, 5));
}