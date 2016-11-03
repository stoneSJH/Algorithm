#include "ListProblems.h"
#include "MathProblems.h"
#include "BtreeProblems.h"
#include "BSearchProblems.h"
#include "BSTreeProblems.h"
/*
 * case for test ListProblems
 */
//int main() {
//
//    cout << whichPrime(104677) << endl;
//    ListNode* head = new ListNode();
//    head->key = 0;
//    ListNode* ptr = head;
//    for (int i = 1; i < 11; i++){
//        ListNode* cur = new ListNode();
//        cur->key = i;
//        ptr->next = cur;
//        ptr = ptr->next;
//    }
//
//    ListNode* append = new ListNode();
//    append->key = -5;
//    ptr = append;
//    for (int i = 0; i < 5; i++){
//        ListNode* cur = new ListNode();
//        cur->key = 3 * i + 2;
//        ptr->next = cur;
//        ptr = ptr->next;
//    }
//
//    ListNode* circle = new ListNode();
//    circle->key = 5;
//    ListNode* node1 = new ListNode();
//    node1->key = 15;
//    ListNode* node2 = new ListNode();
//    node2->key = 25;
//    ListNode* node3 = new ListNode();
//    node3->key = 35;
//    ListNode* node4 = new ListNode();
//    node4->key = 45;
//    ListNode* node5 = new ListNode();
//    node5->key = 55;
//    circle->next = node3;
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node1;
//
//    ListNode* commonNode = new ListNode();
//    commonNode->key = 11111;
//    commonNode->next = NULL;
//    ListNode* intersectList1 = new ListNode();
//    intersectList1->key = 1;
////    intersectList1->next = append;
//    intersectList1->next = commonNode;
//    ListNode* intersectList2 = new ListNode();
//    intersectList2->key = -1;
//    ListNode* tempNode0 = new ListNode();
//    ListNode* tempNode1 = new ListNode();
//    ListNode* tempNode2 = new ListNode();
//    tempNode0->key = -2;
//    tempNode0->next = tempNode1;
//    tempNode1->key = -3;
//    tempNode1->next = tempNode2;
//    tempNode2->key = -4;
////    tempNode2->next = append;
//    tempNode2->next = commonNode;
//    intersectList2->next = tempNode0;
//
//    ListNode* tobeDeleted = new ListNode();
//    tobeDeleted->key = 110;
//    ListNode* tempNode00 = new ListNode();
//    tempNode00->key = 0;
//    ListNode* tempNode01 = new ListNode();
//    tempNode01->key = -1;
//    ListNode* tempNode02 = new ListNode();
//    tempNode02->key = -2;
//    ListNode* tempNode03 = new ListNode();
//    tempNode03->key = -3;
//    ListNode* tempNode04 = new ListNode();
//    tempNode04->key = -4;
//    tobeDeleted->next = tempNode00;
//    tempNode00->next = tempNode01;
//    tempNode01->next = tempNode02;
//    tempNode02->next = tempNode03;
//    tempNode03->next = tempNode04;
//    tempNode04->next = NULL;
//
////    cout << getLength(head) << endl;
//
////    ListNode* reverseHead = reverse(head);
////    ptr = reverseHead;
////    while (ptr != NULL){
////        cout << ptr->key << endl;
////        ptr = ptr->next;
////    }
//
////    ListNode* cur = getReverseNthNode(head, 8);
////    if (cur != NULL)
////        cout << cur->key << endl;
////    else
////        cout << "length error" << endl;
//
////    ListNode* Middle = getMiddleNode(head);
////    cout << Middle->key << endl;
//
////    reversePrint(head);
//
////    ptr = mergeSortedLists(head, append);
////    while (ptr != NULL){
////        cout << ptr->key << endl;
////        ptr = ptr->next;
////    }
//
////    cout << ifHasCircle(circle) << endl;
//
////    cout << ifIntersected(intersectList1, intersectList2) << endl;
//
////    ListNode* intersectNode = getFirstCommonNode(intersectList1, intersectList2);
////    if (intersectNode != NULL){
////        cout << intersectNode->key <<endl;
////    }
////    else{
////        cout << "No common node" << endl;
////    }
//
////    ListNode* firstNodeInCircle = getFirstNodeInCircle(circle);
////    if (firstNodeInCircle != NULL){
////        cout << firstNodeInCircle->key << endl;
////    }
////    else{
////        cout << "No circle" << endl;
////    }
//
////    deleteNode(tobeDeleted, tempNode04);
////    ptr = tobeDeleted;
////    while(ptr != NULL){
////        cout << ptr->key << endl;
////        ptr = ptr->next;
////    }
//    return 0;
//}

