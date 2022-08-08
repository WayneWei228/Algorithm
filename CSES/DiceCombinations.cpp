#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N;
    vector<int> v;
    void Solve() {
        scanf("%d", &N);
        v.resize(N + 1);
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
        v[3] = 4;
        // v[4] = 
    }
};

int main() {
    Solution().Solve();
    return 0;
}