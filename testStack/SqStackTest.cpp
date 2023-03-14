//
// Created by Administrator on 2023/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

/**
 * top-base=栈中的元素  指针相减 是地址直接减 相差多少个位置
 * top-base == MAXSIZE 栈满
 * top == base 空栈
 * top指针指向栈顶元素的下一个位置
 */
typedef  int SElemType;
/**
 * 顺序栈的实现 下表从0开始
 */
typedef struct {
    SElemType *base;//栈底指针
    SElemType *top;//栈顶指针
    int stacksize;//栈可用的最大容量
}SqStack;

/**
 * 初始化
 */
int InitStack(SqStack &S) {
    //S.base = new SElemType [MAXSIZE];//C++
    //分配空间
    S.base = (SElemType*) malloc(MAXSIZE*sizeof(SElemType));//C
    if(!S.base) { //存储分配失败
        return -1;
    }
    //栈顶指针等于栈底指针
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return 1;
}

/**
 * 判空
 */
int EmptyStack(SqStack S) {
    return S.base == S.top ? 1 : 0;
}

/**
* 求长度
*/
int LengthStack(SqStack S) {
    return *S.top + *S.base;
}

/**
* 清空栈
*/
void ClearStack(SqStack S) {
    if(S.base) {
        S.top = S.base;
    }
}

/**
* 销毁栈
*/
void DestroyStack(SqStack &S) {
    if(S.base) {
        //delete S.base;//C++
        free(S.base);//C 释放数组存储空间
        S.base = S.top =NULL;
        S.stacksize = 0;
    }
}

/**
* 入栈
*/
int PushStack(SqStack &S,int e) {
    if(S.top - S.base == MAXSIZE) {
        //栈满了
        return -1;
    }
    //可以合并一步  *(S.top)++ = e;   *的运算级优先级比较高 先执行*S.top的赋值  然后++
    *S.top = e;
    S.top++;
    return 1;
}

/**
* 出栈
*/
int PopStack(SqStack &S,int &e) {
    //栈空 下溢判断
    if(EmptyStack(S)){
        return  -1;
    }
    //e = *--S.top;
    --S.top;
    e = *S.top;
    return e;
}

int mainSqStackTest() {
    SqStack S;
    InitStack(S);
    int i;
    //遍历入栈
    for (i = 1; i <= 10; i++) {
        if (S.top - S.base != MAXSIZE) {
            PushStack(S, i);
        }
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