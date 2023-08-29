//
// Created by Administrator on 2023/2/24.
//
#include <iostream>
using namespace std;
int mainTestPoint() {
    int i = 100;
    int * p;
    p = &i;
    cout << i << endl;
    cout << p << endl;
    cout << *p << endl;
    return 0;
}