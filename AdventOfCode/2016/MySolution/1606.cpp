#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


char Buffer[10];
// lhyrnfkp

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
    if (b.second < a.second) {
        return true;
    } 
    return false;
}

struct Solution {

    vector<vector<pair<char, int>>> Input;  
    string ans1, ans2;

    void Solve() {
        Input.resize(8);
        int i = 0;
        while (true) {
            if (scanf("%s", Buffer) < 1) break;
            string s = Buffer;
            for (int i = 0; i < s.size(); ++i) {
                bool flag = false;
                for (int j = 0; j < Input[i].size(); ++j) {
                    if (s[i] == Input[i][j].first) {
                        Input[i][j].second++;
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    Input[i].emplace_back(pair{s[i], 0});
                }
            }
        }
        
        for (int i = 0; i < Input.size(); ++i) {
            sort(Input[i].begin(), Input[i].end(), cmp);
            ans1 += Input[i][0].first;
            ans2 += Input[i][int(Input[i].size() - 1)].first;
        }
        printf("%s\n", ans1.c_str());
        printf("%s\n", ans2.c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}