// 二维差分 
/*
sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]
sum[i-1][j] = a[i-1][j] + sum[i-2][j] + sum[i-1][j-1] - sum[i-1][j-1]
sum[i][j-1] = a[i][j-1] + sum[i-1][j-1] + sum[i][j-2] - sum[i-1][j-2]
sum[i-1][j-1] = a[i-1][j-1] + sum[i-2][j-1] + sum[i-1][j-2] - sum[i-2][j-2]

p[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1]
p[i-1][j] = a[i-1][j] - a[i-2][j] - a[i-1][j-1] + a[i-2][j-1]
p[i][j-1] = a[i][j-1] - a[i-1][j-1] - a[i][j-2] + a[i-1][j-2]
p[i-1][j-1] = a[i-1][j-1] - a[i-2][j-1] - a[i-1][j-2] + a[i-2][j-2]

a[i][j] = sum[i][j] - sum[i-1][j] - sum[i][j-1] + sum[i-1][j-1]
a[i-1][j] = sum[i-1][j] - sum[i-2][j] - sum[i-1][j-1] + sum[i-2][j-1]
a[i][j-1] = sum[i][j-1] - sum[i-1][j-1] - sum[i][j-2] + sum[i-1][j-2]
a[i-1][j-1] = sum[i-1][j-1] - sum[i-2][j-1] - sum[i-1][j-2] + sum[i-2][j-2]

// bp: p的前缀和 没用
bp[i][j] = p[i][j] + bp[i-1][j] + bp[i][j-1] - bp[i-1][j-1]
bp[i-1][j] = p[i-1][j] + bp[i-2][j] + bp[i-1][j-1] - bp[i-2][j-1]
bp[i][j-1] = p[i][j-1] + bp[i-1][j-1] + bp[i][j-2] - bp[i-1][j-2]
bp[i-1][j-1] = p[i-1][j-1] + bp[i-2][j-1] + bp[i-1][j-2] - bp[i-2][j-2]

a[i][j] = p[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1]


//化简后
p[i][j] = sum[i][j] - 2sum[i-1][j] - 2sum[i][j-1] + 4sum[i-1][j-1] + sum[i-2][j] - 2sum[i-2][j-1] + sum[i][j-2] - 2sum[i-1][j-2] + sum[i-2][j-2]

p[i][j] = sum[i][j] - sum[i-1][j] - sum[i][j-1] + sum[i-1][j-1] 
        -sum[i-1][j] + sum[i-2][j] + sum[i-1][j-1] - sum[i-2][j-1]
        -sum[i][j-1] + sum[i-1][j-1] + sum[i][j-2] - sum[i-1][j-2]
        +sum[i-1][j-1] - sum[i-2][j-1] - sum[i-1][j-2] + sum[i-2][j-2]


*/
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1e3 + 6;
const int MAXM = 1e3 + 6;
int a[MAXN][MAXM];
int diff[MAXN][MAXM];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    int i, j;
    

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> a[i][j];
            diff[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
        }
    }

    for(i = 0; i < q; i++) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        diff[x1][y1] += c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y1] -= c;
        diff[x2 + 1][y2 + 1] += c;
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            cout << diff[i][j]; 
        }
        cout << endl;
    }
    return 0;
}

/*
3 4 3
1 2 2 1
3 2 2 1 
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1
*/






