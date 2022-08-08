#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[105];
/*
current character < next differenct character:
double
current character > next differenct character:
must not double
no next different characters:
must not double
*/
struct Solution {
    string input;
    string ans = "";
    vector<pair<char, int>> v;
    void Solve(int caseNo) {
        scanf("%s", Buffer);
        input = Buffer;
        for (int i = 0; i < input.size(); i++) {
            // i == 0 要写在前面
            if (i == 0 || input[i] != v.back().first) {
                v.emplace_back(input[i], 1);
            } else {
                v.back().second++;
            }
        }
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i].first < v[i + 1].first) {
                ans += string(v[i].second * 2, v[i].first);
            } else {
                ans += string(v[i].second, v[i].first);
            }
        }
        ans += string(v.back().second, v.back().first);
        printf("Case #%d: %s\n", caseNo, ans.c_str());
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}