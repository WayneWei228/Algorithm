#include <cstdio>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
单调队列
a数组中找连续k个的最大值

写SlideMin

*/
vector<int> SlideMax(const vector<int>& a, int k) {
    vector<int> answer; // 放答案
    deque<int> dec; // 严格下降, 存a里面的下标, 下标所对应的值严格下降，放当前可选择的最大值的备选
    for (int i = 0; i < a.size(); ++i) {
        while (!dec.empty() && dec.front() <= i - k) dec.pop_front(); // 过期的出掉
        while (!dec.empty() && a[dec.back()] < a[i]) dec.pop_back(); // 不优的去掉
        // dec.back() 比 i 先过期，而且还小，就没有必要留
        dec.emplace_back(i);
        if (k - 1 <= i) answer.emplace_back(a[dec.front()]); // i + 1 = 当前size，只有size >= k，才有answer
    }
    return answer;
}

vector<vector<int>> Transpose(const vector<vector<int>>& m) {
    vector<vector<int>> answer(m[0].size());
    for (auto& i : answer) i.resize(m.size());
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            // 如果写成 : answer[i][j] = m[j][i] 慢5倍；
            // 读要按顺序读，写可以乱序写
            answer[j][i] = m[i][j];
        }
    }
    return answer;
}

typedef long long int64;

struct Solution {
    int N, K, C, X;
    vector<int> A, B;
    vector<vector<int>> M;

    void Solve(int caseNo) {
        scanf("%d%d%d%d", &N, &K, &C, &X);
        A.resize(N);
        for (int& i : A) scanf("%d", &i);
        B.resize(N);
        for (int& i : B) scanf("%d", &i);
        M.resize(N);
        for (int i = 0; i < N; ++i) {
            M[i].resize(N);
            for (int j = 0; j < N; ++j) {
                int64 m0 = A[i] * (i + 1);
                int64 m1 = B[j] * (j + 1);
                int64 m2 = C;
                M[i][j] = (m0 + m1 + m2) % X;
            }
        }
        for (auto& i : M) {
            auto r = SlideMax(i, K);
            swap(i, r);
        }
        auto m = Transpose(M);
        for (auto& i : m) {
            auto r = SlideMax(i, K);
            swap(i, r);
        }
        int64 answer = 0;
        for (const auto& i : m) {
            for (const auto& j : i) {
                answer += j;
            }
        }
        printf("Case #%d: %lld\n", caseNo, answer);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}