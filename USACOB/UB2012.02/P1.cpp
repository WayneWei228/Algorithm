#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N, L, Answer = 0;
    vector<int> A;

    void Solve() {
        scanf("%d%d", &N, &L);
        A.resize(N);
        for (int& i : A) scanf("%d", &i);
        sort(A.begin(), A.end());
        for (int i = 0; i < N - 1; ++i) Fold(i, N - 1);
        for (int i = 1; i < N - 1; ++i) Fold(0, i);
        printf("%d\n", Answer);
    }

    void Fold(int i0, int i1) {
        int s = A[i0] + A[i1];
        while (i0 <= i1) {
            if (A[i0++] + A[i1--] != s) return;
        }
        ++Answer;
    }
};

int main() {
    Solution().Solve();
    return 0;
}
