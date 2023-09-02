//
// Created by 孙昀 on 2023/9/2.
//
#include <stdio.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *link;
}LNode,*LinkList;

/**
 *  双指针实现，时间复杂度O（n），空间复杂度O（1） 只需要遍历一次链表即可
 * @param L
 * @param k 查找导数第k位置元素的值
 * @return
 */
ElemType func1_2009_42(LinkList L, int k) {
    LNode *fist = L->link, *second = L->link;//两个指针指向第一个节点（头指针的下一个节点）
    for(int i = 0; i < k; i++) {
        if(fist == NULL) { //只有头节点 是个空链表  链表的长度是不包括头指针的
            return 0; //查找失败 返回0
        }
        fist = fist->link; //fist指针后移k+1步
    }
    while (fist != NULL) {
        fist = fist->link;
        second = second->link;
    }
    printf("%d",second->data); //输出查找元素的值
    return 1;//查找成功 返回1
}

/**
 * 单指针实现，时间复杂度O（n），空间复杂度O（1）需要遍历两次链表
 * @param L
 * @param k 查找导数第k位置元素的值
 * @return
 */
ElemType func2_2009_42(LinkList L,int k) {

    int length = 0; //链表长度变量
    LNode * p = L->link; //指针变量指向第一个元素节点（头节点的下一个元素节点）
    while (p != NULL) { //求链表长度
        length++;
        p = p->link;
    }

    p = L->link;//p指针恢复指向第一个节点
    int k1 = length - k + 1;//与倒数第k个位置对应的整数第k1个位置
    if(k1 < 0) {
        return 0;//查找失败
    }

    int i = 1;
    while (i != k) {
        i++;
        p = p->link;
    }
    printf("%d", p->data);//输出查找的值
    return 1;//查找成功
}