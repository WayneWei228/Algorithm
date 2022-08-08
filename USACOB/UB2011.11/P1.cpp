#include <cstdio>
using namespace std;

struct Solution {
    int D, H, M;

    int Epoch(int d, int h, int m) { return (d * 24 + h) * 60 + m; }

    void Solve() {
        scanf("%d%d%d", &D, &H, &M);
        int answer = Epoch(D, H, M) - Epoch(11, 11, 11);
        printf("%d\n", answer < 0 ? -1 : answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
