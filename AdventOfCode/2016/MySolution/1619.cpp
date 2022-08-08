#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int input;

    int Compute1() {
        int t = 1;
        while (t * 2 < input) {
            t *= 2;
        }
        return (input - t) * 2 + 1;
    }
    // 1 2 3 4 5

    // 0 1 2 3 4 5 6 7
    // 0 1 2 3 4 5 6 7 8

    // 0 1 2 /3 4 5 6 /7
    // 1 2 3 /5 6 7 8 /0

    int Compute2(int m, int k) {
        while (true) {
            if (m++ == input) return k;
            int die = m / 2;
            if (k < die - 1) {
                k++;
            } else if (k < m - 2) {
                k += 2;
            } else {
                k = 0;
            }
        }
    }
    void Solve() {
        scanf("%d", &input);
        printf("%d\n", Compute1());
        printf("%d\n", Compute2(1, 0) + 1);
    }
};

int main() {
    Solution().Solve();
    return 0;
}