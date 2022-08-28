#include <cstdio>
#include <vector>

using namespace std;

struct Solution {
    int N;

    void Solve() {
        scanf("%d", &N);
        vector<int> a, b;
        a.resize(N);
        b.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &a[i], &b[i]);
        }    
        int aNeed, bNeed;
        scanf("%d%d", &aNeed, &bNeed);
        vector<int> P;
        P.resize(N);
        for (int i = 0; i < N; i++) {
            P[i] = a[i] / aNeed * b[i] - bNeed
        }

    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
} 
