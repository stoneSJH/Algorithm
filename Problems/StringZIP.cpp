//
// Created by stoneshi on 16/9/23.
//
#include "StringZIP.h"

string stringZIP(string input){
    map<char, int> charMap;
    for (char i = 'a'; i < 'z'; i++){
        charMap[i] = 0;
    }
    for (int i = 0; i < input.length(); i++){
        charMap[input[i]] += 1;
    }
    map<char, int>::iterator it = charMap.begin();
    string ret;
    for(; it != charMap.end(); it++) {
        if (it->second != 0) {
            stringstream ss;
            string cur;
            ss << it->second;
            ss >> cur;
            ret += cur + it->first;
        }
    }
    return ret;
}