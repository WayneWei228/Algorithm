#include <cstdio>
#include <unordered_map>
using namespace std;

typedef long long int64;

struct Solution{
    int64 ans1 = 0, ans2;
    unordered_map<int64, int64> M;
    bool flag = true;

    void Solve() {
        int d;
        M.emplace(0, 0);
        while (scanf("%d ", &d) == 1) {
            ans1 += d;
            auto push = M.emplace(ans1, ans1).second;
            if (!push && flag) {
                ans2 = ans1;
                flag = false;
            }
        } 
        printf("%lld\n", ans1);
        printf("%lld\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}