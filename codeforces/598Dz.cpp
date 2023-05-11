#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll read() {
    ll a = 0, b = getchar(), c = 1;
    while (!isdigit(b)) c = b == '-' ? -1 : 1, b = getchar();
    while (isdigit(b)) a = a * 10 + b - '0', b = getchar();
    return a * c;
}
ll n, m, k, s[100005], b[1005][1005], dx[4] = {-1, 0, 1, 0},
                                      dy[4] = {0, 1, 0, -1};
/*
5 6 3
******
*..*.*
******
*....*
******
2 2
2 5
4 3
*/
/*
b 一变两用
1. 作为 visited 数组
2. 相同联通块有相同的序号

s
s[序号] = 该序号的答案
*/
char a[1005][1005];
ll dfs(int x, int y, int z) {
    if (a[x][y] == '*') return 1;
    // 同一个联通块都是同一个序号
    b[x][y] = z;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!b[nx][ny]) res += dfs(nx, ny, z);
    }
    return res;
}

int main() {
    // freopen("output.out", "w", stdout);
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", a[i] + 1);  // 使得从 a[i][1] 开始读
    for (int i = 1; i <= k; i++) {
        int x = read(), y = read(), ans;
        // 如果访问过
        if (b[x][y])
            // 答案则是这个序号的答案
            ans = s[b[x][y]];
        else
            // 计算这个序号的答案
            ans = s[i] = dfs(x, y, i);
        printf("%d\n", ans);
    }
    return 0;
}