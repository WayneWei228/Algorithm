#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct Solution {
    int R, C;
    vector<string> m;
    void Solve(int caseNo) {
        scanf("%d%d", &R, &C);
        m.resize(2 * R + 1);
        for (auto& i : m) {
            i = string(2 * C + 1, '*');
        }
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                m[i][j] = '.';
            }
        }
        for (int i = 0; i < m.size(); i++) {
            char k = (i % 2 == 0) ? '+' : '|';
            for (int j = 0; j < m[i].size(); j++) {
                if (m[i][j] == '.') continue;
                if (i % 2 == 0) {
                    m[i][j] = k;
                    k ^= 6;
                } else {
                    m[i][j] = k;
                    k ^= 82;
                }
            }
        }
        printf("Case #%d:\n", caseNo);
        for (auto i : m) {
            printf("%s\n", i.c_str());
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}