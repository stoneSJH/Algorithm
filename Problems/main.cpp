#include "ListProblems.h"
#include "MathProblems.h"

//case for test ListProblems
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

int main(){
    cout << whichPrime(104677) << endl;
}