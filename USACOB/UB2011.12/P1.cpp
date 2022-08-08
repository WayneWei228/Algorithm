#include <cstdio>
#include <vector>
using namespace std;

// done 
// 求平均数和实际值之差

struct Solution {
    int N;
    vector<int> A;

    void Solve() {
        scanf("%d", &N);
        A.resize(N);
        int sum = 0;
        for (int& i : A) {
            scanf("%d", &i);
            sum += i;
        }
        int each = sum / N, answer = 0;
        for (int i : A) answer += max(0, i - each);
        printf("%d\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
