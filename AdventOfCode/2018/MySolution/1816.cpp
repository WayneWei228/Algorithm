#include <cstdio>
#include <functional>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Before: [3, 2, 3, 1]
14 2 1 3
After:  [3, 2, 3, 2]
*/
typedef unordered_map<int, unordered_set<int>> Map;

struct Memory {
    vector<int> R{0, 0, 0, 0};
};

struct Solution {
    vector<function<void(Memory&, int, int, int)>> V;

    void Initialize() {
        V.resize(16);
        // addr
        V[0] = [=](Memory& m, int a, int b, int c) {
            m.R[c] = m.R[a] + m.R[b];
        };
        // addi
        V[1] = [=](Memory& m, int a, int b, int c) {
            m.R[c] = m.R[a] + b;
        };
        // mulr
        V[2] = [=](Memory& m, int a, int b, int c) {
            m.R[c] = m.R[a] * m.R[b];
        };
        // muli
        V[3] = [=](Memory& m, int a, int b, int c) {
            m.R[c] = m.R[a] * b;
        };
        // banr
        V[4] = [=](Memory& m, int a, int b, int c) {
            m.R[c] = m.R[a] & m.R[b];
        };
        // bani
        V[5] = [=](Memory& m, int a, int b, int c) {
            m.R[c] = m.R[a] & b;
        };
        // borr
        V[6] = [=](Memory& m, int a, int b, int c) {
            m.R[c] = m.R[a] | m.R[b];
        };
        // bori
        V[7] = [=](Memory& m, int a, int b, int c) {
            m.R[c] = m.R[a] | b;
        };
        // setr
        V[8] = [=](Memory& m, int a, int b, int c) { m.R[c] = m.R[a]; };
        // seti
        V[9] = [=](Memory& m, int a, int b, int c) { m.R[c] = a; };
        // gtir
        V[10] = [=](Memory& m, int a, int b, int c) {
            (a > m.R[b]) ? m.R[c] = 1 : m.R[c] = 0;
        };
        // gtri
        V[11] = [=](Memory& m, int a, int b, int c) {
            (m.R[a] > b) ? m.R[c] = 1 : m.R[c] = 0;
        };
        // gtrr
        V[12] = [=](Memory& m, int a, int b, int c) {
            (m.R[a] > m.R[b]) ? m.R[c] = 1 : m.R[c] = 0;
        };
        // eqir
        V[13] = [=](Memory& m, int a, int b, int c) {
            (a == m.R[b]) ? m.R[c] = 1 : m.R[c] = 0;
        };
        // eqri
        V[14] = [=](Memory& m, int a, int b, int c) {
            (m.R[a] == b) ? m.R[c] = 1 : m.R[c] = 0;
        };
        // eqrr
        V[15] = [=](Memory& m, int a, int b, int c) {
            (m.R[a] == m.R[b]) ? m.R[c] = 1 : m.R[c] = 0;
        };
    }

    bool Same(const Memory& a, const Memory& b) {
        for (int i = 0; i < 4; i++) {
            if (a.R[i] != b.R[i]) return false;
        }
        return true;
    }

    void Solve() {
        Initialize();
        Map reflection;
        int total = 0;
        while (true) {
            Memory m, n;
            if (scanf("Before: [%d, %d, %d, %d] ", &m.R[0], &m.R[1],
                      &m.R[2], &m.R[3]) < 4)
                break;
            int z, a, b, c;
            scanf("%d %d %d %d ", &z, &a, &b, &c);
            scanf("After: [%d, %d, %d, %d] ", &n.R[0], &n.R[1], &n.R[2],
                  &n.R[3]);
            int cnt = 0;
            bool flag = false;
            for (int i = 0; i < 16; i++) {
                Memory mm = m;
                V[i](mm, a, b, c);
                if (Same(move(mm), n)) {
                    cnt++;
                    reflection[z].emplace(i);
                }
                if (cnt >= 3) {
                    flag = true;
                }
            }
            if (flag) total++;
        }
        printf("%d\n", total);

        queue<int> Erase;
        for (int i = 0; i < 16; i++) {
            if (reflection[i].size() == 1) {
                Erase.emplace(*reflection[i].begin());
            }
        }
        while (!Erase.empty()) {
            auto front = Erase.front();
            Erase.pop();
            for (int i = 0; i < 16; i++) {
                if (reflection[i].size() > 1) {
                    reflection[i].erase(front);
                    if (reflection[i].size() == 1) {
                        Erase.emplace(*reflection[i].begin());
                    }
                }
            }
        }
        Memory question2;
        while (true) {
            int z, a, b, c;
            if (scanf("%d %d %d %d ", &z, &a, &b, &c) < 4) break;
            V[*reflection[z].begin()](question2, a, b, c);
        }
        printf("%d\n", question2.R[0]);
    }
};

int main() {
    Solution().Solve();
    return 0;
}