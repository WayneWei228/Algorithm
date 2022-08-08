#include <cstdio>
using namespace std;

struct Solution {
    int N;
    int answer;
    void Solve() {
        scanf("%d", &N);
        answer = 0;
        int i = 0;
        while (i <= N) {
            int t = N - i;
            if (t % 4 == 0) answer++;
            i += 5;
        }
        printf("%d\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}