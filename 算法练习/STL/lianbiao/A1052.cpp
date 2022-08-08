// P267
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

struct Node{
    int address, data, next;
    bool flag;
}node[maxn];

bool cmp(Node a, Node b) {
    if(a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main() {
    for(int i = 0; i < maxn; i++) {
        node[i].flag = false;
    }
    int n, begin, address;
    cin >> n >> begin;
    for(int i = 0; i < n; i++) {
        cin >> address;
        cin >> node[address].data >> node[address].next;
        node[address].address = address;
    }
    int count = 0, p = begin;
    while(p != -1) {
        node[p].flag = true;
        count++;
        p = node[p].next;
    }
    if(count == 0) {
        cout << "0 -1" << endl;
    } else {
        sort(node, node + maxn, cmp);
    }

    cout << count << node[0].address << endl;
    for(int i = 0; i < count; i++) {
        if(i != count - 1) {
            cout << node[i].address << node[i].data << node[i + 1].address << endl;
        } else {
            cout << node[i].address << node[i].data << endl;
        }
    }
    return 0;
}