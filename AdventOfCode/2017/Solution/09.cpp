#include <cstdio>
#include <string>
using namespace std;

char Buffer[22000];
// {{<a!>},{<a!>},{<a!>},{<ab>}}
struct Solution {
    string S;
    int Position = 0, Depth = 0, Answer1 = 0, Answer2 = 0;

    void ParseGroup() {
        if (S[Position++] != '{') return;
        Answer1 += ++Depth;
        while (true) {
            if (S[Position] == '}') break;
            if (S[Position] == '{') {
                ParseGroup();
            } else {
                ParseGarbage();
            }
            // if (S[Position] == ',') ++Position;
        }
        --Depth;
        if (S[Position++] != '}') return;
    }

    void ParseGarbage() {
        if (S[Position++] != '<') return;
        while (true) {
            if (S[Position] == '>') break;
            if (S[Position] == '!') {
                Position += 2;
            } else {
                ++Answer2;
                ++Position;
            }
        }
        if (S[Position++] != '>') return;
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        ParseGroup();
        printf("%d\n%d\n", Answer1, Answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}