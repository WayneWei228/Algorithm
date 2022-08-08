#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;

const int64 Mod = 1000000007;

// (a ^ b) % m
/* https://zhuanlan.zhihu.com/p/95902286
最初ans为1，然后我们一位一位算：

1010的最后一位是0，所以a^1这一位不要。然后1010变为101，a变为a^2。

101的最后一位是1，所以a^2这一位是需要的，乘入ans。101变为10，a再自乘。

10的最后一位是0，跳过，右移，自乘。

然后1的最后一位是1，ans再乘上a^8。循环结束，返回结果。

*/
int64 PowMod(int64 a, int64 b, int64 m) {
    int64 answer = 1;
    while (b != 0) {
        if (b & 1) answer = answer * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return answer % m;
}

struct Solution {
    int A, B, K;
    int64 N;

    void Solve(int caseNo) {
        scanf("%d%d%lld%d", &A, &B, &N, &K);
        int64 answer = 0;
        vector<int64> cA(K), cB(K);
        /*
        cA[i]: 1^A, 2^A, 3^A ... N^A 有几个mod K 余 i
        cB[i]: 同理

        */
        for (int i = 0; i < K; ++i) { // remainder can be [0, K - 1]
            int xA = PowMod(i, A, K), xB = PowMod(i, B, K);
            int64 count = CountMultiple(1 - i, N + 1 - i, K);
            // count: [1, N + 1) mod k == i 的个数
            // 两数之间mod k == i 的个数 等于 两数-i mod k == 0 的个数
            cA[xA] = (cA[xA] + count) % Mod;
            cB[xB] = (cB[xB] + count) % Mod;
            if ((xA + xB) % K == 0) answer -= count % Mod;
        }
        for (int iA = 0; iA < K; ++iA) {
            int iB = (K - iA) % K;
            answer += cA[iA] * cB[iB] % Mod;
        }
        answer %= Mod;
        answer += Mod;
        answer %= Mod;
        printf("Case #%d: %lld\n", caseNo, answer);
    }
    // 要求b为正数
    // 负数向负无穷接近 等于 正数向正无穷接近
    // -2, 5
    int64 DivUp(int64 a, int64 b) {
        if (a < 0) return -DivDown(-a, b);
        return (a + b - 1) / b;
    }

    int64 DivDown(int64 a, int64 b) {
        if (a < 0) return -DivUp(-a, b);
        return a / b;
    }
    // 找[begin, end)之间 mod m == 0 的个数
    int64 CountMultiple(int64 begin, int64 end, int64 m) {
        return DivDown(end - 1, m) - DivDown(begin - 1, m);
        // [1, end) mod m == 0 的个数 - [1, begin) mod m == 0 的个数
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}