#include <cstdio>
using namespace std;

typedef long long int64;

struct Solution {
    int R, C;

    void Solve() {
        scanf("%*[^.].  Enter the code at row %d, column %d.", &R, &C);
        int index = (R + C - 1) * (R + C - 2) / 2 + C;
        int64 answer = 20151125;
        for (int i = 2; i <= index; ++i) {
            answer = answer * 252533 % 33554393;
        }
        printf("%lld\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}