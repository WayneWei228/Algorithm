#include <cstdio>
#include <string>
using namespace std;

char Buffer[20000];

typedef long long int64;
// A(1x5)BC
// ABBBBBC

struct Solution {
    string S;

    int64 DecompressLength(int start, int size, bool recursive) {
        int64 answer = 0;
        for (int i = start; i < start + size;) {
            if (S[i] == '(') {
                int length, times, nchars;
                sscanf(S.c_str() + i, "(%dx%d)%n",  //
                       &length, &times, &nchars);
                i += nchars;
                int64 subLength =
                    recursive ? DecompressLength(i, length, true)
                              : length;
                answer += subLength * times;
                i += length;
            } else {
                ++answer;
                ++i;
            }
        }
        return answer;
    }

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        printf("%lld\n", DecompressLength(0, S.size(), false));
        printf("%lld\n", DecompressLength(0, S.size(), true));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
