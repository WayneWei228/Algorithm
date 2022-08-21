#include <cstdio>
#include <algorithm>
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
        for (int i = 0; i < answer.size(); i++) {
            vector<int> S(A);
            sort(S.begin(), S.end(), [&](int a, int b){
                return a < b;
            });
            for (int i = 0; i < S.size(); i++) {
                if (S[i] < A[i] * 2) {
                    answer[i] = S[i];
                    break;
                }
            }
            if (S[i] == A[i]) {
                
            }
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