/*
 * cases for test BTree problems
 */
//int main(){
//    BtreeNode* root = new BtreeNode();
//    root->key = 0;
//    BtreeNode* node0 = new BtreeNode();
//    node0->key = 1;
//    BtreeNode* node1 = new BtreeNode();
//    node1->key = 2;
//    BtreeNode* node00 = new BtreeNode();
//    node00->key = 3;
//    BtreeNode* node01 = new BtreeNode();
//    node01->key = 4;
//    BtreeNode* node10 = new BtreeNode();
//    node10->key = 5;
//    BtreeNode* node000 = new BtreeNode();
//    node000->key = 6;
//    BtreeNode* node101 = new BtreeNode();
//    node101->key = 7;
//    BtreeNode* node0000 = new BtreeNode();
//    node0000->key = 8;
//
//    root->left = node0;
//    root->right = node1;
//    node0->left = node00;
//    node0->right = node01;
//    node1->left = node10;
////    node1->right = node101;
//    node00->left = node000;
//    node000->left = node0000;
//    node10->right = node101;
//
//
//    BtreeNode* cproot = new BtreeNode();
//    cproot->key = 0;
//    BtreeNode* cpnode0 = new BtreeNode();
//    cpnode0->key = -1;
//    BtreeNode* cpnode1 = new BtreeNode();
//    cpnode1->key = -2;
//    BtreeNode* cpnode00 = new BtreeNode();
//    cpnode00->key = -3;
//    BtreeNode* cpnode01 = new BtreeNode();
//    cpnode01->key = -4;
//    BtreeNode* cpnode10 = new BtreeNode();
//    cpnode10->key = -5;
//    BtreeNode* cpnode000 = new BtreeNode();
//    cpnode000->key = -6;
//    BtreeNode* cpnode100 = new BtreeNode();
//    cpnode100->key = -7;
//    BtreeNode* cpnode101 = new BtreeNode();
//    cpnode101->key = -8;
//
//    cproot->left = cpnode0;
//    cproot->right = cpnode1;
//    cpnode0->left = cpnode00;
//    cpnode0->right = cpnode01;
//    cpnode00->left = cpnode10;
//    cpnode01->left = cpnode000;
//    cpnode10->right = cpnode101;
//    cpnode000->left = cpnode100;
//
//
////    cout << getNodeNumber(root) << endl;
////    cout << getDepth(root) << endl;
////    levelTraverse(root);
////    levelTraverse(mirror(root));
////    cout << getNodeNumberInKthLevel(root, 4) << endl;
//
////    cout << getLeafNodeNumber(root) << endl;
////    cout << structureCmp(root, cproot) << endl;
//
////    int height = -1;
////    cout << isAVLTree(root, height) << endl;
////    cout << height <<endl;
//
////    BtreeNode* ancestor = getLastCommonAncestor2(root, node10, node0);
////    cout << ancestor->key <<endl;
////    int maxl, maxr;
////    cout << getMaxDistance(cproot, maxl, maxr) << endl;
//    int pre[7] = {1,2,4,5,3,6,7};
//    int in[7] = {2,5,4,3,1,7,6};
//    int post[7] = {5,3,4,2,7,6,1};
////    BtreeNode* btree = rebuildBtreeByPreAndIn(pre, in, 7);
////    BtreeNode* btree = rebuildBtreeByInAndPost(in, post, 7);
////    printTree(btree);
////    postOrderTraverse(btree);
//    cout << isCompleteBtree(root) << endl;
//}

/*
 * cases for test binary search problems
 */
//int main(){
//    int a[10] = {-5, -3, -1, 0, 1, 2, 2, 2, 7, 22};
////    cout << search(a, 10, 2);
////    cout << searchFirstTarget(a, 10, 2);
//    cout << searchLastTarget(a, 10, 3);
//}

