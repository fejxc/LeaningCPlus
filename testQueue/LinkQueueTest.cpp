//
// Created by Administrator on 2023/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int QElemType;
typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front; //队头指针
    QueuePtr rear; //队尾指针
}LinkQueue;

/**
 * 初始化
 */
int InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QueuePtr) malloc(sizeof (QNode));
    if(!Q.front){
        exit(-1);
    }
}

/**
* 销毁
*/
int DestroyQueue(LinkQueue &Q) {
    QueuePtr p;
    while (Q.front) {
        p = Q.front->next;//保存待删节点的下一个节点; 还可以直接利用尾指针 Q.rear = Q.front->next;
        free(Q.front);
        Q.front = p; //Q.front=Q.rear;
    }
}

/**
* 入队
*/
int EnQueue(LinkQueue &Q,int e) {
    QueuePtr p = new QNode;
    if(!p){
        exit(-1);
    }
    p->data = e;
    Q.rear->next = p;
    p->next = NULL;
    Q.rear = p;//尾节点指向新的队尾元素
    return 1;
}

/**
* 出队
*/
int DeQueue(LinkQueue &Q,int &e) {
    QueuePtr p = new QNode;
    if(Q.front == Q.rear) {
        exit(-1);
    }
    e = Q.front->next->data;
    p = Q.front->next;
    Q.front = Q.front->next->next;
    //删除的时候式尾节点的情况，特殊处理
    if(Q.rear == p){
        Q.rear = Q.front;
    }
    delete p;
    return 1;
}
/**
 * 取队头元素
 */
int GetHead(LinkQueue Q,int &e) {
    if(Q.front == Q.rear) {
        exit(-1);
    }
    return Q.front->next->data;
}