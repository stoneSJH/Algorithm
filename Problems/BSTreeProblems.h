//
// Created by stoneshi on 16/9/28.
//

#ifndef PROBLEMS_BSTREEPROBLEMS_H
#define PROBLEMS_BSTREEPROBLEMS_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <stack>
using namespace std;

struct BstreeNode{
    int key;
    int height = 0;
    BstreeNode* left;
    BstreeNode* right;
};

bool check(BstreeNode* root);
bool checkAVL(BstreeNode* root);
void setHeight(BstreeNode* root);
void printTree(BstreeNode* root);
BstreeNode* find(BstreeNode* root, int key);
BstreeNode* leftRotate(BstreeNode* root);
BstreeNode* rightRotate(BstreeNode* root);
BstreeNode* lrRotate(BstreeNode* root);
BstreeNode* rlRotate(BstreeNode* root);
BstreeNode* insert(BstreeNode* root, int key);
BstreeNode* remove(BstreeNode* root, int key);
BstreeNode* remove(BstreeNode* root, BstreeNode* key);
BstreeNode* rebuildAVLFromBST(BstreeNode* root);
BstreeNode* rebuildAVLFromBT(BstreeNode* root);
#endif //PROBLEMS_BSTREEPROBLEMS_H
