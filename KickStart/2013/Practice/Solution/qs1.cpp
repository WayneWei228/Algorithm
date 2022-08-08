#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

char Buffer[101];

struct Solution {
    void Solve(int caseNo) {
        int n;
        string last;
        scanf("%d", &n);
        int count = 0;
        // 不受题目描述影响，想清什么对获取答案造成影响以简化思路
        for (int i = 0; i < n; i++) {
            scanf("%*[\r\n]%[^\r\n]", Buffer);
            string s = Buffer;
            // 只有比迄今为止最大的string小，才要排序
            if (s < last) ++count;
            // last 为迄今为止最大
            last = max(last, s);
        }
        printf("Case #%d: %d\n", caseNo, count);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}