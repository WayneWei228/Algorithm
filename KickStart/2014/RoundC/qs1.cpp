#include <cstdio>
#include <queue>
#include <string>
#include <vector>
using namespace std;

char Buffer[305];

int DX[8]{0, -1, -1, -1, 0, 1, 1, 1}, DY[8]{1, 1, 0, -1, -1, -1, 0, 1};

struct Coordinate {
    int x, y;
};

struct Solution {
    int N;
    vector<string> M;
    vector<vector<bool>> Visited;
    int ans = 0;

    bool IsEmpty(int i, int j) {
        bool flag = true;
        for (int k = 0; k < 8; k++) {
            int xnew = i + DX[k];
            if (xnew < 0 || xnew >= N) continue;
            int ynew = j + DY[k];
            if (ynew < 0 || ynew >= N) continue;
            if (M[xnew][ynew] == '*') flag = false;
        }
        return flag;
    }

    vector<Coordinate> Near(const Coordinate& c) {
        vector<Coordinate> answer;
        for (int k = 0; k < 8; k++) {
            int xnew = c.x + DX[k];
            if (xnew < 0 || xnew >= N) continue;
            int ynew = c.y + DY[k];
            if (ynew < 0 || ynew >= N) continue;
            if (M[xnew][ynew] == '.') answer.emplace_back(Coordinate{xnew, ynew});
        }
        return answer;
    }

    void Explore(int i, int j) {
        queue<Coordinate> q;
        q.emplace(Coordinate{i, j});
        Visited[i][j] = true;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            for (auto c : Near(front)) {
                if (IsEmpty(c.x, c.y) && !Visited[c.x][c.y]) q.emplace(c);
                Visited[c.x][c.y] = true;
            }
        }
    }

    void Solve(int caseNo) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%s", Buffer);
            string s = Buffer;
            M.emplace_back(s);
        }
        Visited.resize(N);
        for (auto& i : Visited) i.resize(N);
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[i].size(); j++) {
                if (M[i][j] == '*') Visited[i][j] = true;
                if (M[i][j] == '.' && IsEmpty(i, j) && !Visited[i][j]) {
                    Explore(i, j);
                    ans++;
                }
            }
        }
        for (auto i : Visited) {
            for (auto j : i) {
                if (!j) {
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", caseNo, ans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}