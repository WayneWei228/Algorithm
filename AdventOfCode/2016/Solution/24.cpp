#include <cstdio>
#include <limits>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

char Buffer[200];

struct Coordinate {
    int X, Y;
};

struct Node {
    Coordinate C;
    int Distance;

    vector<Node> Children(int xSize, int ySize) {
        vector<Node> answer;
        auto add = [&](int x, int y) {
            if (x < 0 || xSize <= x) return;
            if (y < 0 || ySize <= y) return;
            answer.emplace_back(Node{Coordinate{x, y}, Distance + 1});
        };
        add(C.X + 1, C.Y);
        add(C.X, C.Y + 1);
        add(C.X - 1, C.Y);
        add(C.X, C.Y - 1);
        return answer;
    }
};

struct Solution {
    vector<string> Board;
    Coordinate Mark[10];
    int Distance[10][10], XSize, YSize;
    int Answer1 = numeric_limits<int>::max();
    int Answer2 = numeric_limits<int>::max();
    vector<int> P;

    void ComputeDistance() {
        for (int i = 0; i < 10; ++i) Mark[i].X = -1;
        for (int i = 0; i < XSize; ++i) {
            for (int j = 0; j < YSize; ++j) {
                if (isdigit(Board[i][j])) {
                    auto& mark = Mark[Board[i][j] - '0'];
                    mark.X = i;
                    mark.Y = j;
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            if (Mark[i].X == -1) continue;
            queue<Node> nodes;
            vector<vector<bool>> visited;
            visited.resize(XSize);
            for (int i = 0; i < XSize; ++i) visited[i].resize(YSize);
            Node initial{Mark[i], 0};
            visited[initial.C.X][initial.C.Y] = true;
            nodes.emplace(move(initial));
            while (!nodes.empty()) {
                auto front = nodes.front();
                nodes.pop();
                if (isdigit(Board[front.C.X][front.C.Y])) {
                    int index = Board[front.C.X][front.C.Y] - '0';
                    Distance[i][index] = front.Distance;
                }
                for (auto& j : front.Children(XSize, YSize)) {
                    if (Board[j.C.X][j.C.Y] == '#') continue;
                    if (visited[j.C.X][j.C.Y]) continue;
                    visited[j.C.X][j.C.Y] = true;
                    nodes.emplace(move(j));
                }
            }
        }
    }

    void Put(int no, int current) {
        if (no == P.size()) {
            if (current < Answer1) Answer1 = current;
            current += Distance[P.back()][P[0]];
            if (current < Answer2) Answer2 = current;
            return;
        }
        for (int i = no; i < P.size(); ++i) {
            swap(P[no], P[i]);
            Put(no + 1, current + Distance[P[no - 1]][P[no]]);
            swap(P[no], P[i]);
        }
    }

    void Solve() {
        while (scanf("%s", Buffer) == 1) Board.emplace_back(Buffer);
        XSize = Board.size();
        YSize = Board[0].size();
        ComputeDistance();
        for (int i = 0; i < 10; ++i) {
            if (Mark[i].X != -1) P.emplace_back(i);
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << Distance[i][j] << " ";
            }
            cout << endl;
        }

        Put(1, 0);
        printf("%d\n", Answer1);
        printf("%d\n", Answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
