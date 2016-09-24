//
// Created by stoneshi on 16/9/23.
//

#ifndef CLIONTEST001_LISTPROBLEMS_H
#define CLIONTEST001_LISTPROBLEMS_H
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct ListNode{
    int key;
    ListNode* next;
};

unsigned int getLength(ListNode* head);
ListNode* reverse(ListNode* head);
ListNode* getReverseNthNode(ListNode* head, int n);
ListNode* getMiddleNode(ListNode* head);
void reversePrint(ListNode* head);
ListNode* mergeSortedLists(ListNode* head1, ListNode* head2);
bool ifHasCircle(ListNode* head);
ListNode* getFirstNodeInCircle(ListNode* head);
bool ifIntersected(ListNode* head1, ListNode* head2);
ListNode* getFirstCommonNode(ListNode* head1, ListNode* head2);
void deleteNode(ListNode* head, ListNode* toDelete);

#endif //CLIONTEST001_LISTPROBLEMS_H
