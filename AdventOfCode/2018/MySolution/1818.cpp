#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[55];

int Next[8][2] = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                  {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

struct Solution {
    vector<string> outskirts;

    string Around(const vector<string>& input, int x, int y) {
        string s;
        for (int i = 0; i < 8; i++) {
            int xnew = x + Next[i][0];
            if (xnew < 0 || xnew >= input.size()) continue;
            int ynew = y + Next[i][1];
            if (ynew < 0 || ynew >= input[0].size()) continue;
            s += input[xnew][ynew];
        }
        return s;
    }
    vector<string> Change(const vector<string>& input) {
        vector<string> out(input);
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[i].size(); j++) {
                string s = Around(input, i, j);
                switch (input[i][j]) {
                    case '.': {
                        int cnt = 0;
                        for (auto k : s) {
                            if (k == '|') cnt++;
                        }
                        if (cnt >= 3) out[i][j] = '|';
                        break;
                    }
                    case '|': {
                        int cnt = 0;
                        for (auto k : s) {
                            if (k == '#') cnt++;
                        }
                        if (cnt >= 3) out[i][j] = '#';
                        break;
                    }
                    case '#': {
                        int cntree = 0, cntyard = 0;
                        for (auto k : s) {
                            if (k == '|') cntree++;
                            if (k == '#') cntyard++;
                        }
                        if (!cntree || !cntyard) out[i][j] = '.';
                        break;
                    }
                }
            }
        }
        return out;
    }

    int CountAns(string s, char c) {
        int cnt = 0;
        for (const auto& i : s) {
            if (i == c) cnt++;
        }
        return cnt;
    }

    void Solve() {
        int ans1 = 0;
        int ans2 = 0;
        unordered_map<string, int> repeat;
        int circle = 0;
        int start = 0;
        while (true) {
            if (scanf("%s", Buffer) < 1) break;
            string s = Buffer;
            outskirts.emplace_back(move(s));
        }
        for (int i = 0; i < 10000; i++) {
            string s;
            for (int i = 0; i < outskirts.size(); i++) {
                s += outskirts[i];
            }
            int total = CountAns(s, '|') * CountAns(s, '#');
            if (i == 10) ans1 = total;
            if (!repeat[s]) {
                repeat[s] = i;
            } else {
                start = repeat[s];
                circle = i - repeat[s]; 
                break;
            }
            outskirts = Change(outskirts);
        }
        int index = start + (1000000000 - start) % circle;
        for (auto i : repeat) {
            if (i.second == index) {
                ans2 = CountAns(i.first, '|') * CountAns(i.first, '#');
                break;
            }
        }
        printf("%d\n", ans1);
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}