/*
 * cases for test binary search tree problems
 */

int main(){
    BstreeNode* root = new BstreeNode();
    root->key = 10;
    BstreeNode* node5 = new BstreeNode();
    node5->key = 5;
    BstreeNode* node1 = new BstreeNode();
    node1->key = 1;
    BstreeNode* node3 = new BstreeNode();
    node3->key = 3;
    BstreeNode* node2 = new BstreeNode();
    node2->key = 2;
    BstreeNode* node11 = new BstreeNode();
    node11->key = 11;
    BstreeNode* node20 = new BstreeNode();
    node20->key = 20;
    BstreeNode* node15 = new BstreeNode();
    node15->key = 15;
//  bst structure;
//    root->left = node5;
//    node5->left = node1;
//    node1->right = node3;
//    node3->left = node2;
//    root->right = node15;
//    node15->left = node11;
//    node15->right = node20;

//    non bst structure
    root->left = node20;
    root->right = node1;
    node1->left = node5;
    node5->right = node3;
    node20->left = node15;
    node15->right = node11;
    node11->right = node2;

//    cout << check(root) << endl;
//    setHeight(root);
//    printTree(root);
//    cout << checkAVL(root) << endl;


    /*
    BstreeNode* tree = NULL;
    tree = insert(tree, 5);
    printTree(tree);
    cout << "-------------------------------------------" << endl;
    tree = insert(tree, 3);
    printTree(tree);
    cout << "-------------------------------------------" << endl;
    tree = insert(tree, 2);
    printTree(tree);
    cout << "-------------------------------------------" << endl;
    tree = insert(tree, 1);
    printTree(tree);
    cout << "-------------------------------------------" << endl;
    tree = insert(tree, 15);
    printTree(tree);
    cout << "-------------------------------------------" << endl;
    tree = insert(tree, 25);
    printTree(tree);
    cout << "-------------------------------------------" << endl;
    tree = insert(tree, 51);
    printTree(tree);
    cout << "-------------------------------------------" << endl;
    tree = insert(tree, 12);
    printTree(tree);
    cout << "-------------------------------------------" << endl;
    tree = insert(tree, 11);
    printTree(tree);
    cout << "-------------------------------------------" << endl;
    tree = insert(tree, 10);
    printTree(tree);
    cout << "-------------------------------------------" << endl;
    tree = insert(tree, 5);
    printTree(tree);
    cout << "-------------------------------------------" << endl;

    cout << checkAVL(tree) << endl;

    cout << "--------------------------------------------" << endl;
//    printTree(tree);
    BstreeNode* cur = find(tree, 5);
    tree = remove(tree, cur);
    printTree(tree);
    cout << "--------------------------------------------" << endl;
//    printTree(tree);
//    cur = find(tree, 12);
    tree = remove(tree, 12);
    printTree(tree);
    cout << "--------------------------------------------" << endl;
//    printTree(tree);
//    cur = find(tree, 11);
    tree = remove(tree, 11);
    printTree(tree);
    cout << "--------------------------------------------" << endl;
    tree = remove(tree, 10);
    printTree(tree);
    cout << "--------------------------------------------" << endl;
    tree = remove(tree, 1);
    printTree(tree);
    cout << "--------------------------------------------" << endl;
    tree = remove(tree, 3);
    printTree(tree);
    cout << "--------------------------------------------" << endl;
    tree = remove(tree, 2);
    printTree(tree);
    cout << "--------------------------------------------" << endl;
    tree = remove(tree, 25);
    printTree(tree);
    cout << "--------------------------------------------" << endl;
    tree = remove(tree, 51);
    printTree(tree);
    cout << "--------------------------------------------" << endl;
    tree = remove(tree, 12);
    printTree(tree);
    cout << "--------------------------------------------" << endl;
    tree = remove(tree, 15);
    printTree(tree);
    */

    cout << checkAVL(root) << endl;
    cout << check(root) << endl;
    printTree(root);
    cout << "---------------------------------------------" << endl;
//    root = rebuildAVLFromBST(root);
    BstreeNode* newRoot = rebuildAVLFromBT(root);
    printTree(newRoot);
    cout << checkAVL(newRoot) << endl;

}