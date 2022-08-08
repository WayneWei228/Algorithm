#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

char Buffer[80];
struct Solution {
    void Solve() {
        int answer1 = 0, answer2 = 0;
        while (true) {
            vector<string> a;
            unordered_set<string> b;
            unordered_set<string> d;
            char c;
            while (true) {
                if (scanf("%s%c", Buffer, &c) < 2) break;
                string s = Buffer;
                a.emplace_back(s);
                b.emplace(s);
                sort(s.begin(), s.end());
                d.emplace(s);
                if (c != ' ') break;
            }
            if (a.empty()) break;
            if (a.size() == b.size()) answer1++;
            if (a.size() == d.size()) answer2++;
        }
        printf("%d\n", answer1);
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}