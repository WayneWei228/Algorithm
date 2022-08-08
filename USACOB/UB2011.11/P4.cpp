#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[51];

struct Node {
    int X, Y;
};

int DX[4]{1, 0, -1, 0}, DY[4]{0, 1, 0, -1};

struct Solution {
    int N, M;
    vector<string> A;
    vector<vector<bool>> Visited;

    void Solve() {
        scanf("%d%d", &N, &M);
        A.resize(N);
        for (string& i : A) {
            scanf("%s", Buffer);
            i = Buffer;
        }
        int argX = -1, argY = -1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (A[i][j] == 'X') {
                    argX = i;
                    argY = j;
                }
            }
        }
        Visited.resize(N);
        for (auto& i : Visited) i.resize(M);
        vector<vector<Node>> nodes(N + M);
        nodes[0].emplace_back(Node{argX, argY});
        Visited[argX][argY] = true;
        for (int i = 0; i < nodes.size(); ++i) {
            while (!nodes[i].empty()) {
                Node front = nodes[i].back();
                nodes[i].pop_back();
                // i = 0时第二块联通块都加入
                // i > 0 寻找另一个联通块
                if (i != 0 && A[front.X][front.Y] == 'X') {
                    printf("%d\n", i);
                    return;
                }
                for (int j = 0; j < 4; ++j) {
                    int newX = front.X + DX[j];
                    if (newX < 0 || N <= newX) continue;
                    int newY = front.Y + DY[j];
                    if (newY < 0 || M <= newY) continue;
                    if (Visited[newX][newY]) continue;
                    Visited[newX][newY] = true;
                    int cost = A[newX][newY] == 'X' ? 0 : 1;
                    nodes[i + cost].emplace_back(Node{newX, newY});
                }
            }
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}
