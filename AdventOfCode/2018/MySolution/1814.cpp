#include <cstdio>
#include <string>
using namespace std;

struct Solution {
    int after;
    string input;
    string S = "37";
    string ans1;
    int ans2 = -1;
    void Solve() {
        scanf("%d\n", &after);
        input = to_string(after);
        int idx1 = 0;  
        int idx2 = 1;
        while (int(S.size()) <= after + 10 || ans2 == -1) {
            int move1 = S[idx1] - '0';
            int move2 = S[idx2] - '0';
            int oldsize = S.size();
            S += to_string(move1 + move2);
            for (int i = oldsize; i < S.size(); i++) {
                int start = i - input.size() + 1;
                if (start < 0) continue;
                string sub = S.substr(start, input.size());
                if (sub == input && ans2 == -1) ans2 = start;
            }
            move1 += 1, move2 += 1;
            idx1 = (idx1 + move1) % int(S.size());
            idx2 = (idx2 + move2) % int(S.size());
        }
        ans1 = S.substr(after, 10);
        printf("%s\n", ans1.c_str());
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}