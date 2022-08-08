#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

// R5, L5, R5, R3

// north 0, east 1, south 2, west 3;

struct Coordinate {
    int x, y;
    int direction;
};

struct Instructions {
    char dic;
    int steps;
};

struct Solution {
    vector<Instructions> V;
    int grid[1000][1000];
    Coordinate Walk(const Coordinate& input) {
        Coordinate no(input);
        for (auto& instruction : V) {
            if (instruction.dic == 'R') {
                (no.direction < 3) ? ++no.direction : no.direction = 0; 
            } else {
                (no.direction > 0) ? --no.direction : no.direction = 3; 
            }
            switch (no.direction) {
                case 0:
                    no.y += instruction.steps;
                    break;
                case 1:
                    no.x += instruction.steps;
                    break;
                case 2: 
                    no.y -= instruction.steps;
                    break;
                case 3: 
                    no.x -= instruction.steps;
                    break;
            }
            cout << no.x << " " << no.y << endl;
        }
        return no;
    }

    Coordinate Walk2(const Coordinate& input) {
        Coordinate no(input);
        for (auto& instruction : V) {
            if (instruction.dic == 'R') {
                (no.direction < 3) ? ++no.direction : no.direction = 0; 
            } else {
                (no.direction > 0) ? --no.direction : no.direction = 3; 
            }
            switch (no.direction) {
                case 0:
                    for (int i = 1; i <= instruction.steps; i++) {
                        grid[no.x][no.y + i]++;
                        if (grid[no.x][no.y + i] == 2) return Coordinate{no.x, no.y + i};
                    } 
                    no.y += instruction.steps;
                    break;
                case 1:
                    for (int i = 1; i <= instruction.steps; i++) {
                        grid[no.x + i][no.y]++;
                        if (grid[no.x + i][no.y] == 2) return Coordinate{no.x + i, no.y};
                    } 
                    no.x += instruction.steps;
                    break;
                case 2: 
                    for (int i = 1; i <= instruction.steps; i++) {
                        grid[no.x][no.y - i]++;
                        if (grid[no.x][no.y - i] == 2) return Coordinate{no.x, no.y - i};
                    } 
                    no.y -= instruction.steps;
                    break;
                case 3: 
                    for (int i = 1; i <= instruction.steps; i++) {
                        grid[no.x - i][no.y]++;
                        if (grid[no.x - i][no.y] == 2) return Coordinate{no.x - i, no.y};
                    }
                    no.x -= instruction.steps;
                    break;
            }
        }
        return no;
    }

    void Solve() {
        while (true) {
            char read_char;
            int d;
            if (scanf("%c%d, ", &read_char, &d) < 2) break;
            V.emplace_back(Instructions{read_char, d});
        }

        memset(grid, 0, sizeof(grid));
        Coordinate now1{0, 0, 0};
        Coordinate ans1 = Walk(now1);
        int distance1 = abs(ans1.x - 0) + abs(ans1.y - 0);
        printf("%d\n", distance1);

        Coordinate now2{500, 500, 0};
        grid[500][500] = 1;
        Coordinate ans2 = Walk2(now2);
        int distance2 = abs(ans2.x - 500) + abs(ans2.y - 500);
        printf("%d\n", distance2);
        
    }
};

int main() {
    Solution().Solve();
    return 0;
}