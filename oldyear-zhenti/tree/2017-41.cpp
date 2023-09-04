//
// Created by 孙昀 on 2023/9/4.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    char data[10];  // 节点的数据，假设操作符和操作数都不超过10个字符
    struct TreeNode* left;  // 左子树
    struct TreeNode* right;  // 右子树
}BtTree;

// 创建一个新节点
struct TreeNode* createNode(const char* data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 深度优先搜索遍历表达式树，构建表达式字符串
void dfs(BtTree* root) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {  // 如果只有一个数，不需要加括号 （根节点和叶子节点的情况）
        printf("%s", root->data);  // 输出叶子节点的数据（操作数）
    } else {
        //遍历其左子树之前添加左括号，遍历完右子树后添加右括号
        printf("(");  // 输出左括号，表示一个表达式
        dfs(root->left);  // 递归处理左子树
        printf("%s", root->data);  // 输出当前节点的数据（操作符）
        dfs(root->right);  // 递归处理右子树
        printf(")");  // 输出右括号，表示一个表达式结束
    }
}

// 处理整个表达式树，打印表达式字符串
void expressionTree(BtTree* root) {
    if (root == NULL) return;

    dfs(root->left);  // 处理左子树
    printf("%s", root->data);  // 输出根节点的数据（操作符）
    dfs(root->right);  // 处理右子树
}

int main() {
    // 构建示例表达式树
    TreeNode* root = createNode("*");
    root->left = createNode("+");
    root->right = createNode("*");
    root->left->left = createNode("a");
    root->left->right = createNode("b");
    root->right->left = createNode("c");
    root->right->right = createNode("-");
    root->right->right->right = createNode("d");

    // 输出表达式字符串
    expressionTree(root);
    printf("\n");

    // 释放内存
    // 注意：在实际应用中，需要释放整个表达式树的内存
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right->right->right);
    free(root->right);
    free(root);

    return 0;
}
