#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Solution {
    int N;
    int ans = 0;
    vector<int> cookies, racks;

    void Solve() {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            cookies.emplace_back(x);
        }
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            racks.emplace_back(x);
        }
        sort(cookies.begin(), cookies.end());
        sort(racks.begin(), racks.end());
        int i = 0;
        for (int j = 0; j < N; j++) {
            if (cookies[i] <= racks[j]) {   
                ans++;
                i++;
            }
        }
        printf("%d\n", ans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
} 