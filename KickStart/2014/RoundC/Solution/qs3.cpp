#include <cstdio>
#include <functional>
#include <limits>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int No, Distance;

    bool operator<(const Node& that) const {
        return that.Distance < Distance;
    }
};

struct Solution {
    int X;
    vector<bool> Available;
    
    /*
    总边数：
    1 -> 10^6 * 1
    2 -> 10^6 * 1/2
    3 -> 10^6 * 1/3
    自然数倒数和是 log n
    total = 10^6 * (1 + 1/2 + 1/3 + 1/n) n <= 10^6
          = 10^6 * ln n
          = 10^6 * ln 10^6
    */
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
            printf("Case #%d: %s\n", caseNo, Dijkstra().c_str());
        }
    }
 
    string Dijkstra() {
        priority_queue<Node> nodes;
        vector<int> distance(X + 1, numeric_limits<int>::max());
        distance[X] = 0;
        nodes.emplace(Node{X, 0});
        while (!nodes.empty()) {
            Node top = nodes.top();
            nodes.pop();
            if (distance[top.No] < top.Distance) continue;
            if (top.No == 1) return to_string(top.Distance);
            ForDivisors(top.No, [&](int x) {
                string s = to_string(x);
                if (HasBroken(s)) return;
                int target = top.No / x;
                int cost = s.size() + 1;
                int newDistance = top.Distance + cost;
                if (newDistance < distance[target]) {
                    distance[target] = newDistance;
                    nodes.emplace(Node{target, newDistance});
                }
            });
        }
        return "Impossible";
    }

    void ForDivisors(int no, function<void(int)> f) {
        int i = 1;
        while (i <= no / i) {
            if (no % i == 0) {
                f(i);
                if (i < no / i) f(no / i);
            }
            ++i;
        }
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