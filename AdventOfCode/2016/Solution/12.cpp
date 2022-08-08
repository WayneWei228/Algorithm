#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer0[80], Buffer1[80];

struct Solution {
    vector<string> Input;

    int Run(int c) {
        int r[4]{0, 0, c, 0}, counter = 0;
        auto get = [&](const char* s) {
            return isalpha(s[0]) ? r[s[0] - 'a']
                                 : strtol(s, nullptr, 10);
        };
        while (counter < Input.size()) {
            if (sscanf(Input[counter].c_str(), "cpy %s %s",  //
                       Buffer0, Buffer1) == 2) {
                r[Buffer1[0] - 'a'] = get(Buffer0);
                ++counter;
            }
            if (sscanf(Input[counter].c_str(), "inc %s",  //
                       Buffer0) == 1) {
                ++r[Buffer0[0] - 'a'];
                ++counter;
            }
            if (sscanf(Input[counter].c_str(), "dec %s",  //
                       Buffer0) == 1) {
                --r[Buffer0[0] - 'a'];
                ++counter;
            }
            int delta;
            if (sscanf(Input[counter].c_str(), "jnz %s %d",  //
                       Buffer0, &delta) == 2) {
                if (get(Buffer0) == 0) delta = 1;
                counter += delta;
            }
        }
        return r[0];
    }

    void Solve() {
        while (scanf("%[^\n]\n", Buffer0) == 1) {
            Input.emplace_back(Buffer0);
        }
        printf("%d\n", Run(0));
        printf("%d\n", Run(1));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
