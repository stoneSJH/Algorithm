//
// Created by stoneshi on 16/9/24.
//

#include "BtreeProblems.h"

void printTree(BtreeNode* root){
    int depth = getDepth(root);
    queue<BtreeNode *> nodeQ;
    queue<int> levelQ;
    queue<int> positionQ;
    nodeQ.push(root);
    levelQ.push(0);
    positionQ.push(0);
    int lastLevel = 0;
    int lastPosition = -1;
    while (!nodeQ.empty()) {
        BtreeNode *cur = nodeQ.front();
        int level = levelQ.front();
        int position = positionQ.front();
        if (lastLevel < level) {
            lastLevel = level;
            lastPosition = -1;
            cout << endl;
        }
        if (lastPosition == -1 && position != 0){
            for (int i = 1; i <= position; i++) {
                for (int j = 0; j < pow(2, (depth - level)); j++) {
                    cout << " ";
                }
            }

            for (int j = 0; j < pow(2, (depth - level)) / 2; j++){
                cout << " ";
            }
        }
        else if (lastPosition == -1 && position == 0){
            for (int i = 0; i <= position; i++) {
                for (int j = 0; j < pow(2, (depth - level)) / 2; j++) {
                    cout << " ";
                }
            }
        }
        else{
            for (int i = 0; i < (position - lastPosition); i++) {
                for (int j = 0; j < pow(2, (depth - level)); j++) {
                    cout << " ";
                }
            }
        }
        cout << cur->key;
        lastPosition = position;
        nodeQ.pop();
        levelQ.pop();
        positionQ.pop();
        if (cur->left != NULL) {
            nodeQ.push(cur->left);
            levelQ.push(level + 1);
            positionQ.push(position * 2);
        }
        if (cur->right != NULL) {
            nodeQ.push(cur->right);
            levelQ.push(level + 1);
            positionQ.push(position * 2 + 1);
        }
    }
    cout << endl;
}

int getNodeNumber(BtreeNode* root){
    if (root == NULL)
        return 0;
    return getNodeNumber(root->left) + getNodeNumber(root->right) + 1;
}

int getDepth(BtreeNode* root){
    if (root == NULL)
        return 0;
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

void levelTraverse(BtreeNode* root) {
    queue<BtreeNode *> nodeQ;
    queue<int> levelQ;
    nodeQ.push(root);
    levelQ.push(1);
    int lastLevel = 1;
    while (!nodeQ.empty()) {
        BtreeNode *cur = nodeQ.front();
        int level = levelQ.front();
        if (lastLevel < level) {
            lastLevel = level;
            cout << endl;
        }
        cout << cur->key << endl;
        nodeQ.pop();
        levelQ.pop();
        if (cur->left != NULL) {
            nodeQ.push(cur->left);
            levelQ.push(level + 1);
        }
        if (cur->right != NULL) {
            nodeQ.push(cur->right);
            levelQ.push(level + 1);
        }
    }
    cout << endl;
}

void postOrderTraverse(BtreeNode* root){
    if (root == NULL)
        return;
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->key << " ";
    return;
}
void preOrderTraverse(BtreeNode* root){
    if (root == NULL)
        return;
    cout << root->key << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
    return;
}
void inOrderTraverse(BtreeNode* root){
    if (root == NULL)
        return;
    inOrderTraverse(root->left);
    cout << root->key << " ";
    inOrderTraverse(root->right);
    return;
}

int getNodeNumberInKthLevel(BtreeNode* root, int k){
    if (root == NULL)
        return 0;
    if (k == 1)
        return 1;
    else{
        return getNodeNumberInKthLevel(root->left, k - 1) + getNodeNumberInKthLevel(root->right, k - 1);
    }
}

int getLeafNodeNumber(BtreeNode* root){
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return getLeafNodeNumber(root->left) + getLeafNodeNumber(root->right);
}

bool structureCmp(BtreeNode* root1, BtreeNode* root2){
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL && root2 != NULL)
        return false;
    else if (root1 != NULL && root2 == NULL)
        return false;
    return (structureCmp(root1->left, root2->left) && structureCmp(root1->right, root2->right));

}

