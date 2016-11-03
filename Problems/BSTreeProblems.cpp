//
// Created by stoneshi on 16/9/28.
//

#include "BSTreeProblems.h"

int recordMin = INT_MIN;

bool _check(BstreeNode* root){
    if(root == NULL)
        return true;
    if (!_check(root->left))
        return false;
    if (root->key > recordMin){
        recordMin = root->key;
    }
    else {
        return false;
    }
    if (!_check(root->right))
        return false;
    return true;
}

bool check(BstreeNode* root){
    recordMin = INT_MIN;
    return _check(root);
}

bool _checkAVL(BstreeNode* root){
    if(root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    setHeight(root);
    if (root->right == NULL) {
        if (root->left != NULL && root->left->height > 1)
            return false;
    }
    if(root->left == NULL){
        if (root->right != NULL && root->right->height > 1)
            return false;
    }
    if (root->left != NULL && root->right != NULL && (abs(root->left->height - root->right->height) > 1))
        return false;
    if (!_checkAVL(root->left))
        return false;
    if (root->key > recordMin){
        recordMin = root->key;
    }
    else {
        return false;
    }
    if (!_checkAVL(root->right))
        return false;
    return true;

}

bool checkAVL(BstreeNode* root){
    recordMin = INT_MIN;
    return _checkAVL(root);
}

void setHeight(BstreeNode* root){
    if (root == NULL) {
        return;
    }
    setHeight(root->left);
    setHeight(root->right);

    if(root->left == NULL && root->right == NULL){
        root->height = 1;
    }
    else if (root->left == NULL){
        root->height = root->right->height + 1;
    }
    else if (root->right == NULL){
        root->height = root->left->height + 1;
    }
    else{
        root->height = (root->left->height > root->right->height ? root->left->height : root->right->height) + 1;
    }
    return;
}


void printTree(BstreeNode* root){
    if (root == NULL) {
        cout << "the tree is empty" << endl;
        return;
    }
    int depth = root->height;
    queue<BstreeNode*> nodeQ;
    queue<int> levelQ;
    queue<int> positionQ;
    nodeQ.push(root);
    levelQ.push(0);
    positionQ.push(0);
    int lastLevel = 0;
    int lastPosition = -1;
    while (!nodeQ.empty()) {
        BstreeNode *cur = nodeQ.front();
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
//                cout << "  ";
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
//                cout << "  ";
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

void resetHeight(BstreeNode* root){
    if (root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL){
        root->height = 1;
    }
    else if (root->left == NULL){
        root->height = root->right->height + 1;
    }
    else if (root->right == NULL){
        root->height = root->left->height + 1;
    }
    else{
        root->height = (root->left->height > root->right->height ? root->left->height : root->right->height) + 1;
    }
    return;

}

int getHeight(BstreeNode* root){
    if (root == NULL)
        return 0;
    else
        return root->height;
}

BstreeNode* leftRotate(BstreeNode* root){
    BstreeNode* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    resetHeight(root);
    resetHeight(newRoot);
    return newRoot;
}

BstreeNode* rightRotate(BstreeNode* root){
    BstreeNode* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    resetHeight(root);
    resetHeight(newRoot);
    return newRoot;
}

BstreeNode* lrRotate(BstreeNode* root){
    root->left = rightRotate(root->left);
    return leftRotate(root);
}

BstreeNode* rlRotate(BstreeNode* root){
    root->right = leftRotate(root->right);
    return rightRotate(root);
}

BstreeNode* insert(BstreeNode* root, int key){
    if (root == NULL){
        BstreeNode* newRoot = new BstreeNode();
        newRoot->key = key;
        newRoot->height = 1;
        return newRoot;
    }
    else if (key > root->key){
        root->right = insert(root->right, key);
        int leftHeight;
        int rightHeight;
        if (root->left != NULL)
            leftHeight = root->left->height;
        else
            leftHeight = 0;
        resetHeight(root->right);
        resetHeight(root);
        rightHeight = root->right->height;
        if (rightHeight - leftHeight >= 2){
            if (key > root->right->key){
                return rightRotate(root);
            }
            else{
                return rlRotate(root);
            }
        } else
            return root;
    }
    else if (key < root->key){
        root->left = insert(root->left, key);
        int leftHeight;
        int rightHeight;
        if (root->right != NULL)
            rightHeight = root->right->height;
        else
            rightHeight = 0;
        resetHeight(root->left);
        resetHeight(root);
        leftHeight = root->left->height;
        if (leftHeight - rightHeight >= 2){
            if (key < root->left->key){
                return leftRotate(root);
            }
            else{
                return lrRotate(root);
            }
        }
        else
            return root;
    }
    else{
        cout << "the element has been inserted" << endl;
        return root;
    }
}

BstreeNode* find(BstreeNode* root, int key){
    if (root == NULL)
        return NULL;
    BstreeNode* cur = root;
    while (cur != NULL){
        if (key > cur->key){
            cur = cur->right;
        }
        else if (key < cur->key){
            cur = cur->left;
        }
        else{
            return cur;
        }
    }
    cout << "the element is not in the tree" << endl;
    return NULL;
}

BstreeNode* findMin(BstreeNode* root){
    if (root == NULL)
        return NULL;
    BstreeNode* cur = root;
    if (cur->left != NULL) {
        cur = cur->left;
    }
    return cur;
}
BstreeNode* findMax(BstreeNode* root){
    if(root == NULL)
        return NULL;
    BstreeNode* cur = root;
    if (cur->right != NULL){
        cur = cur->right;
    }
    return cur;
}
BstreeNode* remove(BstreeNode* root, BstreeNode* key){
    if (root == NULL || key == NULL) {
        return root;
    }
    else if (key->key > root->key){
        root->right = remove(root->right, key);
        int leftHeight;
        int rightHeight;
        leftHeight = getHeight(root->left);
        resetHeight(root->right);
        resetHeight(root);
        rightHeight = getHeight(root->right);
        if (leftHeight - rightHeight >= 2){
            if (getHeight(root->left->left) > getHeight(root->left->right)){
                return leftRotate(root);
            }
            else{
                return lrRotate(root);
            }
        }
        else
            return root;
    }
    else if (key->key < root->key){
        root->left = remove(root->left, key);
        int leftHeight;
        int rightHeight;
        rightHeight = getHeight(root->right);
        resetHeight(root->left);
        resetHeight(root);
        leftHeight = getHeight(root->left);
        if (rightHeight - leftHeight >= 2){
            if (getHeight(root->right->left) > getHeight(root->right->right)){
                return rlRotate(root);
            }
            else
                return rightRotate(root);
        }
        else
            return root;
    }
    else{
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if (root->left == NULL){
            BstreeNode* tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }
        else if (root->right == NULL){
            BstreeNode* tmp = root;
            root = root->left;
            delete tmp;
            return root;
        }
        else{
            if (getHeight(root->left) > getHeight(root->right)){
                BstreeNode* tmp = root;
                BstreeNode* toDelete = findMax(root->left);
                root->key = toDelete->key;
                root->left = remove(root->left, toDelete);
                return root;
            }
            else{
                BstreeNode* tmp = root;
                BstreeNode* toDelete = findMin(root->right);
                root->key = toDelete->key;
                root->right = remove(root->right, toDelete);
                return root;
            }
        }
    }
}

BstreeNode* remove(BstreeNode* root, int key){
    BstreeNode* cur = find(root, key);
    return remove(root, cur);
}

BstreeNode* rebuildAVLFromBST(BstreeNode* root){
    if (root->left != NULL)
        root->left = rebuildAVLFromBST(root->left);
    if (root->right != NULL)
        root->right = rebuildAVLFromBST(root->right);
    if (getHeight(root->left) - getHeight(root->right) >= 2){
        if (getHeight(root->left->left) > getHeight(root->left->right))
            return leftRotate(root);
        else
            return lrRotate(root);
    }
    else if (getHeight(root->right) - getHeight(root->left) >= 2){
        if (getHeight(root->right->left) > getHeight(root->right->right))
            return rlRotate(root);
        else
            return rightRotate(root);
    }
    else
        return root;
}

BstreeNode* rebuildAVLFromBT(BstreeNode* root){
    vector<int> inOrder;
    stack<BstreeNode*> q;
    BstreeNode* cur = root;
    while(!q.empty() || cur != NULL){
        while (cur != NULL){
            q.push(cur);
            cur = cur->left;
        }
        if (!q.empty()) {
            cur = q.top();
            inOrder.push_back(cur->key);
            q.pop();
            cur = cur->right;
        }
    }
    BstreeNode* newRoot = NULL;
    for (int i = 0; i < inOrder.size(); i++){
        newRoot = insert(newRoot, inOrder[i]);
    }
    return newRoot;
}