#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int Answer1 = 0, Answer2 = 0;

    int DivideResult(const vector<int>& a) {
        for (int i = 0; i < a.size(); ++i) {
            for (int j = i + 1; j < a.size(); ++j) {
                if (a[i] % a[j] == 0) return a[i] / a[j];
                if (a[j] % a[i] == 0) return a[j] / a[i];
            }
        }
        return 0;
    }

    void Solve() {
        while (true) {
            vector<int> a;
            while (true) {
                int x;
                char c;
                if (scanf("%d%c", &x, &c) < 2) break;
                a.emplace_back(x);
                if (c != '\t') break;
            }
            if (a.empty()) break;
            Answer1 += *max_element(a.begin(), a.end()) -
                       *min_element(a.begin(), a.end());
            Answer2 += DivideResult(a);
        }
        printf("%d\n", Answer1);
        printf("%d\n", Answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
