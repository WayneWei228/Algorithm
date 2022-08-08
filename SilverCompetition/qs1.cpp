#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long int64;

int N;

struct Node {
    int64 value;
    int64 target;
    int64 step;

    bool operator<(const Node& that) const {
        if (step != that.step) {
            return step > that.step;
        }
        return (abs(value - target)) > (abs(that.value - target));
    }
};

struct Solution {
    int DFS(int64 a, int64 b) {
        priority_queue<Node> q;
        q.emplace(Node{a, b, 0});
        unordered_set<int64> visited;
        visited.emplace(a);
        int ans = 0;
        while (!q.empty()) {
            auto top = q.top();
            q.pop();

            if (top.value == b) {
                ans = top.step;
                break;
            }
            if (visited.find(top.value * 2) == visited.end()) {
                q.emplace(
                    Node{top.value * 2, top.target, top.step + 1});
                visited.emplace(top.value * 2);
            }
            if (top.value % 2 == 0 && visited.find(top.value / 2) == visited.end()) {
                q.emplace(
                    Node{top.value / 2, top.target, top.step + 1});
                visited.emplace(top.value / 2);
            }
            if (visited.find(top.value + 1) == visited.end()) {
                q.emplace(
                    Node{top.value + 1, top.target, top.step + 1});
                visited.emplace(top.value + 1);
            }
        }
        return ans;
    }

    void Solve() {

        cin >> N;
        vector<int64> ans;
        for (int i = 0; i < N; i++) {
            int64 a, b;
            cin >> a >> b;
            ans.emplace_back(DFS(a, b));
        }
        for (const auto& i : ans) {
            printf("%lld\n", i);
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}