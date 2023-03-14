//
// Created by Administrator on 2023/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int QElemType;
/**
 * 顺序结构的队列(循环队列）
 * 少用一个元素区分对空对满的情况：
 * 对空 -> Q.front=Q.rear
 * 对满 -> (Q.rear+1)%MAXSIZE == Q.front
 */
typedef struct {
    QElemType *base; //初始化的动态分配存储空间
    int front; //头指针
    int rear; //尾指针
}SqQueue;

/**
* 初始化
*/
int InitQueue(SqQueue &Q) {
    //数组首元素的地址就是个指针
    Q.base = new QElemType[MAXSIZE];//分配数组空间
    //Q.base = (QElemType *) malloc(MAXSIZE*sizeof (QElemType));
    if(!Q.base){
        return -1;
    }
    //普通类型引用使用. 指针类型引用可以用->
    Q.front = Q.rear = 0;
    return 1;
}

/**
 * 判满
 */
int FullQueue(SqQueue Q) {
    return (Q.rear + 1 )%MAXSIZE == Q.front ? 0 : 1;
}

/**
 * 判空
 */
int EmptyQueue(SqQueue Q) {
    return Q.rear == Q.front;
}

/**
* 入队
*/
int EnQueue(SqQueue &Q,int e) {
    if(!FullQueue(Q)){
        Q.base[Q.rear] = e; //新元素加入队尾巴
        Q.rear = (Q.rear + 1)%MAXSIZE;//对尾指针加1
        return 1;
    }
    return -1;
}

/**
* 出队
*/
int DeQueue(SqQueue &Q,int &e) {
    if(!EmptyQueue(Q)){
        e = Q.base[Q.front];
        Q.front = (Q.front + 1)%MAXSIZE;//对头指针加1
        return 1;
    }
    return -1;
}

/**
* 求队列长度
*/
int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}

/**
 * 取对头元素
 */
int GetHead(SqQueue Q) {
    if(!EmptyQueue(Q)) {
        return Q.base[Q.front];
    }
    return -1;
}
