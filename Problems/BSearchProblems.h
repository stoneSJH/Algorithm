//
// Created by stoneshi on 16/9/28.
//

#ifndef PROBLEMS_BSEARCHPROBLEMS_H
#define PROBLEMS_BSEARCHPROBLEMS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int search(int* a, int n, int target);
int searchFirstTarget(int* a, int n, int target);
int searchLastTarget(int* a, int n, int target);
int searchLastLessTarget(int* a, int n, int target);
int searchLastGreaterTarget(int* a, int n, int target);
int getTargetCount(int* a, int n, int target);
int searchOrInsertTarget(int* a, int n, int target);
int searchMinAbs(int* a, int n, int target);
int findKthIn2Arrays(int *a, int m, int* b, int n,int k);//k th element in merged array
int searchInRotatedArray(int* a, int n, int target);//array a ha been rotated
int searchMinInRotatedArray(int* a, int n);
int searchKthInRotatedArray(int* a, int n, int k);


#endif //PROBLEMS_BSEARCHPROBLEMS_H
