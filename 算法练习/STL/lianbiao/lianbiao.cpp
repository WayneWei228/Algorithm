#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

node* create (int Array[]) {
    node *p, *pre, *head;  //pre保存当前结点的前驱结点, head为头结点
    head = new node; // 创建头结点
    head -> next = NULL; // 头节点不需要数据域, 指针域初始化为NULL
    pre = head; // 记录pre 为head
    for(int i = 0; i < 5; i++) {
        p = new node; // 新建结点
        p -> data = Array[i];
        p -> next = NULL; // 新结点的指针域设为NULL
        pre -> next = p; // 前驱结点的指针域设为当前新建结点的地址
        pre = p;
    }
    return head; // 返回头结点指针
}

int search(node* head, int x) { // 查到元素在链表中的个数
    int count = 0;
    node* p = head->next;
    while(p != NULL) {
        if(p->data == x) {
            count++;
        }
        p = p->next;
    }
    return count;
}

// 将 x 插入以 head 为头节点的链表的第pos个位置上
void insert(node* head, int pos, int x) {
    node* p = head;
    for(int i = 0; i < pos - 1; i++) {
        p = p -> next; // pos - 1 是为了到插入位置的前一个结点
    }
    node* q = new node; 
    q->data = x;
    q->next = p->next;
    p->next = q;
}

void del(node* head, int x) {
    node* p = head->next;
    node* pre = head;
    while(p != NULL) {
        if(p->data == x) {
            pre->next = p->next;
            delete(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}
int main() {
    int Array[5] = {5, 3, 6, 1, 2};
    node* L = create(Array); // 新建链表，返回的头指针 head 赋给 L
    L = L -> next; // 从第一个节点开始有数据域
    while(L != NULL) {
        printf("%d ", L->data); // 输出每个节点的数据域
        L = L -> next;
    }
    return 0;
}