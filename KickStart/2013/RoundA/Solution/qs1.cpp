#include <cstdio>
#include <string>
#include <vector>
using namespace std;

// 奇数从小到大寸排序，偶数从大到小排序，排序后的奇偶顺序跟原本一样
 
struct Solution {
    void Solve(int caseNo) {
        int N;
        vector<int> a, b[2];
        scanf("%d", &N);
        a.resize(N);
        for (int& i : a) i = scanf("%d", &i);
        // 1 -> 1, 0 -> 0
        for (int i : a) b[i & 1].emplace_back(i);
        // 偶 小到大
        // 奇 大到小
        // 反着存
        sort(b[0].begin(), b[0].end());
        sort(b[1].begin(), b[1].end(), [](int a, int b) {
            return a < b;
        });
        printf("Case #%d: ", caseNo);
        bool head = true;
        for (int i = 0; i < N; ++i) {
            auto& b0 = b[a[i] & 1];
            // 第一次前无空格，之后有
            if (!head) printf(" ");
            head = false;
            printf("%d", b0.back());
            b0.pop_back();
        }
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        Solution().Solve(i);
    }
    return 0;
}