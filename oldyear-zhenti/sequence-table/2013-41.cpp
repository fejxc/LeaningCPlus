//
// Created by 孙昀 on 2023/8/30.
//
#include <stdio.h>
#include "qsort.h"
/**
 *
 * @param a 数组a
 * @param n 数组a的长度
 * @return
 */

int func_2013_41(int a[],int n){
    quickSortArray(a,0,n-1);//快排
    int m = a[n/2];//可能的主元素
    int count = 0;//m值的计数器
    for(int i = n/2-1; i>=0; i--){
        if(a[i] == m){ //处理左半边元素
            count++;
        }
    }
    for(int i = n/2+1; i<n; i++){
        if(a[i] == m){ //处理右半边元素
            count++;
        }
    }
    if(count+1 > n/2){//count+1 中间的可能主元素
        return a[n/2];
    }else {
        return -1;
    }
}

int main_2013_41(){
    int a[8] = {0,5,5,3,5,7,5,5};//主元素是5
    int b[8] = {0,5,5,3,5,1,5,7};//没主元素
    int resa = func_2013_41(a,8);
    int resb = func_2013_41(b,8);
    printf("%d",resa);
    printf("\n");
    printf("%d",resb);
}