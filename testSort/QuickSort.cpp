//
// Created by 孙昀 on 2023/7/30.
//
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
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

void quickSort2(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort2(arr, low, pi - 1);
        quickSort2(arr, pi + 1, high);
    }
}

int mainQuickSort() {
    int arr[] = {64, 34, 25, 12, 22, 11, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quickSort2(arr, 0, n - 1);

    printf("\n排序后的数组：\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}