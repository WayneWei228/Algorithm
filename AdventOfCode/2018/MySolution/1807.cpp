#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

char Buffer[80], Buffer1[80];
// Step C must be finished before step A can begin.
// Step C must be finished before step F can begin.

struct letter {
    char c;
    int value;

    letter(const char& a, int n) {
        c = a;
        value = a - 'A' + 61 + n;
    }

    bool operator<(const letter& that) const {
        return that.value < value;
    }
};

struct Solution {
    vector<vector<char>> M;
    vector<vector<char>> M2;
    vector<bool> Visited;
    vector<bool> Visited2;
    string ans1 = "";
    int ans2 = 0;
    priority_queue<letter> q;

    void Dfs(int no) {
        char a = no + 'A';
        ans1 += a;
        Visited[no] = true;
        for (auto& i : M) {
            for (int j = 0; j < int(i.size()); j++) {
                if (i[j] == a) {
                    i.erase(i.begin() + j);
                    break;
                }
            }
        }
        for (int i = 0; i < Visited.size(); i++) {
            if (!Visited[i] && !int(M[i].size())) {
                Dfs(i);
                break;
            }
        }
    }

    void Dfs2(int no) {
        char a = no + 'A';
        Visited2[no] = true;
        for (auto& i : M2) {
            for (int j = 0; j < int(i.size()); j++) {
                if (i[j] == a) {
                    i.erase(i.begin() + j);
                    break;
                }
            }
        }
        // priority_queue<letter> p(q);
        // while (!p.empty()) {
        //     auto t = p.top();
        //     printf("%c : %d  ", t.c, t.value);
        //     p.pop();
        // }
        // printf("\n");
        if (!q.empty()) {
            ans2 = q.top().value;
            q.pop();
        } else {
            return;
        }
        for (int i = 0; i < Visited2.size(); i++) {
            if (!Visited2[i] && !int(M2[i].size()) &&
                int(q.size()) < 5) {
                q.emplace(letter(i + 'A', ans2));
                Visited2[i] = true;
            }
        }
        Dfs2(q.top().c - 'A');
    }

    void Solve() {
        Visited.resize(26, true);
        M.resize(26);
        char a, b;
        while (
            scanf("Step %c must be finished before step %c can begin. ",
                  &a, &b) == 2) {
            auto& c = M[b - 'A'];
            c.emplace_back(a);
            Visited[b - 'A'] = false;
            Visited[a - 'A'] = false;
        }

        M2 = M;
        Visited2 = Visited;

        // for (int i = 0; i < 26; i++) {
        //     if (!Visited[i]) {
        //         printf("%c : ", i + 'A');
        //         for (auto j : M[i]) {
        //             printf("%c", j);
        //         }
        //         printf("\n");
        //     }
        // }

        for (int i = 0; i < 26; i++) {
            if (!Visited[i] && M[i].size() == 0) {
                Dfs(i);
                break;
            }
        }
        printf("%s\n", ans1.c_str());

        for (int i = 0; i < 26; i++) {
            if (!Visited2[i] && !int(M2[i].size()) && q.size() < 5) {
                q.emplace(letter(i + 'A', 0));
                Visited2[i] = true;
            }
        }
        auto top = q.top();

        Dfs2(top.c - 'A');
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}