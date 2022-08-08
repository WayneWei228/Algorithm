#include <cmath>
#include <cstdio>
#include <limits>
#include <vector>
using namespace std;

/*
约束传播搜索


0 1 2 3 4 5 6 7
0 1 2 3  4 5 6 7
000      100

前一场不想相遇
把最后一位扔掉看看一不一样
011 扔 末尾1
前两场不想相遇
把最后两位扔掉看看一不一样
011 扔 末尾11
没有前N场不想相遇的情况，因为都是空串
最多可以前N - 1 场不想相遇
只留下最前面的（最高位）一个数且两数不相等

对于第一个精灵选择几号位都没区别
如何将一号精灵调整到零号位：
遇0左右不换，遇1左右换
更新其他精灵方式：

XOR：不同则为1 相同则为0
：把其中一个操作数拿出来
a ^ b ： 
if b 的某一位为0
答案的这一位就是a的这一位
反之 取反
等同于 条件取反
以一个数为条件 把另一个数取反

一号：101
有一个精灵：110
011

*/
struct Solution {
    int N, M;
    vector<vector<int>> D, A;

    /* D： 邻接矩阵
    D[i][j]: i 和 j 两个精灵前K轮因为i的原因不能相遇
    */

    void Solve(int caseNo) {
        scanf("%d%d", &N, &M);
        D.resize(1 << N); 
        for (auto& i : D) i.resize(1 << N, 0);
        int maxB = 0, arg = -1;
        for (int i = 0; i < M; ++i) {
            int e, k, b;
            scanf("%d%d%d", &e, &k, &b);
            for (int j = 0; j < b; ++j) {
                int id;
                scanf("%d", &id);
                D[e - 1][id - 1] = k;
            }
            if (maxB < b) {
                maxB = b;
                arg = e - 1;
            }
        }
        A.resize(1 << N);
        /*
        A[i]: i这个精灵能够在的位置
        每个人一开始可以在所有位置
        */
        for (auto& i : A) {
            i.resize(1 << N);
            for (int j = 0; j < i.size(); ++j) i[j] = j;
        }
        bool answer = Propagate(A, arg, 0) && Search(A);
        printf("Case #%d: %s\n", caseNo, answer ? "YES" : "NO");
    }

    // 找一个size不是 1 但是size最小
    // Search 返回可不可以
    bool Search(const vector<vector<int>>& a) {
        int minSize = numeric_limits<int>::max(), arg = -1;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i].size() == 1) continue;
            if (a[i].size() < minSize) {
                minSize = a[i].size();
                arg = i;
            }
        }
        if (minSize == numeric_limits<int>::max()) return true;
        for (int i : a[arg]) {
            vector<vector<int>> newA = a;
            if (Propagate(newA, arg, i) && Search(newA)) return true;
        }
        return false;
    }
    /*
    让arg这个精灵选择位置c并且传播对别的精灵造成的影响
    如果有矛盾，返回false
    没有，返回true
    c 是 arg的位置
    */
    bool Propagate(vector<vector<int>>& a, int arg, int c) {
        a[arg].clear();
        a[arg].emplace_back(c);
        for (int i = 0; i < a.size(); ++i) {
            if (i == arg) continue;
            int d = max(D[i][arg], D[arg][i]); // i 和 arg 最大前多少轮不能相遇
            int oldSize = a[i].size(), newSize = 0;
            for (int j : a[i]) { // j 是 i 能放的位置（二进制表示）
                /*
                j ^ c = j 和 c 不同的地方是否仅仅在最右边的d位
                j ^ c产生01字符串，1表示不同，0表示相同
                */
                if ((1 << d) <= (j ^ c)) a[i][newSize++] = j;
            }
            a[i].resize(newSize);
            if (newSize == 0) return false;
            if (newSize == 1 && oldSize != 1) {
                // a[i][0]: i 能放的新位置
                if (!Propagate(a, i, a[i][0])) return false;
            }
        }
        return true;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}