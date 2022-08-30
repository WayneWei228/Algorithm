#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/*
异或符号: 相同为0, 不同为1
1 ^ 0 -> 0
0 ^ 0 -> 1
任何数跟0异或不变

0 ^ 1 -> 1
1 ^ 1 -> 0
任何数跟1异或变化


新值是原串中相邻三位的异或
*/

char Buffer[51];

struct  Solution {
    string S; // 之后
    vector<string> Answer; 

    void Inverse(int n0, int n1) {
        string inv(S.size(), 0); // 之前
        inv[0] = '0' + n0;
        inv[1] = '0' + n1;
        for (int i = 2; i < S.size(); i++) {
            inv[i] = S[i - 1] ^ inv[i - 1] ^ inv[i - 2];
        }
        char s0 = inv[S.size() - 1] ^ inv[0] ^ inv[1];
        if (s0 != S[0]) return;
        char sl = inv[S.size() - 2] ^ inv[S.size() - 1] ^ inv[0];
        if (sl != S[S.size() - 1]) return;
        Answer.emplace_back(inv);
    }

    void Solve() {
        scanf("%s",Buffer);
        S = Buffer;
        for (int i0 = 0; i0 < 2; i0++) {
            for (int i1 = 0; i1 < 2; i1++) {
                Inverse(i0, i1);
            }
        }
        if (Answer.empty()) {
            printf("No solution\n");
        } else if (2 <= Answer.size()) {
            printf("Multiple solutions\n");
        } else {
            printf("%s\n", Answer[0].c_str());
        }
        return;
    }
};


int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}