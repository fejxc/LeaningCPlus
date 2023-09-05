//
// Created by 孙昀 on 2023/9/5.
//
#include <stdio.h>
#define MAXV 100
typedef struct {                    // 图的定义
    int numVertices, numEdges;      // 图中实际的顶点数和边数
    char VerticesList[MAXV];        // 顶点表，MAXV为已定义常量
    int Edge[MAXV][MAXV];           // 邻接矩阵
}MGraph;
//时间复杂度O（n*n） 空间复杂度O（1）
int IsExistEL(MGraph G) {
    int degree = 0;
    int count = 0;
    // 遍历无向图统计所有点的度
    for (int i = 0; i < G.numVertices; i++) {
        degree = 0; // 重置
        // 计算点i的度
        for (int j = 0; j < G.numVertices; j++) {
            degree += G.Edge[i][j];
        }
        // 检查点i的度是否为奇数
        if (degree % 2 != 0) {
            count++;
        }
    }
    // 检查度为奇数的点个数是否为0或者2
    if (count == 0 || count == 2) {
        return 1;  // 存在EL路径
    } else {
        return 0;  // 不存在EL路径
    }
}

int main_2021_41() {
    MGraph G;
    G.numVertices = 5;

    int edges[5][5] = {
            {0, 1, 0, 1, 0},
            {1, 0, 1, 0, 1},
            {0, 1, 0, 1, 0},
            {1, 0, 1, 0, 1},
            {0, 1, 0, 1, 0}
    };

    for (int i = 0; i < G.numVertices; i++) {
        for (int j = 0; j < G.numVertices; j++) {
            G.Edge[i][j] = edges[i][j];
        }
    }

    int result = IsExistEL(G);

    if (result == 1) {
        printf("存在欧拉路径\n");
    } else {
        printf("不存在欧拉路径\n");
    }

    return 0;
}