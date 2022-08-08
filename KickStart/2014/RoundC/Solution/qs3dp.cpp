#include <cstdio>
#include <limits>
#include <string>
#include <vector>
using namespace std;

struct Solution {
    int X;
    vector<bool> Available;

    void Solve(int caseNo) {
        Available.resize(10);
        for (int i = 0; i < 10; ++i) {
            int b;
            scanf("%d", &b);
            Available[i] = b;
        }
        scanf("%d", &X);
        if (X == 1) {
            if (Available[1]) {
                printf("Case #%d: 2\n", caseNo);
            } else {
                printf("Case #%d: Impossible\n", caseNo);
            }
        } else {
            printf("Case #%d: %s\n", caseNo, DP().c_str());
        }
    }

    string DP() {
        vector<int> distance(X + 1, numeric_limits<int>::max());
        distance[1] = 0;
        for (int i = 1; i <= X; ++i) {
            if (distance[i] == numeric_limits<int>::max()) continue;
            for (int j = 2;; ++j) {
                int to = i * j;
                if (X < to) break; // over X, break
                string s = to_string(j);
                if (HasBroken(s)) continue; 
                int cost = s.size() + 1; // * 2 * 4 * 6 == 2 * 4 * 6 =
                int newDistance = distance[i] + cost;
                if (newDistance < distance[to]) {
                    distance[to] = newDistance;
                }
            }
        }
        if (distance[X] == numeric_limits<int>::max()) {
            return "Impossible";
        }
        return to_string(distance[X]);
    }

    bool HasBroken(const string& s) {
        for (int i = 0; i < s.size(); ++i) {
            if (!Available[s[i] - '0']) return true;
        }
        return false;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}