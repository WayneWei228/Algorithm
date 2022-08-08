#include <cstdio>
#include <cstdlib>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef unsigned long long uint64;

int BitCount(int x) {
    int answer = 0;
    for (int i = 0; i < 32; ++i) {
        answer += x & 1;
        x >>= 1;
    }
    return answer;
}

struct Node {
    int X, Y, Distance, F;

    bool operator<(const Node& that) const { return that.F < F; }
    bool Finish() const { return X == 31 && Y == 39; }
    uint64 H() const { return (uint64(X) << 32) + Y; }

    Node& ComputeF() {
        F = Distance + abs(X - 31) + abs(Y - 39);
        return *this;
    }

    vector<Node> Children() const {
        return {Node{X + 1, Y, Distance + 1}.ComputeF(),
                Node{X, Y + 1, Distance + 1}.ComputeF(),
                Node{X - 1, Y, Distance + 1}.ComputeF(),
                Node{X, Y - 1, Distance + 1}.ComputeF()};
    }
};

struct Solution {
    int C;

    bool IsBlocked(int x, int y) {
        if (x < 0 || y < 0) return true;
        int number = x * x + 3 * x + 2 * x * y + y + y * y + C;
        return BitCount(number) & 1;
    }

    int Compute1() {
        priority_queue<Node> queue;
        unordered_map<uint64, int> visited;
        Node initial{1, 1, 0};
        visited.emplace(initial.H(), initial.ComputeF().F);
        queue.emplace(move(initial));
        while (true) {
            auto top = queue.top();
            queue.pop();
            if (visited[top.H()] < top.F) continue;
            if (top.Finish()) return top.Distance;
            for (auto& i : top.Children()) {
                if (IsBlocked(i.X, i.Y)) continue;
                uint64 h = i.H();
                auto it = visited.find(h);
                if (it != visited.end() && it->second <= i.F) continue;
                visited[h] = i.F;
                queue.emplace(move(i));
            }
        }
    }

    int Compute2() {
        queue<Node> queue;
        unordered_set<uint64> visited;
        Node initial{1, 1, 0};
        visited.emplace(initial.H());
        queue.emplace(move(initial));
        while (true) {
            auto front = queue.front();
            if (50 <= front.Distance) return visited.size();
            queue.pop();
            for (auto& i : front.Children()) {
                if (IsBlocked(i.X, i.Y) || visited.count(i.H())) {
                    continue;
                }
                visited.emplace(i.H());
                queue.emplace(move(i));
            }
        }
    }

    void Solve() {
        scanf("%d", &C);
        printf("%d\n", Compute1());
        printf("%d\n", Compute2());
    }
};

int main() {
    Solution().Solve();
    return 0;
}