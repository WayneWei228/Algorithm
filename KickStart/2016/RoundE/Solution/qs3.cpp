#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N, D;

    void Solve(int caseNo) {
        scanf("%d%d", &N, &D);
        int answer = 0;
        for (int i = D; i <= N; i += D) {
            int maxProvide = (N - i) / i * 2; // 最大可能的余数
            int need = N % i; // 需要的余数
            if (maxProvide < need) continue;
            answer += Put(N - i, {i, i + 1, i + 2}); // Put算拼法
        }
        printf("Case #%d: %d\n", caseNo, answer);
    }


/*
i, i + 1, i + 2 拼出 N - i的必要条件是
如果N % i大，则需要很多 0, 1, 2
0, 1, 2 拼出 N % i (余数必须得拼对)
*/
    int Put(int n, const vector<int>& a) {
        vector<int> W(n + 1);
        W[0] = 1;
        for (int i : a) {
            // 从大到小，只有一次
            // 从小到大，无限多次
            for (int j = i; j <= n; ++j) W[j] += W[j - i];
        }
        return W.back();
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}