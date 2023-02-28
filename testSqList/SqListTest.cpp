//
// Created by Administrator on 2023/2/28.
//
#include <stdio.h>
#include <stdlib.h>
typedef  int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
/**
 * 头插法
 * @param L  链表
 * @return
 */
LinkList listHeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList )malloc(sizeof (LNode));
    L-> next = NULL;
    while (x != 9999) {
        s = (LNode* )malloc(sizeof (LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
int main() {
    LinkList L;
    listHeadInsert(L);
    return 0;
}