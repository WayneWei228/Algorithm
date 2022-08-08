#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <limits>
#include <vector>
using namespace std;

/*
时间轴
时间越长，所用energy越少
时间越少，所用energy越大

*/

int BSearch(int lower, int upper, function<bool(int)> f) {
    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        f(mid) ? upper = mid : lower = mid + 1;
    }
    return lower;
}

struct Speed {
    int Value;
    bool Left = false;
};

struct Balloon {
    int P, H;
    bool Left = false;
};

struct Solution {
    int N, M, Q;
    vector<Speed> V;
    vector<Balloon> B;

    void Solve(int caseNo) {
        scanf("%d%d%d", &N, &M, &Q);
        V.resize(M);
        for (Speed& i : V) {
            scanf("%d", &i.Value);
            if (i.Value < 0) {
                i.Value = -i.Value;
                i.Left = true;
            }
        }
        B.resize(N);
        for (Balloon& i : B) {
            scanf("%d%d", &i.P, &i.H);
            if (i.P < 0) {
                i.P = -i.P;
                i.Left = true;
            }
        }
        // [0, 10001] 但 最右边（10001）不询问
        int answer = BSearch(0, 10001, [&](int time) {
            int totalQ = 0;
            for (Balloon& i : B) {
                int minQ = numeric_limits<int>::max();
                for (int j = 0; j < M; ++j) {
                    if (i.P == 0 || (V[j].Left != i.Left &&
                                     i.P <= V[j].Value * time)) {
                        minQ = min(minQ, abs(j - i.H));
                    }
                }
                if (minQ == numeric_limits<int>::max()) return false; // 没有一个高度可以使气球回到P0处
                totalQ += minQ;
            }
            return totalQ <= Q;
        });
        if (answer == 10001) {
            printf("Case #%d: IMPOSSIBLE\n", caseNo);
        } else {
            printf("Case #%d: %d\n", caseNo, answer);
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}