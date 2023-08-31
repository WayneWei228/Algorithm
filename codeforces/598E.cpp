#include <cstdio>
#include <algorithm>
using namespace std;

int dp[31][31][51];

int f(int x, int y, int k) {
    if (dp[x][y][k]) return dp[x][y][k];
    for (int i = 1; i <= x - i; i++) {
        for (int j = 0; j <= k; j++) {
            dp[x][y][k] = min(dp[x][y][k], f(i, y, j) + f(x - i, y, k - j) + y * y);
        }
    }
    
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", f(a, b, c));
    }
}