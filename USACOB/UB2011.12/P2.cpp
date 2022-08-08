#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

// ?

struct Solution {
    int N;
    vector<int> A, B[5];

    void Solve() {
        scanf("%d", &N);
        for (int i = 0; i < 5; ++i) {
            B[i].resize(N);
            for (int j = 0; j < N; ++j) {
                int x;
                scanf("%d", &x);
                B[i][x - 1] = j;
            }
        }
        A.resize(N);
        for (int i = 0; i < N; ++i) A[i] = i;
        sort(A.begin(), A.end(), [this](int a1, int a2) {
            int answer = 0;
            for (int i = 0; i < 5; ++i) {
                if (B[i][a1] < B[i][a2]) ++answer;
            }
            return 2 < answer;
        });
        for (int i : A) printf("%d\n", i + 1);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
