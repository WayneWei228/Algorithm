#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

// 求数组的中位数
// ?
struct Solution {
    int N, K, A, B;
    vector<int> V;

    void Solve() {
        scanf("%d%d", &N, &K);
        V.resize(N + 2); // B + 1
        for (int i = 0; i < K; ++i) {
            scanf("%d%d", &A, &B);
            ++V[A];
            --V[B + 1];
        }
        for (int i = 1; i <= N; ++i) V[i] += V[i - 1]; 
        // why N instead of N + 1
        // because the V[N + 1] = 0
        // there are total N numbers;
        nth_element(V.begin() + 1,          //
                    V.begin() + 1 + N / 2,  //
                    V.begin() + 1 + N);
        printf("%d\n", V[1 + N / 2]);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
