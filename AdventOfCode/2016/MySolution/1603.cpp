#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;


//   883  357  185
struct Solution {
    int total1 = 0, total2 = 0;
    void Solve1() {
        while (true) {
            int a[3];
            if (scanf(" %d %d %d\n", &a[0], &a[1], &a[2]) < 3) break;
            sort(a, a + 3);
            if (a[0] + a[1] > a[2]) ++total1;
        }
        printf("%d\n", total1);
    }

    void Solve2() {
        int i = 0;
        while (true) {
            int a[3], b[3], c[3];
            if (scanf(" %d %d %d\n", &a[i], &b[i], &c[i]) < 3) break;
            ++i %= 3;
            if (i == 0) {
                sort(a, a + 3);
                sort(b, b + 3);
                sort(c, c + 3);
                if (a[0] + a[1] > a[2]) ++total2;
                if (b[0] + b[1] > b[2]) ++total2;
                if (c[0] + c[1] > c[2]) ++total2;
            }
        }
        printf("%d\n", total2);
    }
};

int main() {
    // Solution().Solve1();
    Solution().Solve2();
    return 0;
}