#include <cstdio>
#include <limits>
#include <string>
#include <vector>
using namespace std;

char Buffer[200];

struct Solution {
    int Answer1 = 0, Answer2 = 0;

    int Divisible(const vector<int>& a) {
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a.size(); ++j) {
                if (i == j) continue;
                if (a[i] % a[j] == 0) {
                    return a[i] / a[j];
                }
            }
        }
        return 0;
    }

    void Solve() {
        while (true) {
            vector<int> a;
            while (true) {
                int num;
                char behind;
                if (scanf("%d%c", &num, &behind) < 2) break;
                a.emplace_back(num);
                if (behind != '\t') break;
            }
            if (a.empty()) break;
            Answer1 += *max_element(a.begin(), a.end()) -
                       *min_element(a.begin(), a.end());
            Answer2 += Divisible(a);
        }
        printf("%d\n", Answer1);
        printf("%d\n", Answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}