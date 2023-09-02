//
// Created by 孙昀 on 2023/9/2.
//
#include <stdio.h>
#include <math.h>

typedef char ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//求链表长度
int getLength_2012_41(LinkList L) {
    int len = 0;
    LNode * p = L->next;
    while (p != NULL) {
        len++;
        p = p->next;
    }
}

LNode* func_2012_42(LinkList L1,LinkList L2) {
    LNode *str1 = L1->next, * str2 = L2->next; //指针str1、str2指向两个链表的第一个节点
    int len1 = getLength_2012_41(L1);
    int len2 = getLength_2012_41(L2);
    //int step = (len1-len2) > 0 ? (len1-len2) : (-(len1-len2)); //同样可以达到取绝对值的目的
    int step = abs(len1-len2);//计算两个链表的长度差值
    int mini = len1; //长度小的变量
    if(len1 >= len2) {
        mini = len2; //更小的是len2
        for(int i = 0; i < step; i++) { //更长先后移 step步
            str1 = str1->next;
        }
    } else {
        for(int i = 0; i < step; i++) { //更长先后移 step步
            str2 = str2->next;
        }
    }

    for(int i = 0; i < mini; i++) {
        if(str1->data == str2->data){
            return str1;//查找成功
        }
        str1 = str1->next;
        str2 = str2->next;
    }
    return NULL;//查找失败
}