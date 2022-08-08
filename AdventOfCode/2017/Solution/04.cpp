#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

char Buffer[80];

struct Solution {
    int Answer1 = 0, Answer2 = 0;

    void Solve() {
        while (true) {
            vector<string> v;
            while (true) {
                char c;
                if (scanf("%s%c", Buffer, &c) < 2) break;
                v.emplace_back(Buffer);
                if (c != ' ') break;
            }
            if (v.empty()) break;
            int distinct;
            distinct = unordered_set<string>(v.begin(), v.end()).size();
            if (distinct == v.size()) ++Answer1;
            for (auto& i : v) sort(i.begin(), i.end());
            distinct = unordered_set<string>(v.begin(), v.end()).size();
            if (distinct == v.size()) ++Answer2;
        }
        printf("%d\n", Answer1);
        printf("%d\n", Answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}