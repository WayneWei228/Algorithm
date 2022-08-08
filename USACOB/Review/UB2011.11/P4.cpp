#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[100];

// BFS 的种子可以是多个
// 用此方法试一下

struct Node {
    int x, y;
};

int DX[4] {0, 1, 0, -1}, DY[4] {1, 0, -1, 0};

struct Solution {
    int N, M;
    vector<string> A;
    vector<vector<bool>> Visited;

    void Solve() {
        scanf("%d%d", &N, &M);
        A.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%s", Buffer);
            string s = Buffer;
            A[i] = s;
        }
        int argx = -1, argy = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i][j] == 'X') {
                    argx = i;
                    argy = j;
                }
            }
        }
        
        Visited.resize(N);
        for (auto& i : Visited) i.resize(M);
        Visited[argx][argy] = true;
        vector<vector<Node>> nodes (N + M);
        nodes[0].emplace_back(Node{argx, argy});

        // vector<vector<Node>> 代替优先队列
        // 代价小时（总distance小）可用

        for (int i = 0; i < N; i++) {
            while (!nodes[i].empty()) {
                auto front = nodes[i].back();
                nodes[i].pop_back();
                if (i != 0 && A[front.x][front.y] == 'X') {
                    printf("%d\n", i);
                    return;
                }
                for (int j = 0; j < 4; j++) {
                    int xnew = front.x + DX[j];
                    if (xnew < 0 || xnew >= N) continue;
                    int ynew = front.y + DY[j];
                    if (ynew < 0 || ynew >= N) continue;
                    if (Visited[xnew][ynew]) continue;
                    Visited[xnew][ynew] = true;
                    int cost = A[xnew][ynew] == 'X' ? 0 : 1;
                    nodes[i + cost].emplace_back(Node{xnew, ynew});
                }
            }
        } 
    }
};

int main() {
    Solution().Solve();
    return 0;
}