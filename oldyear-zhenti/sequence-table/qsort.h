//
// Created by 孙昀 on 2023/8/30.
//

#ifndef LEARNINGCPLUS_QSORT_H
#define LEARNINGCPLUS_QSORT_H

#endif //LEARNINGCPLUS_QSORT_H
int partitionArray(int arr[], int low, int high) {
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

void quickSortArray(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionArray(arr, low, high);
        quickSortArray(arr, low, pi - 1); //左半部分
        quickSortArray(arr, pi + 1, high); //右半部分
    }
}