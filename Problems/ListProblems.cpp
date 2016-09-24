//
// Created by stoneshi on 16/9/23.
//
#include "ListProblems.h"

unsigned int getLength(ListNode* head){
    unsigned int result = 0;
    ListNode* ptr = head;
    while (ptr != NULL){
        result++;
        ptr = ptr->next;
    }
    return result;
}

ListNode* reverse(ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;
    ListNode* newHead = new ListNode();
    newHead->key = head->key;
    newHead->next = NULL;
    ListNode* cur = head->next;
    while(cur != NULL){
        ListNode* newCur = new ListNode();
        newCur->key = cur->key;
        newCur->next = newHead;
        newHead = newCur;
        cur = cur->next;
    }
    return newHead;
}

ListNode* getReverseNthNode(ListNode* head, int n){
    ListNode* cur1 = head;
    ListNode* cur2 = head;
    int count = n;
    while (count > 0){
        count--;
        if (cur1->next != NULL)
                cur1 = cur1->next;
        else if (count == 0)
            cur1 = cur1->next;
        else
            return NULL;
    }
    while (cur1 != NULL){
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur2;
}

ListNode* getMiddleNode(ListNode* head){
    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
        return head;

    ListNode* cur1 = head;
    ListNode* cur2 = head;
    while(cur1 != NULL){
        cur2 = cur2->next;
        cur1 = cur1->next;
        if (cur1 != NULL)
            cur1 = cur1->next;
        else
            break;
    }
    return cur2;
}

void reversePrint(ListNode* head){
    if (head == NULL){
        cout << "The list is empty!" << endl;
        return;
    }
    stack<int> rPrintStack;
    ListNode* cur = head;
    while (cur != NULL){
        rPrintStack.push(cur->key);
        cur = cur->next;
    }
    while(!rPrintStack.empty()){
        cout << rPrintStack.top() << endl;
        rPrintStack.pop();
    }
}

ListNode* mergeSortedLists(ListNode* head1, ListNode* head2){
    ListNode* mergedList = new ListNode();
    ListNode* cur1 = head1;
    ListNode* cur2 = head2;
    ListNode* cur = mergedList;
    while (cur1 != NULL || cur2 != NULL) {
        if (cur1 == NULL) {
            cur->key = cur2->key;
            cur2 = cur2->next;
        } else if (cur2 == NULL) {
            cur->key = cur1->key;
            cur1 = cur1->next;
        } else {
            if (cur1->key < cur2->key) {
                cur->key = cur1->key;
                cur1 = cur1->next;
            } else {
                cur->key = cur2->key;
                cur2 = cur2->next;
            }
        }
        if (cur1 != NULL || cur2 != NULL) {
            cur->next = new ListNode();
            cur = cur->next;
        }
    }
    return mergedList;
}

bool ifHasCircle(ListNode* head){
    if (head == NULL || head->next == NULL)
        return false;
    ListNode* cur1 = head;
    ListNode* cur2 = head;
    while(cur1 != NULL){
        cur1 = cur1->next;
        cur2 = cur2->next;
        if (cur1 != NULL)
            cur1 = cur1->next;
        else
            return false;
        if (cur1 == cur2)
            return true;
    }
    return false;
}

ListNode* getFirstNodeInCircle(ListNode* head){
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode* cur1 = head;
    ListNode* cur2 = head;
    while(cur1 != NULL){
        cur1 = cur1->next;
        cur2 = cur2->next;
        if (cur1 != NULL)
            cur1 = cur1->next;
        else
            return NULL;
        if (cur1 == cur2)
            break;
    }
    if (cur1 == NULL)
        return NULL;
    ListNode* newHead = cur1->next;
    cur1->next = NULL;
    ListNode* result = getFirstCommonNode(head, newHead);
    cur1->next = newHead;
    return result;
}

bool ifIntersected(ListNode* head1, ListNode* head2){
    ListNode* cur1 = head1;
    ListNode* cur2 = head2;
    while(cur1->next != NULL){
        cur1 = cur1->next;
    }
    while (cur2->next != NULL){
        cur2 = cur2->next;
    }
    return cur1 == cur2;
}

ListNode* getFirstCommonNode(ListNode* head1, ListNode* head2){
    ListNode* tail1 = head1;
    ListNode* tail2 = head2;
    int length1 = 1;
    int length2 = 1;
    while (tail1->next != NULL){
        tail1 = tail1->next;
        length1++;
    }
    while (tail2->next != NULL){
        tail2 = tail2->next;
        length2++;
    }
    if (tail1 != tail2)
        return NULL;
    ListNode* cur1 = head1;
    ListNode* cur2 = head2;
    if (length1 > length2){
        int diff = length1 - length2;
        while (diff > 0) {
            cur1 = cur1->next;
            diff--;
        }
    }
    else if (length1 < length2){
        int diff = length2 - length1;
        while(diff > 0){
            cur2 = cur2->next;
            diff--;
        }
    }
    while (cur1->next != NULL){
        if (cur1 == cur2)
            return cur1;
        else{
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    return cur1;
}

void deleteNode(ListNode* head, ListNode* toDelete){
    if (toDelete == NULL)
        return;
    if (toDelete->next != NULL){
        toDelete->key = toDelete->next->key;
        toDelete->next = toDelete->next->next;
        delete toDelete->next;
    }
    else{
        ListNode* ptr = head;
        while(ptr != NULL){
            if (ptr->next == toDelete)
                break;
            else
                ptr = ptr->next;
        }
        if (ptr == NULL)
            return;
        else {
            ptr->next = toDelete->next;
            delete toDelete;
        }
    }
}