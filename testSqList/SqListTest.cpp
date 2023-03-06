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
 * 初始化 带头节点的链表
 */
bool InitList(LinkList &L) {
    L = (LNode* )malloc(sizeof (LNode));
    if(L == NULL) {
        return false;
    }
    L->next = NULL;
    return true;
}

/**
 * 头插法
 */
LinkList listHeadInsert(LinkList &L) {
    LNode *s;
    int x;
    InitList(L);
    while (x != 9999) {
        s = (LNode* )malloc(sizeof (LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

/**
 * 在第i个位置插入元素e 头节点是第0个位置，只要找到第i-1节点 插在其后就可以
 */
bool ListInsert(LinkList &L,int i,ElemType e) {
    if(i < 1) {
        return false;
    }
    //指针p指向当前扫描的节点
    LNode *p;
    //初始化指向头节点
    p = L;
    int j = 0;
    while (p != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if(p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof (ElemType));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

/**
 * 遍历打印链表的函数
 */
void traverse(LinkList L) {
    LNode *p = L->next; // 指向第一个节点
    while (p != NULL) {
        printf("%d ", p->data); // 输出节点的数据
        p = p->next; // 指向下一个节点
    }
}

int main() {
    LinkList L;
    listHeadInsert(L);
    traverse(L);
    ListInsert(L,1,888);
    printf("\n");
    traverse(L);
    return 0;
}