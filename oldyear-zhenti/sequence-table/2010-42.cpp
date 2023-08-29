//
// Created by 孙昀 on 2023/8/29.
//
#include <stdio.h>

// 时间复杂度O（n），空间复杂度O（n）
void revers(int p,int a[],int n) {
    int tmp[p];
    for(int i = 0; i < p; i++) {
        tmp[i] = a[i]; //数组暂存前n个元素
    }
    for(int i = 0; i < n-p; i++) {
        a[i] = a[i+p]; //从p+1开始的元素左移p个位置
    }
    for(int i = n-p; i < n; i++) {
        a[i] = tmp[i-(n-p)]; //前p个元素从暂存数组中赋值到原数组a的后p个位置
    }
}

// 时间复杂度O（n），空间复杂度O（1）
void revers2(int a[],int start,int end) {
    int tmp;
    int n = end-start+1;
    for(int i = start; i < n/2; i++) {
        tmp = a[n-i-1];
        a[n-i-1] = a[i];
        a[i] = tmp;
    }
}

#define n 6 //数组长度
#define p 2 //左移动位数
int main2010_42() {
    int a[n]{1,2,3,4,5,6};
    printf("原始数组：\n");
    for(int i = 0; i < n; i++) {
        printf("%2d",a[i]);
    }
    printf("\n");
    printf("左移动%d位后的数组：\n",p);
    //revers(p,a,n);
    revers2(a,0,n-1);
    revers2(a,0,n-p-1);
    revers2(a,n-p,n-1);
    for(int i = 0; i < n; i++) {
        printf("%2d",a[i]);
    }
    return 0;
}