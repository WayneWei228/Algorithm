#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N;
    vector<int> L;

    void Solve() {
        scanf("%d", &N);
        L.emplace_back(0);
        while (L.back() < N) {
            L.emplace_back(L.back() + L.size() + 2 + L.back());
        }
        for (int i = L.size() - 2; i >= 0; --i) {
            if (L[i] + i + 3 < N) {
                N -= L[i] + i + 3;
            } else if (L[i] < N) {
                printf("%c\n", N == L[i] + 1 ? 'm' : 'o');
                return;
            }
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}
