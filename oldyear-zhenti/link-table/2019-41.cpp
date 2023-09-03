//
// Created by 孙昀 on 2023/9/3.
//
#include <stdio.h>
typedef struct node {
    int data;
    struct node *next;
} NODE,*List;

/**
 * 找到中间节点
 * @param head
 * @return
 */
NODE* middleNode(NODE* head) {
    NODE* slow = head;
    NODE* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/**
 * 反转链表
 * @param head
 * @return
 */
NODE* reverseList(NODE* head) {
    NODE* prev = NULL;
    NODE* curr = head;
    while (curr != NULL) {
        NODE* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
/**
 * 合并链表
 * @param l1
 * @param l2
 */
void mergeList(NODE* l1, NODE* l2) {
    NODE* l1_tmp;
    NODE* l2_tmp;
    while (l1 != NULL && l2 != NULL) {
        l1_tmp = l1->next;
        l2_tmp = l2->next;
        l1->next = l2;
        l1 = l1_tmp;
        l2->next = l1;
        l2 = l2_tmp;
    }
}

void  reorderList(NODE* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    NODE* mid = middleNode(head->next);
    NODE* l1 = head->next;
    NODE* l2 = mid->next;
    mid->next = NULL;
    l2 = reverseList(l2);
    mergeList(l1, l2);
}