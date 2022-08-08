#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

char Buffer0[150], Buffer1[150];

struct Solution {
    int n;
    unordered_map<string, int> m;
    vector<vector<int>> V;
    unordered_set<int> store[2];

    int MaptoNum(const string& s) {
        auto res = m.emplace(s, int(m.size()));
        return res.first->second;
    }

    bool canPut(int n, int id) {
        if (store[id].find(n) != store[id].end()) return false;
        for (auto i : V[n]) {
            store[id].emplace(i);
        }
        return true;
    }
    // 1-2 2-3 3-4
    // 1 4 只能异侧
    // 1 4 2 3 
    // A 1 4
    // B
    bool Put(int n) {
        if (canPut(n, 0)) return true;
        if (canPut(n, 1)) return true;
        return false;
    }
    void Solve(int caseNo) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            string l, r;
            scanf("%s %s", Buffer0, Buffer1);
            l = Buffer0, r = Buffer1;
            int a = MaptoNum(l);
            int b = MaptoNum(r);
            if (a >= V.size()) V.resize(a + 1);
            V[a].emplace_back(b);
            if (b >= V.size()) V.resize(b + 1);
            V[b].emplace_back(a);
        }
        bool can = true;
        for (int i = 0; i < m.size(); i++) {
            if (!Put(i)) can = false;
        }
        printf("Case #%d: ", caseNo);
        if (can) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}