#include <cstdio>
using namespace std;

struct Solution {
    int Depth = 0;

    void Solve() {
        int c0 = 0, c1 = 0;
        while (true) {
            if (c0 != 0 && Depth == 0) putchar(c0);
            c0 = c1;
            c1 = getchar();
            if (c1 == EOF) break;
            if (c0 == '/' && c1 == '*') {
                ++Depth;
                c0 = c1 = 0;
            } else if (0 < Depth && c0 == '*' && c1 == '/') {
                --Depth;
                c0 = c1 = 0;
            }
        }
        putchar(c0);
    }
};

int main() {
    printf("Case #1:\n");
    Solution().Solve();
    return 0;
}