#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    vector<vector<int>> Out;
    vector<bool> Visited;

    void AddEdge(int v0, int v1) {
        if (Out.size() <= v0) Out.resize(v0 + 1);
        Out[v0].emplace_back(v1);
    }

    void Visit(int no) {
        Visited[no] = true;
        for (int i : Out[no]) {
            if (!Visited[i]) Visit(i);
        }
    }

    void Solve() {
        while (true) {
            int v0, v1;
            if (scanf("%d <-> ", &v0) < 1) break;
            while (true) {
                char c;
                scanf("%d%c", &v1, &c);
                AddEdge(v0, v1);
                AddEdge(v1, v0);
                if (c != ',') break;
            }
        }
        Visited.resize(Out.size());
        int answer1 = 0, answer2 = 0;
        for (int i = 0; i < Out.size(); ++i) {
            if (!Visited[i]) {
                Visit(i);
                ++answer2;
            }
            if (i == 0) {
                for (bool j : Visited) answer1 += j;
            }
        }
        printf("%d\n%d\n", answer1, answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}