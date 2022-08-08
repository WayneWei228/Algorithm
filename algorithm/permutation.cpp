#include <bits/stdc++.h>
using namespace std;

int n, b;
int a[1000];
void dfs(int x, int b) {
    if(x == n + 1) {
        for(int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++) {
        if((b & (1 << (i - 1))) == 0) {
            b ^= (1 << (i - 1));
            a[x] = i;
            dfs(x + 1, b);
            b ^= (1 << (i - 1));
        }
    }
}

int main() {
    n = 5;
    dfs(1, 0);
}