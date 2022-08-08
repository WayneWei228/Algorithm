#include <cstdio>
#include <string>
using namespace std;

char Buffer[80];

struct Solution {
    string Input;
    int InputNumber, P0 = 0, P1 = 1;
    string S = "37";

    void Solve() {
        scanf("%s", Buffer);
        Input = Buffer;
        sscanf(Input.c_str(), "%d", &InputNumber);
        int index = -1;
        for (int i = 2;; ++i) {
            if (index != -1 && InputNumber + 10 <= S.size()) break;
            int x = (S[P0] - '0') + (S[P1] - '0');
            int oldSize = S.size();
            S += to_string(x);
            for (int i = oldSize; i < S.size(); ++i) {
                int start = i - Input.size() + 1;
                if (start < 0) continue;
                string sub = S.substr(start, Input.size());
                if (index == -1 && sub == Input) index = start;
            }
            P0 = (P0 + 1 + (S[P0] - '0')) % S.size();
            P1 = (P1 + 1 + (S[P1] - '0')) % S.size();
        }
        printf("%s\n", S.substr(InputNumber, 10).c_str());
        printf("%d\n", index);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
