//
// Created by 孙昀 on 2023/9/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memset
typedef struct node {
    int data;
    struct node *link;
} NODE;

NODE* deleteDuplicates(NODE* head, int n) {
    int st[n + 1];
    memset(st, 0, sizeof(st));
    NODE *prev = head;
    NODE *curr = head->link;
    while (curr != NULL) {
        if (st[abs(curr->data)] == 1) {
            prev->link = curr->link;
            NODE *temp = curr;
            free(temp);
        } else {
            st[abs(curr->data)] = 1;
            prev = prev->link;
        }
        curr = curr->link;
    }
    return head;
}

int main_2015_41(int argc, const char * argv[]) {
    NODE *head = (NODE *)malloc(sizeof(NODE));
    head->link = NULL; // 初始化链表的头节点
    NODE *curr = head;
    int nums[] = {21, -15, -15, -7, 15};
    for (int i = 0; i < 5; ++i) {
        NODE *next = (NODE *)malloc(sizeof(NODE));
        next->data = nums[i];
        next->link = NULL;
        curr->link = next;
        curr = curr->link;
    }
    head = deleteDuplicates(head, 64);
    curr = head->link;
    printf("head");
    while (curr != NULL) {
        printf("->%d", curr->data);
        curr = curr->link;
    }
    return 0;
}