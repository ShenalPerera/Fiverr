#include "binary_search.h"

int binary_search(const int array[], int high, int key){
    int min_index = 0;
    int mid_num;
    int n=-1;

    while(min_index <= high){
        mid_num = (min_index + high) / 2;

        if( array[mid_num] == key ){
            n = mid_num;
            break;
        }else if ( array[mid_num] < key){
            min_index = mid_num + 1;
        }else{
            high = mid_num -1;
        }
    }
    return n;
}