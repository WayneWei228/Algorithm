#include <cstdio>
#include <string>
using namespace std;

char Buffer[7001];

struct Solution {
    string S;

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        int answer1 = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                ++answer1;
            } else {
                --answer1;
            }
        }
        printf("%d\n", answer1);
        int answer2 = 0, balance = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                answer2 = i + 1;
                break;
            }
        }
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
