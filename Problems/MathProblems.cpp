//
// Created by stoneshi on 16/9/24.
//
#include "MathProblems.h"

int whichPrime(long num){
    if (num < 2)
        return -1;
    if (num < 4 && num >= 2)
        return (int)num - 1;
    vector<int> numberMap((unsigned long)num-1, 1);
    for (int i = 2; i * i <= num; i++){
        if (numberMap[i - 2]){
            for (int j = i * i; j <= num; j += i)
                numberMap[j - 2] = 0;
        }
    }
    if (!numberMap[num - 2])
        return -1;
    else{
        int result = 0;
        for (int i = 2; i <= num; i++)
            result += numberMap[i - 2];
        return result;
    }
}
