//
// Created by 孙昀 on 2023/7/30.
//
#include <stdio.h>
#include <stdlib.h>
/**
 * 划分函数
 * @param a 原始数组
 * @param l 左指针
 * @param r 右指针
 * @return
 */
int huafen(int a[], int l, int r) {
    //选中枢元素
    int mid = a[l];
    while(l < r) {
        while(a[r] >= mid && l < r) {
            r--;
        }
        a[l] = a[r];
        while (a[l] <= mid && l < r) {
            l++;
        }
        a[r] = a[l];
    }
    a[l] = mid;
    return l;
}
int getArrayLength(int a[]) {
    return  sizeof (a)/sizeof (int);
}
int printArray(int a[],int size) {
    int i = 0;
    for( i = 0; i < size; i++) {
        printf("%2d2",a[i]);
    }
}
void quickSort(int a[], int l, int r) {
    //递归终止条件
    if(l >= r)
        return;
    int m = huafen(a,l,r);
    //左部分
    quickSort(a,l,m-1);
    //右部分
    quickSort(a,m+1,r);
    printArray(a,sizeof (a)/sizeof (a[0]));
}



//
//int main(){
//    int a[6] = {12,12,12,45,78,6};
//    printArray(a,sizeof (a)/sizeof (a[0]));
//    //printf("\n");
//    quickSort(a,0, 5);
//    return 0;
//}