bool isAVLTree(BtreeNode* root, int &height){
    if (root == NULL) {
        height = 0;
        return true;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    if (isAVLTree(root->left, leftHeight) && isAVLTree(root->right, rightHeight) && abs(leftHeight - rightHeight) <= 1){
        height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
        return true;
    }
    else{
        return false;
    }
}

BtreeNode* mirror(BtreeNode* root){//change left to right
    if (root == NULL)
        return root;
    if (root->left == NULL && root->right == NULL)
        return root;
    BtreeNode* newLeft = mirror(root->right);
    BtreeNode* newRight = root->right = mirror(root->left);
    root->left = newLeft;
    root->right = newRight;
    return root;
}

bool findNode(BtreeNode* root, BtreeNode* node){
    if (root == NULL)
        return false;
    if (root == node)
        return true;
    return findNode(root->left, node) || findNode(root->right, node);
}
BtreeNode* getLastCommonAncestor(BtreeNode* root, BtreeNode* node1, BtreeNode* node2){
    if (root == NULL)
        return NULL;
    if (node1 == root || node2 == root)
        return root;
    if (findNode(root->left, node1)){
        if(findNode(root->right, node2))
            return root;
        else
            return (getLastCommonAncestor(root->left, node1, node2));
    }
    else{
        if(findNode(root->left, node2))
            return root;
        else
            return (getLastCommonAncestor(root->right, node1, node2));
    }
}

bool getNodePath(BtreeNode* root, BtreeNode* node, deque<BtreeNode*>& path){
    if (root == NULL)
        return false;
    if (root == node){
        path.push_front(root);
        return true;
    }
    if (getNodePath(root->left, node, path)) {
        path.push_front(root);
        return true;
    }
    else if (getNodePath(root->right, node, path)){
        path.push_front(root);
        return true;
    }
    return false;
}
BtreeNode* getLastCommonAncestor2(BtreeNode* root, BtreeNode* node1, BtreeNode* node2){
    if (root == NULL)
        return NULL;
    if (node1 == root || node2 == root)
        return root;
    deque<BtreeNode*> path1;
    deque<BtreeNode*> path2;
    BtreeNode* result = root;
    if (getNodePath(root, node1, path1) && getNodePath(root, node2, path2)){
        deque<BtreeNode*>::iterator it1 = path1.begin();
        deque<BtreeNode*>::iterator it2 = path2.begin();
        for(;it1 != path1.end() && it2 != path2.end(); it1++, it2++){
            if (*it1 == *it2)
                result = *it1;
            else
                break;
        }
        return result;
    }
    else
        return NULL;
}

int getMaxDistance(BtreeNode* root, int& maxLeft, int& maxRight){
    if (root == NULL) {
        maxLeft = 0;
        maxRight = 0;
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        maxLeft = 0;
        maxRight = 0;
        return 0;
    }
    int leftDist, rightDist;
    int maxLL, maxLR, maxRL, maxRR;
    if (root->left != NULL) {
        leftDist = getMaxDistance(root->left, maxLL, maxLR);
        maxLeft = max(maxLL, maxLR) + 1;
    }
    else{
        maxLeft = 0;
        leftDist = 0;
    }
    if (root->right != NULL) {
        rightDist = getMaxDistance(root->right, maxRL, maxRR);
        maxRight = max(maxRL, maxRR) + 1;
    }
    else{
        maxRight = 0;
        rightDist = 0;
    }
    return max(max(leftDist, rightDist), maxLeft + maxRight);

}

BtreeNode* rebuildBtreeByPreAndIn(int* preOrder, int* inOrder, int nodeNum){
    if (preOrder == NULL || inOrder == NULL || nodeNum <= 0)
        return NULL;
    BtreeNode* root = new BtreeNode();
    root->key = preOrder[0];
    root->left = NULL;
    root->right = NULL;
    int position = -1;
    for(int i = 0; i < nodeNum; i++){
        if (inOrder[i] == preOrder[0]){
            position = i;
            break;
        }
    }
    int* leftPreOrder = preOrder + 1;
    int* leftInOrder = inOrder;
    int leftNodeNum = position;
    int* rightPreOrder = preOrder + position + 1;
    int* rightInOrder = inOrder + position + 1;
    int rightNodeNum = nodeNum - position - 1;
    root->left = rebuildBtreeByPreAndIn(leftPreOrder, leftInOrder, leftNodeNum);
    root->right = rebuildBtreeByPreAndIn(rightPreOrder, rightInOrder, rightNodeNum);
    return root;
}

BtreeNode* rebuildBtreeByInAndPost(int* inOrder, int* postOrder, int nodeNum){
    if (inOrder == NULL || postOrder == NULL || nodeNum <= 0){
        return NULL;
    }
    BtreeNode* root = new BtreeNode();
    root->key = postOrder[nodeNum - 1];
    root->left = NULL;
    root->right = NULL;
    int position = -1;
    for (int i = 0; i < nodeNum; i++){
        if (inOrder[i] == postOrder[nodeNum - 1]){
            position = i;
            break;
        }
    }
    int* leftInOrder = inOrder;
    int* leftPostOrder = postOrder;
    int leftNodeNum = position;
    int* rightInorder = inOrder + position + 1;
    int* rightPostOrder = postOrder + position;
    int rightNodeNum = nodeNum - position - 1;
    root->left = rebuildBtreeByInAndPost(leftInOrder, leftPostOrder, leftNodeNum);
    root->right = rebuildBtreeByInAndPost(rightInorder, rightPostOrder, rightNodeNum);
    return root;
}

bool isCompleteBtree(BtreeNode* root){
    queue<BtreeNode*> nodeQ;
    if (root == NULL)
        return false;
    nodeQ.push(root);
    bool startEmpty = false;
    while(!nodeQ.empty()){
        BtreeNode* cur = nodeQ.front();
        nodeQ.pop();
        if (startEmpty){
            if (cur->left != NULL || cur->right != NULL)
                return false;
        }
        else{
            if (cur->left != NULL && cur->right != NULL){
                nodeQ.push(cur->left);
                nodeQ.push(cur->right);
            }
            else if (cur->left == NULL && cur->right == NULL){
                startEmpty = true;
            }
            else if (cur->left != NULL && cur->right == NULL){
                startEmpty = true;
            }
            else
                return false;
        }
    }
    return true;
}
