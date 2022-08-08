
#include <cstdio>
#include <string>
using namespace std;

char Buffer[110];

struct Solution {
    string S;

    string Next(const string& s, int n) {
        string answer(s);
        for (int i = 0; i < answer.size(); ++i) {
            int a0 = (i == answer.size() - 1) ? 0 : s[i + 1] == '^';
            int a1 = s[i] == '^';
            int a2 = (i == 0) ? 0 : s[i - 1] == '^';
            int a = (a2 << 2) + (a1 << 1) + a0;
            answer[i] = (n >> a) & 1 ? '^' : '.';
        }
        return answer;
    }

    int Compute(int n) {
        string current(S);
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (char j : current) {
                if (j == '.') ++answer;
            }
            current = Next(current, 90);
        }
        return answer;
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        printf("%d\n", Compute(40));
        printf("%d\n", Compute(400000));
    }
};

int main() {
    Solution().Solve();
    return 0;
}