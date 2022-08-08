#include <cstdio>
using namespace std;

struct Solution {
    void Solve() {
        int n = 2534, x = 2;
        while (x < n) x = (x << 2) + 2;
        printf("%d\n", x - n);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
