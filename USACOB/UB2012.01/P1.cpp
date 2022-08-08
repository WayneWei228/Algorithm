#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

// 在可优惠一个的情况下最大可买多少礼物
// ?

int BSearch(int lower, int upper, function<bool(int)> f) {
    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        f(mid) ? upper = mid : lower = mid + 1;
    }
    return lower;
}

typedef long long int64;

struct Gift {
    int64 P, S, T;

    bool operator<(const Gift& that) const { return T < that.T; }
};

struct Solution {
    int N, B;
    vector<Gift> Gifts;

    void Solve() {
        scanf("%d%d", &N, &B);
        Gifts.resize(N);
        for (Gift& i : Gifts) {
            scanf("%lld%lld", &i.P, &i.S);
            i.T = i.P + i.S;
        }
        sort(Gifts.begin(), Gifts.end());
        for (int i = 1; i < N; ++i) {
            Gifts[i].T += Gifts[i - 1].T;
        }
        int answer = 0;
        for (int i = 0; i < N; ++i) {
            int64 r = Gifts[i].P / 2 + Gifts[i].S;
            int maxBuy = BSearch(0, N, [&](int k) {
                if (k == 0) return B < r;
                if (k <= i) return B < Gifts[k - 1].T + r;
                return B < Gifts[k].T - (Gifts[i].P + Gifts[i].S) + r;
            });
            if (answer < maxBuy) answer = maxBuy;
        }
        printf("%d\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
