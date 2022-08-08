#include <cctype>
#include <cstdio>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[100];
int Next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Coordinate {
    int x, y;

    bool operator==(const Coordinate& that) const {
        return that.x == x && that.y == y;
    }
};

struct Node {
    Coordinate coordinate;
    int Dis;

    vector<Node> Children(int xSize, int ySize) {
        vector<Node> ans;
        for (int i = 0; i < 4; i++) {
            Coordinate next(coordinate);
            next.x += Next[i][0];
            next.y += Next[i][1];
            if (0 <= next.x && next.x < xSize && 0 <= next.y &&
                next.y < ySize) {
                Node ne;
                ne.coordinate = move(next);
                ne.Dis = Dis + 1;
                ans.emplace_back(move(ne));
            }
        }
        return ans;
    }
};

struct Solution {
    vector<int> numbers;
    vector<string> map;
    unordered_map<int, Coordinate> points;
    int numSize;
    vector<vector<int>> store;
    int xSize, ySize;

    int shorest = numeric_limits<int>::max();
    int fullshorest = numeric_limits<int>::max();
    void ComputeDis(int start) {
        queue<Node> queue;
        queue.emplace(Node{points[start], 0});
        vector<vector<bool>> visited;
        visited.resize(xSize);
        for (int i = 0; i < xSize; ++i) visited[i].resize(ySize);
        visited[points[start].x][points[start].y] = true;
        while (!queue.empty()) {
            Node top = queue.front();
            queue.pop();
            for (auto i : points) {
                if (i.second == top.coordinate) {
                    store[start][i.first] = top.Dis;
                    store[i.first][start] = top.Dis;
                    break;
                }
            }
            for (auto i : top.Children(xSize, ySize)) {
                if (map[i.coordinate.x][i.coordinate.y] != '#' &&
                    !visited[i.coordinate.x][i.coordinate.y]) {
                    queue.emplace(i);
                    visited[i.coordinate.x][i.coordinate.y] = true;
                }
            }
        }
    }

    void Put(int no) {
        if (no == numbers.size()) {
            int dis = 0;
            for (int i = 0; i < numbers.size() - 1; i++) {
                dis += store[numbers[i]][numbers[i + 1]];
            }
            if (dis < shorest) {
                shorest = dis;
            }
            dis += store[numbers[numbers.size() - 1]][numbers[numbers.size()]];
            //  numbers[numbers.size()] 为 0
            if (dis < fullshorest) {
                fullshorest = dis;
            }
        }

        for (int i = no; i < int(numbers.size()); ++i) {
            swap(numbers[no], numbers[i]);
            Put(no + 1);
            swap(numbers[no], numbers[i]);
        }
    }

    void Solve() {
        while (scanf("%s", Buffer) == 1) {
            string s = Buffer;
            map.emplace_back(s);
        }
        xSize = map.size();
        ySize = map[0].size();
        for (int i = 0; i < xSize; ++i) {
            for (int j = 0; j < ySize; ++j) {
                if (isdigit(map[i][j])) {
                    points[map[i][j] - '0'] = Coordinate{i, j};
                }
            }
        }
        numSize = int(points.size());

        numbers.resize(numSize);

        store.resize(numSize);
        for (int i = 0; i < numSize; ++i) store[i].resize(numSize);
        for (int i = 0; i < numbers.size(); ++i) numbers[i] = i;
        for (int i = 0; i < numSize; ++i) ComputeDis(i);

        Put(1);
        cout << numbers.size() << endl;

        for (auto i : store) {
            for (auto j : i) {
                printf("%d ", j);
            }
            printf("\n");
        }

        printf("%d\n", shorest);
        printf("%d\n", fullshorest);
    }
};

int main() {
    Solution().Solve();
    return 0;
}