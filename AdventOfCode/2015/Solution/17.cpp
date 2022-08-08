#include <cstdio>
#include <limits>
#include <vector>
using namespace std;

const int N = 150;

struct Solution {
    vector<int> Input; // 存容器
    // 20, 15, 10, 5
    int Ways() {
        vector<int> answer(N + 1); // 5
        answer[0] = 1;
        for (int i : Input) {
            for (int j = N; j >= i; --j) {
                answer[j] += answer[j - i];
            }
        }
        
        for (int i = 0; i <= N; i++) {
            printf("%d ", i);
        }
        return answer[N];
    }

    int WaysOpt() {
        vector<int> answer(N + 1), opt(N + 1);
        for (int i = 1; i <= N; ++i) {
            opt[i] = numeric_limits<int>::max() / 2;
        }
        answer[0] = 1;
        for (int i : Input) {
            for (int j = N; j >= i; --j) {
                int opt1 = opt[j - i] + 1;
                if (opt1 < opt[j]) {
                    opt[j] = opt1;
                    answer[j] = answer[j - i];
                } else if (opt1 == opt[j]) {
                    answer[j] += answer[j - i];
                }
            }
        }
        return answer[N];
    }

    void Solve() {
        int x;
        while (scanf("%d", &x) == 1) Input.emplace_back(x);
        printf("%d\n", Ways());
        printf("%d\n", WaysOpt());
    }
};

int main() {
    Solution().Solve();
    return 0;
}