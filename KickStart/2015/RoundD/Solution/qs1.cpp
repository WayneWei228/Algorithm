#include <cstdio>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int DX[4]{1, 0, -1, 0}, DY[4]{0, 1, 0, -1};

char Buffer[101];

struct Node {
    int X, Y;
};

struct Solution {
    int R, C, N;
    vector<string> B;

    void Solve(int caseNo) {
        scanf("%d%d", &R, &C);
        B.resize(R);
        for (string& i : B) {
            scanf("%s", Buffer);
            i = Buffer;
        }
        scanf("%d", &N);
        printf("Case #%d:\n", caseNo);
        for (int i = 0; i < N; ++i) {
            char c;
            scanf(" %c", &c);
            switch (c) {
                case 'Q':
                    printf("%d\n", Query());
                    break;
                case 'M':
                    int x, y, z;
                    scanf("%d%d%d", &x, &y, &z);
                    B[x][y] = '0' + z;
                    break;
            }
        }
    }

    int Query() { // 查询
        int answer = 0;
        vector<vector<bool>> visited(R);
        for (auto& i : visited) i.resize(C);
        queue<Node> nodes;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (visited[i][j] || B[i][j] == '0') continue;
                ++answer;
                visited[i][j] = true;
                nodes.emplace(Node{i, j});
                while (!nodes.empty()) {
                    Node n = nodes.front();
                    nodes.pop();
                    for (int k = 0; k < 4; ++k) {
                        int newX = n.X + DX[k], newY = n.Y + DY[k];
                        if (newX < 0 || R <= newX) continue;
                        if (newY < 0 || C <= newY) continue;
                        if (!visited[newX][newY] &&
                            B[newX][newY] != '0') {
                            visited[newX][newY] = true;
                            nodes.emplace(Node{newX, newY});
                        }
                    }
                }
            }
        }
        return answer;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}