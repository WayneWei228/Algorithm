#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

/*
ST (Sparse Table)
O(nlogn) 构造二维表
O(1) 查询 [l, r] 区间最值
F[i, j] : [i, i + 2 ^ j - 1] 区间的最值,区间长度为 2^j
递推公式: F[i, j] = max(F[i, j - 1], F[i + 2 ^ (j - 1), j - 1]);
数组长度为 n, 最大长度区间 2 ^ k <= n <= 2 ^ (k + 1)
k = log2n 下取整

*/
struct Solution {
    vector<vector<int>> F;
    vector<int> a;
    void ST_create(int n) {
        for (int i = 1; i <= n; ++i) {  // 初始化
            F[i][0] = a[i];  // 表示[i, i]区间的最值, 区间长度为 2 ^ 0;
        }
        int k = log2(n);
        for (int j = 1; j <= k; ++j) {
            for (int i = 1; i <= n - (1 << j) + 1;
                 ++i) {  // n - 2 ^ j + 1
                F[i][j] =
                    max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int ST_query(int l, int r) {
        int k = log2(r - l + 1);
        return max(F[l][k], F[r - (1 << k) + 1][k]);
    }
};

int main() { return 0; };