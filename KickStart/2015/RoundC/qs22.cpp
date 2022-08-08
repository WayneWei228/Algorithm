#include <cstdio>
#include <vector>
using namespace std;


int BSearch(int lower, int upper, function<bool(int)> f) {
    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        f(mid) ? upper = mid : lower = mid + 1;
    }
    return lower;
}

struct Solution {
    int N;
    vector<pair<int, int>> v;
    void Solve(int caseNo) {
        scanf("%d", &N);
        v.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &v[i].first, &v[i].second);
        }
        
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}