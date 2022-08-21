#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

// 找到最大的小于某数的数
// lower_bound 第一个大于等于某数的数

struct Solution {
    int N;
    vector<int> A;
    vector<int> answer;

    void Solve(int caseNo) {
        scanf("%d", &N);
        A.resize(N);
        answer.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < A.size(); i++) {
            vector<int> S(A);
            sort(S.begin(), S.end());
            int l = 0, r = S.size() - 1;
            while (l < r) {  // <= 2 * A[i]
                int mid = l + (r - l) / 2 + 1;
                if (S[mid] > A[i] * 2) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            // printf("S[l] %d A[i] %d\n", S[l], A[i]);
            if (S[l] == A[i]) {
                if (l + 1 < S.size() && S[l + 1] == A[i]) {
                    l++;
                }
                l--;
                if (l < 0) {
                    answer[i] = -1;
                } else {
                    answer[i] = S[l];
                }
            } else {
                answer[i] = S[l];
            }
            // if (S[l] == A[i]) {
            //     while (S[l++] == A[i]);
            //     l--;  // rightmost
            //     if (l == 0) {
            //         answer[i] = -1;
            //     } else {
            //         answer[i] = S[l - 1];
            //     }
            // } else {
            //     answer[i] = S[l];
            // }
        }
        printf("Case #%d:", caseNo);
        for (int i = 0; i < answer.size(); i++) {
            printf(" %d", answer[i]);
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