#include <cstdio>
#include <string>
using namespace std;


char Buffer[80];

// cqjxjnds
// azzz
struct Solution {

    bool FirstRequire(const string& input) {
        for(int i = 0; i < input.size() - 2; ++i) {
            if(input[i + 1] == input[i] + 1 && input[i + 2] == input[i] + 2) {
                return true;
            }
        }
        return false;
    }

    bool SecondRequire(const string& input) {
        for(int i = 0; i < input.size(); ++i) {
            if(input[i] == 'i' || input[i] == 'o' || input[i] == 'l') {
                return false;
            }
        }
        return true;
    }

    bool ThirdRequire(const string& input) {
        for(int i = 0; i < input.size() - 1; ++i) {
            for(int j = i + 2; j < input.size() - 1; ++j) {
                if(input[i] != input[j] && input[i] == input[i + 1] && input[j] == input[j + 1]) {
                    return true;
                }
            }
        }
        return false;
    }

    string Next (const string& in) {
        string input = in;
        for(int i = input.size() - 1; i >= 0; --i) {
            if(input[i] == 'z') {
                input[i] = 'a';
            } else {
                input[i] += 1;
                break;
            }
        }
        return input;
    }

    void Solve() {
        scanf("%s", Buffer);
        string s = Buffer;
        while (true) {
            if(FirstRequire(s) && SecondRequire(s) && ThirdRequire(s)) {
                break;
            } else {
                s = Next(s);
            }
        }
        printf("%s\n", s.c_str());
    }
};



int main() {
    Solution().Solve();
    return 0;
}