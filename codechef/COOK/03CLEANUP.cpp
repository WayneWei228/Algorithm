#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;

struct Solution {
    int N, M;
    unordered_set<int> Finished;
    vector<int> A[2];

    void Solve() {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; ++i) {
            int x;
            scanf("%d", &x);
            Finished.emplace(x);
        }
        int d = 0;
        for (int i = 1; i <= N; ++i) {
            if (Finished.count(i)) continue;
            A[d].emplace_back(i);
            d = 1 - d;
        }
        for (int i = 0; i < 2; ++i) {
            bool head = true;
            for (int j = 0; j < A[i].size(); ++j) {
                if (head) {
                    printf("%d", A[i][j]);
                    head = false;
                } else {
                    printf(" %d", A[i][j]);
                }
            }
            if (A[i].size() == 0) {
                printf("-1");
            }
            printf("\n");
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}