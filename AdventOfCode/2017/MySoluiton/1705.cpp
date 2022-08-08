#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    vector<int> input;
    void Solve() {
        int n;
        while (scanf("%d", &n) == 1) {
            input.emplace_back(n);
        }
        int no = 0;
        int steps = 0;
        vector<int> a(input);
        while (0 <= no && no < a.size()) {
            no += a[no]++;
            ++steps;
        }
        printf("%d\n", steps);
        steps = 0;
        no = 0;
        vector<int> b(input);
        while (0 <= no && no < b.size()) {
            (b[no] >= 3) ? no += b[no]-- : no += b[no]++;
            ++steps;
        }
        printf("%d\n", steps);
    }
};

int main() {
    Solution().Solve();
    return 0;
}