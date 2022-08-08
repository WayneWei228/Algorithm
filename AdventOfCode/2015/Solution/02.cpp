#include <algorithm>
#include <cstdio>
using namespace std;

struct Solution {
    void Solve() {
        int answer1 = 0, answer2 = 0;
        while (true) {
            int a[3];
            if (scanf("%dx%dx%d", &a[0], &a[1], &a[2]) < 3) break;
            sort(a, a + 3);
            answer1 +=
                a[0] * a[1] * 3 + a[1] * a[2] * 2 + a[2] * a[0] * 2;
            answer2 += (a[0] + a[1]) * 2 + a[0] * a[1] * a[2];
        }
        printf("%d\n%d\n", answer1, answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
