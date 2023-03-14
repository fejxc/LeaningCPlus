//
// Created by Administrator on 2023/3/14.
//
#include <stdio.h>
#include <stdlib.h>
/**
 * 求n的阶层
 * 最后调用的最新返回，最新调用的最后返回
 * 递归工作栈（实现了函数的调用，实参，局部变量，返回结果 等等）
 * 递归的优点：结构清晰，程序可读性好
 * 递归的缺点：时间开销大
 *
 *
 * 递归变非递归：
 * 1、尾递归、单向递归->循环结构
 * 2、自己用栈模拟系统的运行时栈
 */
long Fact(long n) {
    if(n == 0) return 1;//基本项目
    else return Fact(n-1) * n;//归纳项
}

int mainFact() {
    long res = Fact(4);
    printf("%d",res);
}