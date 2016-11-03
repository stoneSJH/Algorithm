//
// Created by stoneshi on 16/9/28.
//

#include "BSearchProblems.h"

int search(int* a, int n, int target){
    if (n <= 0)
        return -1;
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high){
//        mid = (low + high) / 2;
        mid = low + ((high - low) >> 1);
        if (a[mid] == target)
            return mid;
        else if (a[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int searchFirstTarget(int* a, int n, int target){
    if (n <= 0)
        return -1;
    int low = 0;
    int high = n - 1;
    int mid;
    while (low < high){
        mid = low + ((high - low) >> 1);
        if (a[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    if (a[low] == target)
        return low;
    else
        return -1;
}

int searchLastTarget(int* a, int n, int target){
    if (n <= 0)
        return -1;
    int low = 0;
    int high = n - 1;
    int mid;
    while (low < high){
        mid = low + ((high - low + 1) >> 1);
        if (a[mid] <= target){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    if (a[low] == target)
        return low;
    else
        return -1;
}

int searchLastLessTarget(int* a, int n, int target){

}

int searchLastGreaterTarget(int* a, int n, int target){

}

int getTargetCount(int* a, int n, int target){

}

int searchOrInsertTarget(int* a, int n, int target){

}

int searchMinAbs(int* a, int n, int target){

}

int findKthIn2Arrays(int *a, int m, int* b, int n,int k) {

}

int searchInRotatedArray(int* a, int n, int target){

}

int searchMinInRotatedArray(int* a, int n){

}

int searchKthInRotatedArray(int* a, int n, int k){

}