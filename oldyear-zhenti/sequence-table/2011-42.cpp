//
// Created by 孙昀 on 2023/8/29.
//
#include <stdio.h>
int partition2(int arr[], int low, int high) {
    int pivot = arr[low];
    while (low<high) {
        while (arr[high] >= pivot && low < high){
            high--;
        }
        arr[low] = arr[high];
        while (arr[low] <= pivot && low < high){
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition2(arr, low, high);
        quickSort(arr, low, pi - 1); //左半部分
        quickSort(arr, pi + 1, high); //右半部分
    }
}
/**
 *
 * @param a 数组a
 * @param n 数组a的长度
 * @param b 数组b
 * @param m 数组b的长度
 * @return 中位数的数组下标
 */
int func(int a[], int n, int b[], int m){
    int c[m+n];
    for(int i=0; i < n; i++){
        c[i] = a[i];//赋值a的数据元素到数组c
    }
    for(int i=0; i < m; i++){
        c[i+n] = b[i];//赋值b的数据元素到数组c
    }
    quickSort(c,0,m+n-1);//快排
//    for(int i=0; i < m+n; i++){
//        printf("%4d",c[i]);
//    }
//    printf("\n");
//    printf("%d",c[(m+n-1)/2]); //注意(m+n-1)/2、 不要错写成m+n-1/2
    return c[(m+n-1)/2];
}
#define n 5
#define m 5
int main2011_42() {
    int a[n]={11,13,15,17,19};
    int b[m]={2,4,6,8,20};
    int mid = func(a,n,b,m);
    printf("\n");
    printf("中位数是%d",mid);
    return 0;
}
