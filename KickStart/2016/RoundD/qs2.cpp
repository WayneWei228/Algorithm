#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int R, C;
    vector<vector<bool>> v;
    void Solve(int caseNo) {
        scanf("%d%d", &R, &C);
        R += 2, C += 2;
        v.resize(R);
        for (auto& i : v) {
            i.resize(C);
        }
        Search(1, 1);
    }

    void Search(int x, int y) {
        
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 