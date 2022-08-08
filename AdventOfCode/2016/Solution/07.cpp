#include <cstdio>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

char Buffer0[80], Buffer1[80];

struct Solution {
    vector<string> S0, S1;

    bool HasABBA(const string& s) {
        for (int i = 0; i < int(s.size()) - 3; ++i) {
            if (s[i] != s[i + 1] && s[i] == s[i + 3] &&
                s[i + 1] == s[i + 2]) {
                return true;
            }
        }
        return false;
    }

    bool HaveABBA(const vector<string>& v) {
        for (const auto& i : v) {
            if (HasABBA(i)) return true;
        }
        return false;
    }

    vector<pair<char, char>> ABA(const string& s) {
        vector<pair<char, char>> answer;
        for (int i = 0; i < int(s.size()) - 2; ++i) {
            if (s[i] != s[i + 1] && s[i] == s[i + 2]) {
                answer.emplace_back(s[i], s[i + 1]);
            }
        }
        return answer;
    }

    bool HasReverse(const set<pair<char, char>>& s0,
                    const set<pair<char, char>>& s1) {
        for (const auto& i : s0) {
            if (s1.count(make_pair(i.second, i.first))) return true;
        }
        return false;
    }

    bool Read() {
        S0.clear(); // outside
        S1.clear(); // inside
        while (true) {
            if (scanf(" %[^[\n]", Buffer0) < 1) break;
            S0.emplace_back(Buffer0);
            int nchars = 0;
            scanf("[%n", &nchars); // 把 [ 读掉同时判断是否为末尾
            if (nchars == 0) break;
            scanf("%[^]]]", Buffer1);
            S1.emplace_back(Buffer1);
        }
        return !S0.empty() || !S1.empty();
    }

    void Solve() {
        int answer1 = 0, answer2 = 0;
        while (Read()) {
            if (!HaveABBA(S1) && HaveABBA(S0)) ++answer1;
            set<pair<char, char>> v0, v1;
            for (const auto& i : S0) {
                for (auto& j : ABA(i)) v0.insert(move(j));
            }
            for (const auto& i : S1) {
                for (auto& j : ABA(i)) v1.insert(move(j));
            }
            if (HasReverse(v0, v1)) ++answer2;
        }
        printf("%d\n", answer1);
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
