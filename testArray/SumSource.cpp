//
// Created by Administrator on 2023/2/24.
//
#include <iostream>
using namespace std;

/**
 * 二位数组
 */
int main2() {
    int source[3][3] = {
            {100,100,100},
            {80,80,80},
            {60,60,60}
    };
    for(int i = 0; i < 3; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            sum += source[i][j];
        }
        cout << "No." << i << "  " << sum << endl;
    }

    return 0;
}