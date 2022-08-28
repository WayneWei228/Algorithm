#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/*
a[i] : Ept = aNeed : bNeed;
Ept * aNeed = a[i] * bNeed;
Ept = a[i] * bNeed / aNeed;
P[i] = b[i] - Ept = b[i] - a[i] * bNeed / aNeed;
To make P[i] become integer
P[i] = b[i] * aNeed - a[i] * bNeed;
*/

struct Node {
    int Depth, Current;
};

struct Solution {
    int N, MinP, MaxP;
    vector<int> P;

    void Solve() {
        scanf("%d", &N);
        vector<int> a, b;
        a.resize(N);
        b.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &a[i], &b[i]);
        }
        int aNeed, bNeed;
        scanf("%d%d", &aNeed, &bNeed);
        P.resize(N);
        for (int i = 0; i < N; i++) {
            P[i] = b[i] * aNeed - a[i] * bNeed;
        }
        MinP = *min_element(P.begin(), P.end());
        MaxP = *max_element(P.begin(), P.end());
        printf("%d\n", Compute());
    }

    int Compute() {
        if (MaxP < 0 || 0 < MinP) return -1;
        vector<bool> visited(MaxP - MinP + 1);
        queue<Node> nodes;
        nodes.emplace(Node{0, 0});
        while (!nodes.empty()) {
            Node n = nodes.front();
            nodes.pop();
            for (int i = 0; i < N; i++) {
                if (n.Current + P[i] == 0) return n.Depth + 1;
                int next = n.Current + P[i];
                if (next < MinP || MaxP < next) continue;
                if (visited[next - MinP]) continue;
                visited[next - MinP] = true;
                nodes.emplace(Node{n.Depth + 1, next});
            }
        }
        return -1;
    }
};

int main() {
    Solution().Solve();
    return 0;
}
