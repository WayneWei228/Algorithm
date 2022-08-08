#include <cstdio>
using namespace std;

struct Solution {
    int Depth = 0;
    void Solve(int caseNo) {
        int c0 = 0, c1 = 0;
        while (true) {
            // putchar 系统规定 用 int
            if (c0 != 0 && Depth == 0) putchar(c0);
            // 存两个，读一个，一前一后
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
        // 把最后一个c0输出出来
        putchar(c0);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        Solution().Solve(i);
    }
}