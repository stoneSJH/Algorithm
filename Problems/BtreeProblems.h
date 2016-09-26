//
// Created by stoneshi on 16/9/24.
//

#ifndef CLIONTEST001_BTREEPROBLEMS_H
#define CLIONTEST001_BTREEPROBLEMS_H
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <math.h>
using namespace std;

struct BtreeNode{
    int key;
    BtreeNode* left;
    BtreeNode* right;
};

void printTree(BtreeNode* root);
int getNodeNumber(BtreeNode* root);
int getDepth(BtreeNode* root);
void levelTraverse(BtreeNode* root);
void postOrderTraverse(BtreeNode* root);
void preOrderTraverse(BtreeNode* root);
void inOrderTraverse(BtreeNode* root);
int getNodeNumberInKthLevel(BtreeNode* root, int k);
int getLeafNodeNumber(BtreeNode* root);
bool structureCmp(BtreeNode* root1, BtreeNode* root2);
bool isAVLTree(BtreeNode* root, int &height);
BtreeNode* mirror(BtreeNode* root);//change left to right
BtreeNode* getLastCommonAncestor(BtreeNode* root, BtreeNode* node1, BtreeNode* node2);
BtreeNode* getLastCommonAncestor2(BtreeNode* root, BtreeNode* node1, BtreeNode* node2);
int getMaxDistance(BtreeNode* root, int& maxLeft, int& maxRight);
BtreeNode* rebuildBtreeByPreAndIn(int* preOrder, int* inOrder, int nodeNum);
BtreeNode* rebuildBtreeByInAndPost(int* inOrder, int* postOrder, int nodeNum);
bool isCompleteBtree(BtreeNode* root);

//BST
void convertBSTtoLinkList(BtreeNode* root, BtreeNode* pFirstNode, BtreeNode* pLastNode);

#endif //CLIONTEST001_BTREEPROBLEMS_H
