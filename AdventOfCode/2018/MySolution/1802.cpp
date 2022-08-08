#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[80];

typedef long long int64;

struct Solution {
    int64 two = 0, three = 0;
    vector<string> input;
    string ans2;
    void Solve() {
        while (scanf("%s", Buffer) == 1) {
            string s = Buffer;
            input.emplace_back(s);
            unordered_map<char, int> M;
            for (auto i : s) {
                auto it = M.find(i);
                if (it != M.end()) {
                    it->second++;
                } else {
                    M.emplace(i, 1);
                }
            }
            bool flag_two = true, flag_three = true;
            for (auto& j : M) {
                if (j.second == 2 && flag_two) {
                    two++;
                    flag_two = false;
                }
                if (j.second == 3 && flag_three) {
                    three++;
                    flag_three = false;
                }
            }
        }
        printf("%lld\n", two * three);

        for (int i = 0; i < int(input.size()); i++) {
            for (int j = i + 1; j < int(input.size()); j++) {
                int cnt = 0;
                for (int k = 0; k < int(input[0].size()); k++) {
                    if (input[i][k] != input[j][k]) cnt++;
                    if (cnt > 1) break;
                }
                if (cnt <= 1) {
                    string s = "";
                    for (int k = 0; k < int(input[0].size()); k++) {
                        if (input[i][k] == input[j][k]) s += input[i][k];
                    }
                    ans2 = s;
                    goto Label;
                }
            }
        }
        Label: 
            printf("%s\n", ans2.c_str());        
    }
};

int main() {
    Solution().Solve();
    return 0;
}