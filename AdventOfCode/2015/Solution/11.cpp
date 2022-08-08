#include <cstdio>
#include <string>
using namespace std;

char Buffer[80];

struct Solution {
    bool HasABC(const string& s) {
        for (int i = 0; i < int(s.size()) - 2; ++i) {
            if (s[i] + 1 == s[i + 1] && s[i + 1] + 1 == s[i + 2]) {
                return true;
            }
        }
        return false;
    }

    bool HasIOL(const string& s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'i' || s[i] == 'o' || s[i] == 'l') {
                return true;
            }
        }
        return false;
    }

    bool HasTwoPairs(const string& s) {
        int pairs = 0;
        for (int i = 0; i < int(s.size()) - 1;) {
            if (s[i] == s[i + 1]) {
                ++pairs;
                i += 2;
            } else {
                ++i;
            }
        }
        return 2 <= pairs;
    }

    bool IsValidPassword(const string& s) {
        return HasABC(s) && !HasIOL(s) && HasTwoPairs(s);
    }

    string Next(const string& s) {
        string answer(s);
        for (int i = answer.size() - 1; i >= 0; --i) {
            if (answer[i] != 'z') {
                ++answer[i];
                break;
            } else {
                answer[i] = 'a';
            }
        }
        return answer;
    }

    string FirstValidAfter(const string& s) {
        string answer(s);
        do {
            answer = Next(answer);
        } while (!IsValidPassword(answer));
        return answer;
    }

    void Solve() {
        scanf("%s", Buffer);
        string s = FirstValidAfter(Buffer);
        printf("%s\n", s.c_str());
        s = FirstValidAfter(s);
        printf("%s\n", s.c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}