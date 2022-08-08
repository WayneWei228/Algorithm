#include <cstdio>
#include <string>
using namespace std;

char Buffer[80];

struct Solution {
    string S;
    int RSize;

    bool isSafe(int no) {
        if (no % RSize == 0) {
            if (S[no - RSize] == '.' && S[no - RSize + 1] == '^' ||
                S[no - RSize] == '^' && S[no - RSize + 1] == '^') {
                return false;
            }
            return true;
        }
        if ((no - RSize + 1) % RSize == 0) {
            if (S[no - RSize] == '.' && S[no - RSize - 1] == '^' ||
                S[no - RSize] == '^' && S[no - RSize - 1] == '^') {
                return false;
            }
            return true;
        }
        if (S[no - RSize] == S[no - RSize - 1] &&
                S[no - RSize] != S[no - RSize + 1] ||
            S[no - RSize] == S[no - RSize + 1] &&
                S[no - RSize] != S[no - RSize - 1]) {
            return false;
        }
        return true;
    }

    int Compute1(int lenRow) {
        int cnt = 0;
        for (int i = 0; i < RSize; ++i) {
            if (S[i] == '.') {
                cnt++;
            }
        }
        for (int i = RSize; i < lenRow * RSize; ++i) {
            if (isSafe(i)) {
                S += '.';
                cnt++;
            } else {
                S += '^';
            }
        }
        return cnt;
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        RSize = int(S.size());
        printf("%d\n", Compute1(40));
        S = Buffer;
        printf("%d\n", Compute1(400000));
    }
};

int main() {
    Solution().Solve();
    return 0;
}