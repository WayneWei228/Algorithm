#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    vector<int> A;

    int Compute1(vector<int> a) {
        int current = 0, answer = 0;
        while (0 <= current && current < a.size()) {
            ++answer;
            current += a[current]++;
        }
        return answer;
    }

    int Compute2(vector<int> a) {
        int current = 0, answer = 0;
        while (0 <= current && current < a.size()) {
            ++answer;
            int next = current + a[current];
            if (a[current] >= 3) {
                --a[current];
            } else {
                ++a[current];
            }
            current = next;
        }
        return answer;
    }

    void Solve() {
        while (true) {
            int x;
            if (scanf("%d", &x) < 1) break;
            A.emplace_back(x);
        }
        printf("%d\n", Compute1(A));
        printf("%d\n", Compute2(A));
    }
};

int main() {
    Solution().Solve();
    return 0;
}