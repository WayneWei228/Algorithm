#include <algorithm>
#include <cstdio>
#include <limits>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int Next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) { // 给一个uint64 得到一个uint64, 越乱越好, 对于同一个uint64, 必须得到同一个解, 不同的尽量得到不同的解 要求看到结果尽量猜不出原来的数
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct Coordinate {
    int x, y;

    bool operator==(const Coordinate& that) const {
        return x == that.x && y == that.y;
    }
};

struct CoordinateHash {
    
    size_t operator()(const Coordinate& c) const { 
        return Fingerprint(c.x) + c.y;
    }
};

typedef unordered_map<Coordinate, int, CoordinateHash> CoordinateMap;

struct Solution {
    string s;
    int n, m;
    int sx, sy, ex, ey;
    vector<vector<int>> V;

    int Travel() {
        CoordinateMap q;
        vector<vector<bool>> Visited;
        Visited.resize(V.size());
        for (auto& i : Visited) i.resize(V[0].size());
        Visited[sx][sy] = true;

        q.emplace(Coordinate{sx, sy},V[sx][sy]);
        int ans = -1;

        while (!q.empty()) {
            CoordinateMap qNew;
            for (auto& front : q) {
                for (int i = 0; i < 4; i++) {
                    int xnew = front.first.x + Next[i][0];
                    if (xnew < 0 || xnew >= n) continue;
                    int ynew = front.first.y + Next[i][1];
                    if (ynew < 0 || ynew >= m) continue;
                    // qNew 没去重
                    if (!Visited[xnew][ynew] && V[xnew][ynew] != -1) {
                        auto& t = qNew[Coordinate{xnew, ynew}];
                        t = max(t, front.second + V[xnew][ynew]); 
                    }
                }
                if (front.first.x == ex && front.first.y == ey) {
                    if (front.second > ans) {
                        ans = front.second;
                    }
                }
            }
            for (const auto& i : qNew) {
                Visited[i.first.x][i.first.y] = true;
            }
            if (ans != -1) return ans;
            q = move(qNew);
        }
        return -1;
    }

    void Solve(int caseNo) {
        scanf("%d %d", &n, &m);
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        V.resize(n);
        for (auto& i : V) i.resize(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &V[i][j]);
            }
        }

        int ans = Travel();
        if (ans == -1) {
            printf("Case #%d: Mission Impossible.\n", caseNo);
        } else {
            printf("Case #%d: %d\n", caseNo, ans);
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}