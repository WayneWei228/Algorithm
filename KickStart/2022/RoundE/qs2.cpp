#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

// 找到最大的小于某数的数
// lower_bound 第一个大于等于某数的数
// upper_bound 第一个大于某数的数

/*
vector 用 upper_bound 因为支持随机访问
随意访问也就是 it 可以 += n or -= n (n 可以是任意整数)
multiset 不支持随意访问, 即指针 it 只能++ or --;
*/
struct Solution {
    int N;
    vector<int> A;
    multiset<int> S;

    void Solve(int caseNo) {
        scanf("%d", &N);
        A.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            S.emplace(A[i]);
        }
        printf("Case #%d:", caseNo);
        for (int i = 0; i < A.size(); i++) {
            S.erase(S.find(A[i]));
            int ans;
            auto it = S.upper_bound(2 * A[i]); // 正确, 全对
            // auto it = upper_bound(S.begin(), S.end(), 2 * A[i]); // 错误, Test Set 2 TLE
            if (it == S.begin()) {
                ans = -1;
            } else {
                ans = *(--it);
            }
            printf(" %d", ans);
            S.insert(A[i]);
        }
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}