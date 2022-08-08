#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];

struct CharCount {
    char C;
    int Count;
};

struct Solution {
    string LookNSay(const string& input) {
        vector<CharCount> C;
        for (int i = 0; i < input.size(); ++i) {
            if (i == 0 || input[i] != input[i - 1]) {
                C.push_back(CharCount{input[i], 1});
            } else {
                ++C.back().Count;
            }
        }
        string answer;
        for (int i = 0; i < C.size(); ++i) {
            answer += to_string(C[i].Count);
            answer += C[i].C;
        }
        return answer;
    }

    void Solve() {
        scanf("%s", Buffer);
        string s = Buffer;
        for (int i = 0; i < 40; ++i) s = LookNSay(s);
        printf("%d\n", int(s.size()));
        for (int i = 40; i < 50; ++i) s = LookNSay(s);
        printf("%d\n", int(s.size()));
    }
};

int main() {
    Solution().Solve();
    return 0;
}