#include <cstdio>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


char Buffer[80];

struct Solution {
    int N;
    vector<vector<int>> Out;
    unordered_map<string, int> mtn;
    vector<int> Visited;

    int MapToNumber(const string& s) {
        return mtn.emplace(s, mtn.size()).first->second;
    }

    void Solve(int caseNo) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf(" %[^=]=%*[^(](", Buffer);
            int v0 = MapToNumber(Buffer);
            if (v0 >= Out.size()) Out.resize(v0 + 1);
            while (true) {
                scanf(",");
                if (scanf("%[^,)]", Buffer) == 0) break;
                int v1 = MapToNumber(Buffer);
                if (v1 >= Out.size()) Out.resize(v1 + 1);
                Out[v0].emplace_back(v1);
            }
            scanf(")");
        }
        printf("Case #%d: %s\n", caseNo, Topo() ? "GOOD" : "BAD");

    }

    bool Topo() {
        if (Out.size() != N) return false;
        Visited.resize(N);
        for (int i = 0; i < N; i++) {
            if (Visited[i] == 0 && !VisitOK(i)) return false;
        }      
        return true;
    }

    bool VisitOK(int i) {
        Visited[i] = 1;
        for (auto j : Out[i]) {
            if (Visited[j] == 1) return false;
            if (Visited[j] == 0 && !VisitOK(j)) return false;
        }
        Visited[i] = 2;
        return true;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 