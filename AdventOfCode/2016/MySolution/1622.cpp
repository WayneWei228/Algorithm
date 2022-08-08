#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];
/*
root@ebhq-gridcenter# df -h
Filesystem              Size  Used  Avail  Use%
/dev/grid/node-x0-y0     88T   67T    21T   76%
/dev/grid/node-x0-y1     85T   73T    12T   85%
*/

int Next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Node {
    int X, Y;
    int Size, Used, Avail, Use;

    Node(const string& input) {
        const char* format = "/dev/grid/node-x%d-y%d %dT %dT %dT %d%";
        sscanf(input.c_str(), format, &X, &Y, &Size, &Used, &Avail,
               &Use);
    }
};

struct Solution {
    vector<Node> nodes;
    int xSize = 0, ySize = 0;

    char Get(const Node& input) {
        if (input.Used > 100) return '#';
        if (input.X == 0 && input.Y == 0) return 'g';
        if (input.X == xSize - 1 && input.Y == 0) return 'G';
        if (input.Used == 0) return '_';
        return '.';
    }

    int Distance(int from_x, int from_y, int to_x, int to_y) {
        return abs(from_x - to_x) + abs(from_y - to_y);
    }

    void Solve() {
        for (int i = 0; i < 2; ++i) {
            scanf("%*[^\n]\n");
        }
        while (scanf("%[^\n]\n", Buffer) == 1) {
            nodes.emplace_back(Buffer);
        }
        int ans1 = 0;
        for (int i = 0; i < nodes.size(); ++i) {
            for (int j = 0; j < nodes.size(); ++j) {
                if (i == j) continue;
                if (nodes[i].Used != 0 &&
                    nodes[i].Used <= nodes[j].Avail) {
                    ++ans1;
                }
            }
        }
        printf("%d\n", ans1);

        for (auto i : nodes) {
            if (i.X > xSize) xSize = i.X;
            if (i.Y > ySize) ySize = i.Y;
        }
        ++xSize, ++ySize;
        vector<string> map(ySize);
        for (int i = 0; i < map.size(); i++) {
            map[i].resize(xSize, '0');
        }

        for (auto i : nodes) map[i.Y][i.X] = Get(i);

        printf("%s\n", "print the map:");
        for (auto i : map) {
            for (auto j : i) {
                cout << j;
            }
            cout << endl;
        }
        int moveToG = Distance(30, 16, 28, 4) + Distance(28, 4, 1, 33);
        int moveTog = Distance(1, 1, 1, 32) * 5;
        int moveTotal = moveToG + moveTog;
        printf("%d\n", moveTotal);
    }
};

int main() {
    Solution().Solve();
    return 0;
}