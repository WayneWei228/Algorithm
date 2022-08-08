#include <cstdio>
#include <string>
using namespace std;

char Buffer[80000];

struct Solution {
    int N;
    string input;
    bool ans = false;

    void Permutate(int no) {
        if (no == N) {

            if (Compute(input)) {
                ans = true;
            }
            return;
        }
        if (input[no] != '?') {
            return Permutate(no + 1);
        }
        input[no] = '0';
        Permutate(no + 1);
        input[no] = '1';
        Permutate(no + 1);
        input[no] = '?';
        return;
    }

    bool isPalindrome (const string& s) {
        int mid = int(s.size()) / 2;
        for (int i = 0; i < mid; i++) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }

    bool Compute(const string& s) {
        for (int j = 5; j <= s.size(); j++) {
            for (int i = 0; i + j <= s.size(); i++) {
                string temp = s.substr(i, j);
                if (isPalindrome(temp)) return false;
            }
        }
        return true;
    }

    void Solve(int caseNo) {
        scanf("%d", &N);
        scanf("%s", Buffer);
        input = Buffer;
        Permutate(0);
        printf("Case #%d: %s\n", caseNo, ans ?  "POSSIBLE" : "IMPOSSIBLE");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 