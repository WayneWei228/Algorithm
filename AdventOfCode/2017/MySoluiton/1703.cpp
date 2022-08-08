#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Coordinate {
    int x, y;
    int value;
};

int Next[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int around[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                    {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
struct Solution {
    int Input;
    vector<Coordinate> store;
    vector<vector<int>> map;
    int answer1 = 0, answer2 = 0;

    int getValue(const Coordinate&& input) {
        int value = 0;
        for (int i = 0; i < 8; ++i) {
            Coordinate next(input);
            next.x += around[i][0] + 50;
            next.y += around[i][1] + 50;
            value += map[next.x][next.y];
        }
        return value;
    }

    void Compute(bool quesiton1, bool question2) {
        map.resize(100);
        for (int i = 0; i < 100; ++i) map[i].resize(100);
        int direction = 0, steps = 1, no = 1;
        store.emplace_back(Coordinate{0, 0, 1});
        map[50][50] = 1;
        while (!quesiton1 || !question2) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < steps; ++j) {
                    Coordinate next = store.back();
                    next.x += Next[direction][0];
                    next.y += Next[direction][1];
                    next.value = ++no;
                    store.emplace_back(next);
                    if (no == Input) {
                        answer1 = abs(store.back().x - 0) +
                                  abs(store.back().y - 0);
                        quesiton1 = true;
                    }
                    if (!question2) {
                        int value = getValue(move(next));
                        map[next.x + 50][next.y + 50] = value;
                        if (value > Input) {
                            answer2 = value;
                            question2 = true;
                        }
                    }
                }
                direction = (direction + 1) % 4;
            }
            steps++;
        }
    }

    void Solve() {
        scanf("%d", &Input);
        Compute(false, false);
        printf("%d\n", answer1);
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}