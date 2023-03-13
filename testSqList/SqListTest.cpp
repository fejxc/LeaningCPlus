//
// Created by Administrator on 2023/2/28.
//
#include <stdio.h>
#include <stdlib.h>
typedef  int ElemType;
/**
 * 定义链表L: LinkList L;  （通常用）
 * 定义节点指针P： LNode *p;(通常用） 《=》 LinkList p;
 * 单链表是顺序的存取结构，不是随机存取的结构
 */
typedef struct LNode {
    ElemType data; //数据域
    struct LNode *next; //指针域 指向LNode的类型指针
}LNode, *LinkList;

/**
 * 初始化 带头节点的链表
 */
bool InitList(LinkList &L) {
    // L = new LNode; C++
    // L = (LinkList) malloc(sizeof(LNode)); C
    L = (LNode* )malloc(sizeof (LNode));
    if(L == NULL) {
        return false;
    }
    L->next = NULL;
    return true;
}

/**
 * 判空
 */
bool isEmpty(LinkList &L) {
    return L->next == NULL;
}

/**
 * 销毁单链表(包括头节点也消除）
 */
void DestroyList(LinkList &L) {
    LNode *p;//指向销毁节点
    while (L) {
        p = L;
        L = L->next;
        free(p);
    }
}

/**
 * 清空单链表(保留头节点）
 * 从首元节点开始删，保留头节点，头节点指向NULL
 */
void CleanList(LinkList &L) {
    LNode *p;
    LNode *q;
    p = L->next;
    while (p){
        q = p->next;//下个节点
        free(p);
        p = q;
    }
   L->next = NULL;//头节点指针域为空
}
/**
 * 求单链表表上 时间复杂度O(n)
 */
int LengthList(LinkList L) {
    LNode *p;
    p = L->next;//指向首元节点
    int length = 0;
    while (p){
        length++;
        p = p->next;
    }
    return length;
}

/**
 * 查找第i个元素的值（按位查找） 时间复杂度O(n)
 */
int getElementByPlace(LinkList &L,int i,int &e) {
    LNode *p;
    p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if(!p || j > i){
        return -1;
    }
    e = p->data;
    return e;
}

/**
 * 按值查找 时间复杂度O(n)
 */
int getElementByValue(LinkList &L,int e) {
    LNode *p;
    p = L->next;//首元节点
    int i = 1;
    while (p && p->data != e){
        p = p->next;
        i++;
    }
    if(!p){
        return -1;//没找到，查找失败
    }
    return i;
}

/**
 * 头插法
 */
LinkList listHeadInsert(LinkList &L) {
    LNode *s;
    int x = 8888;
    InitList(L);
    while (x != 9999) {
        if(x!=8888){
            s = (LNode* )malloc(sizeof (LNode));
            s->data = x; //新节点的值域
            s->next = L->next; //L的next域赋值给新节点的next域
            L->next = s; //新的节点接到头节点后面
        }
        scanf("%d", &x);
    }
    return L;
}
/**
 * 尾插法  需要一个尾指针一直指向最后的节点
 */
LinkList ListTailInsert(LinkList &L) {
    InitList(L);
    LNode *p,*r;
    r = L; //尾指针指向头节点
    int x=8888;
    while (x!=9999) {
        if(x!=8888){
            p = new LNode;
            p->next = NULL;//生成新的节点
            p->data = x;
            r->next = p; //插入到表尾
            r = p;//r指针指向新的尾节点
        }
        scanf("%d",&x);
    }
    return L;
}
/**
 * 在第i个位置前插入元素e 头节点是第0个位置，只要找到第i-1节点 插在其后就可以 时间复杂度O(1)
 */
bool ListInsert(LinkList &L,int i,ElemType e) {
    if(i < 1) {
        return false;
    }
    //指针p指向当前扫描的节点
    LNode *p;
    //初始化指向头节点
    p = L;
    int j = 0;
    //找到i-1个节点  插入的后一个节点可为NULL
    while (p != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    //i大于表长+1 或者小于1 擦换如位置非法
    if(p == NULL || j > i -1) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof (ElemType));//生成新的节点
    s->data = e;
    //顺序不能换，除非再加一个指针保存i+1个节点的地址
    s->next = p->next;
    p->next = s;
    return true;
}
/**
 * 删除第i个位置的节点 时间复杂度O(1)
 */
int DeleteElem(LinkList &L,int i,int &e){
    LNode *p,*q;
    p = L;
    int j = 0;
    //找到第i-1个节点  p->next != null 保证p后面还有节点 删除算法p后一个节点不可以为NULL
    while (p->next && j < i-1){
        p = p->next;
        j++;
    }
    //校验合法性
    if(!p->next || j > i - 1){
        return -1;
    }
    q = p->next; //指向待删除的节点
    e = q->data;
    p = p->next->next;
    free(q);
    return 1;
}
/**
 * 遍历打印链表的函数
 */
void traverse(LinkList L) {
    LNode *p = L->next; // 指向第一个节点
    while (p != NULL) {
        printf("%d ", p->data); // 输出节点的数据
        p = p->next; // 指向下一个节点
    }
}
/**
 * 主函数
 */
int main() {
    LinkList L;
    listHeadInsert(L);
    //ListTailInsert(L);
    traverse(L);
   // ListInsert(L,1,888);
    printf("\n");
    traverse(L);
    return 0;
}