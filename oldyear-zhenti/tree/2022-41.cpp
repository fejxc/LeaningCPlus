//
// Created by 孙昀 on 2023/9/4.
//
#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 20011
typedef struct {
    int SqBiTNode[MAX_SIZE];
    int ELemNum;
} SqBiTree;

// 辅助函数：递归检查BST的有效性
bool helper(SqBiTree T, int i, long long lower, long long upper) {
    if (i >= T.ELemNum || T.SqBiTNode[i] == -1) { // 如果节点越界或为空
        return true; // 空节点可以看作是有效的BST
    }
    if (T.SqBiTNode[i] <= lower || T.SqBiTNode[i] >= upper) { // 如果节点值不在上下界内
        return false; // 不是有效的BST
    }
    // 递归检查左子树和右子树
    //对于左子树，我们将限制节点值的上界为当前节点的值，因为左子树中的节点必须小于当前节点。这确保了左子树中的所有节点都在合理的范围内。
    //对于右子树，我们将限制节点值的下界为当前节点的值，因为右子树中的节点必须大于当前节点。这确保了右子树中的所有节点也都在合理的范围内。
    return helper(T, 2 * i + 1, lower, T.SqBiTNode[i]) && helper(T, 2 * i + 2, T.SqBiTNode[i], upper);
}

// 主函数：检查BST的有效性
bool isValidBST(SqBiTree T) {
    //对于根节点，它没有限制，可以取任何值，因此我们将其上界设置为正无穷大，下界设置为负无穷大。
    return helper(T, 0, LLONG_MIN, LLONG_MAX); // 调用辅助函数，设置初始上下界
}

int main_2022_41() {
    // 构建一个有效的BST
    SqBiTree validBST;
    validBST.ELemNum = 7;
    validBST.SqBiTNode[0] = 4;
    validBST.SqBiTNode[1] = 2;
    validBST.SqBiTNode[2] = 6;
    validBST.SqBiTNode[3] = 1;
    validBST.SqBiTNode[4] = 3;
    validBST.SqBiTNode[5] = 5;
    validBST.SqBiTNode[6] = 7;

    bool isValid = isValidBST(validBST);
    printf("有效的BST: %s\n", isValid ? "true" : "false");

    // 构建一个无效的BST
    SqBiTree invalidBST;
    invalidBST.ELemNum = 5;
    invalidBST.SqBiTNode[0] = 5;
    invalidBST.SqBiTNode[1] = 2;
    invalidBST.SqBiTNode[2] = 6;
    invalidBST.SqBiTNode[3] = 1;
    invalidBST.SqBiTNode[4] = 7;

    isValid = isValidBST(invalidBST);
    printf("无效的BST: %s\n", isValid ? "true" : "false");

    return 0;
}
