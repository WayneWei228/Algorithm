#include <cstdio>
#include <limits>
#include <vector>
using namespace std;

struct Solution {
    int N;

    int Compute(int c, int t) {
        int bound = 1024;
        while (true) {
            vector<int> a(bound + 1);
            for (int i = 1; i <= bound; ++i) {
                int available = c;
                for (int j = i; j <= bound; j += i) {
                    a[j] += i;
                    if (--available == 0) break;
                }
                if (a[i] * t >= N) return i;
            }
            bound += bound;
        }
    }

    void Solve() {
        scanf("%d", &N);
        printf("%d\n", Compute(numeric_limits<int>::max(), 10));
        printf("%d\n", Compute(50, 11));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
