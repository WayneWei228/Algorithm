#include <string>
#include <vector>
using namespace std;

// LongestPalindromicSubstring

struct Solution {
    string s = "forgeeksskeegfor";
    vector<vector<bool>> dp;
    int start = 0;
    int maxLen = 1;

    void Solve() {
        dp.resize(s.size());
        for (auto& i : dp) {
            i.resize(s.size());
        }

        for (int i = 0; i < dp.size(); i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                maxLen = 2;
                start = i;
            }
        }
        // k is the len of substring
        for (int k = 3; k <= s.size(); k++) {
            // i: start pos
            for (int i = 0; i < s.size() - k + 1; i++) {
                // j : end pos
                int j = i + k - 1;
                // dp[i + 1][j - 1]: whether inner part is palindromic string
                // s[i] s[j] : check two end points are same 
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (k > maxLen) {
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }

        printf("%s\n", s.substr(start, maxLen).c_str());

    }
};

int main() {
    Solution().Solve();
    return 0;
}