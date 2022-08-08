#include <bits/stdc++.h>
using namespace std;

struct node {
    
};

int* p = new int; //  delete(p)
node* q = new node; // 分配地址

int* w = (int*)malloc(sizeof(int));    // free(w);
node* t = (node*)malloc(sizeof(node));

int main() {
    int a = 1;
    int& b = a;
    int& c = b;
    int& d = a;
    // a = a + 1;
    b++;
    cout << "a " << a << " b " << b << " c " << c << endl;
    return 0;


}

