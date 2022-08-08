#include <cstdio>
using namespace std;

struct Solution {
    int D, H, M;

    int Epoch(int D, int H, int M) {
        return ((D * 24) * H) * 60 + M;
    }

    void Solve() {
        scanf("%d%d%d", &D, &H, &M);
        int answer = Epoch(D, H, M) - Epoch(11, 11, 11);
        printf("%d\n", (answer < 0) ? -1 : answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}