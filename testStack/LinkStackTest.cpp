//
// Created by Administrator on 2023/3/14.
//
#include <stdio.h>
#include <stdlib.h>

typedef  int SElemType;
/**
 * 链式栈的实现
 * 链表的头指针就是栈顶
 * 不需要头节点
 * 空栈 == 头指针指向NULL
 * 插入删除在栈顶执行
 * 不存在栈满的情况（动态分配空间）
 */
typedef struct StackNode {
    SElemType data;//数据域
    struct StackNode *next;//指针域  (嵌套的定义 指向自己的类型)
}StackNode, *LinkStack;

/**
* 初始化
*/
int InitStack(LinkStack &S) {
    //构造一个空栈
    S = NULL;
    return 1;
}

/**
* 判空
*/
int EmptyStack(LinkStack S) {
    if(S == NULL) {
        return 1;
    }else{
        return 0;
    }
}

/**
* 入栈
*/
int PushStack(LinkStack &S,int e) {
    StackNode *p;
    p =  new StackNode; //生成新的节点
    p->data = e; //新节点赋值
    p->next = S; //新节点插入栈顶
    S = p; //修改栈顶指针
}

/**
* 出栈
*/
int PopStack(LinkStack &S,int &e) {
    StackNode *p;
    if(S == NULL) {
        return -1;//空栈
    }
    e = S->data;
    p = S;
    S = S->next;
    delete p;
    return 1;
}

/**
* 取栈顶元素
*/
int GetTop(LinkStack &S) {
    if(S == NULL) {
        return -1;
    }
    return S->data;
}

int mainLinkStackTest() {
    LinkStack S;
    InitStack(S);
    int i;
    //遍历入栈
    for (i = 1; i <= 10; i++) {
        //链式栈不需要判断是否空间满了，动态分配内存空间
        PushStack(S, i);

    }
    int e;
    //遍历出栈
    for (i = 1; i <= 10; i++) {
        if (!EmptyStack(S)) {
            PopStack(S, e);
            printf("%d\t",e);
        }
    }
}