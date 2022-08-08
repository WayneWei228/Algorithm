#include <cstdio>
#include <string>
#include <vector>
using namespace std;
struct Claim {
    int id, left, top, wide, tall;
};

struct Solution {
    vector<Claim> input;
    vector<vector<int>> M{};
    int ans1 = 0;
    int ans2;
    void Solve() {
        M.resize(1000);
        for (auto& i : M) i.resize(1000);
        Claim a;
        while (scanf("#%d @ %d,%d: %dx%d ", &a.id, &a.left, &a.top,
                     &a.wide, &a.tall) == 5) {
                         input.emplace_back(a);
            for (int i = a.top; i < a.top + a.tall; i++) {
                for (int j = a.left; j < a.left + a.wide; j++) {
                    M[i][j]++;
                }
            }
        }
        for (auto& i : M) {
            for (auto& j : i) {
                if (j > 1) ans1++;
            }
        }
        printf("%d\n", ans1);
        
        for (auto& a : input) {
            bool flag = true;
            for (int i = a.top; i < a.top + a.tall; i++) {
                for (int j = a.left; j < a.left + a.wide; j++) {
                    if (M[i][j] != 1) flag = false;
                }
            }
            if (flag) {
                ans2 = a.id;
                break;
            }
        }
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}