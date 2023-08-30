//
// Created by 孙昀 on 2023/8/30.
//
#include <stdio.h>
int partition_2018_41(int arr[], int low, int high) {
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

void quickSort_2018_41(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_2018_41(arr, low, high);
        quickSort_2018_41(arr, low, pi - 1); //左半部分
        quickSort_2018_41(arr, pi + 1, high); //右半部分
    }
}
int func_2018_41(int a[],int n) {
    quickSort_2018_41(a,0,n-1);//快排
    int m = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            m = i;
            break;
        }
    }
    if(m == -1 || a[m] != 1) {
        return 1; //1元素没有出现过
    }
    for(int m = m+1; m < n; m++) {
        if(a[m] - a[m-1] > 1){
            return a[m-1] + 1; //中间未出现的元素
        }
    }
    return a[n-1]+1; //大于0的元素都是间隔1的，未出现的最小正整数是末尾元素+1
}
int main_2018_41() {
    int a[] = {-5,3,2,3};
    int b[] = {-5,-3,-2,-3};
    int c[] = {1,2,3,4};
    int mina = func_2018_41(a,4);
    int minb = func_2018_41(b,4);
    int minc = func_2018_41(c,4);
    printf("%d\n",mina);
    printf("%d\n",minb);
    printf("%d\n",minc);
}