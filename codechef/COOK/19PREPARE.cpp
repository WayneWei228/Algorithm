#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

int BSearch(int lower, int upper, function<bool(int)> f) {
    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        f(mid) ? upper = mid : lower = mid + 1;
    }
    return lower;
}

const int M = 1000;

struct Dish {
    int ByOtherCook, Bychef;
};
/*
vector<vector<char>> v;
v.resize(N);
for (auto& i : v) {
    i.resize(M + 1);
}
for (int i = 0; i <= M; i++) {
    v[0][i] = true;
}
v[i][j] : 选前 i 个能否恰好填满容量 j

for (int i = 1; i < N; i++) {
    for (int j = 0; j < M; j++) {
        if (j < D[i].byChef) {
            v[i][j] = v[i - 1, j];
        } else {
            if (v[i - 1, j - D[i].byChef]) {
                v[i, j] = true;
            }
        }
    }
}


S <= T
total - S <= T

valid range : total - T <= S <= T

if (time < total - time)

*/

struct Solution {
    int N;
    vector<Dish> D;

    void Solve() {
        scanf("%d", &N);
        D.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &D[i].ByOtherCook, &D[i].Bychef);
        }

        int answer = BSearch(0, M, [&](int time) {
            vector<char> v(M + 1);
            v[0] = true;
            int total = 0;
            for (int i = 0; i < N; i++) {
                if (D[i].ByOtherCook <= time) continue;
                total += D[i].Bychef;
                for (int j = M; j >= D[i].Bychef; j--) {
                    if (v[j - D[i].Bychef]) v[j] = true;
                }
            }
            for (int i = time; i >= 0; --i) {
                if (i < total - i) break;
                if (v[i]) return true;
            }
            return false;
        });
        printf("%d\n", answer);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        Solution().Solve();
    }
}
