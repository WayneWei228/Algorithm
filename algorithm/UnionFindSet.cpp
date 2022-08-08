#include <cstdio>
#include <iostream>
using namespace std;

const int N = 110;

int father[N];
int ans;

void init(int n) {
    for(int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int findFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}


void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faA] = faB;
        ans--;
    }
}


int main() {
    int n, m, a, b;
    cin >> n >> m;
    init(n);
    ans = n;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        Union(a, b);
    }
    cout << ans << endl;
}