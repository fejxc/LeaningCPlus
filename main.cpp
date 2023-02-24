#include <iostream>
using namespace std;
/**
 *
 * @param num1
 * @param num2
 * @return
 */
int numAdd(int num1, int num2) {
    return num1 + num2;
}
int main01() {
    int i , j;
    cin >> i >> j;
    cout << numAdd(i,j) << endl;
    //system("pause");
    return 0;

}