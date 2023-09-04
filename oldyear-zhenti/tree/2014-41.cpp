//
// Created by 孙昀 on 2023/9/4.
//
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    int weight;  // 节点的权重
    struct TreeNode* left;  // 左子树
    struct TreeNode* right;  // 右子树
}*BiTree,TreeNode;

// 创建一个新节点
TreeNode* createNode(int weight) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->weight = weight;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
//深度优先搜索（DFS）计算二叉树的带权路径长度时
int dfs(BiTree root, int depth) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {//叶子节点，计算带权路径权值
        return root->weight * depth;
    }
    return dfs(root->left, depth + 1) + dfs(root->right, depth + 1);
}

//dfs的通俗易懂的版本
int calculateWeightedPathLength(BiTree root, int depth) {
    // 如果当前节点为空，返回0（递归的终止条件）
    if (root == NULL) {
        return 0;
    }

    // 如果当前节点是叶子节点，计算并返回带权路径权值
    if (root->left == NULL && root->right == NULL) {
        int weightedValue = root->weight * depth;
        return weightedValue;
    }

    // 递归计算左子树和右子树的带权路径长度，并将它们相加
    int leftPathLength = calculateWeightedPathLength(root->left, depth + 1);
    int rightPathLength = calculateWeightedPathLength(root->right, depth + 1);

    // 返回当前节点的带权路径长度，包括左子树和右子树的贡献值
    return leftPathLength + rightPathLength;
}

int pathSum(BiTree root) {
    return calculateWeightedPathLength(root, 0);
}

int main() {
    // 构建示例二叉树
    TreeNode* root = createNode(1);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(1);
    root->left->right = createNode(2);

    // 计算带权路径长度
    int weightedPathLength = pathSum(root);

    printf("带权路径长度: %d\n", weightedPathLength);

    // 释放内存
    // 注意：在实际应用中，需要释放整个二叉树的内存
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
