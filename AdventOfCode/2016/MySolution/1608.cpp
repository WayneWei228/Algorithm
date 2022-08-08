#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
rect 3x2
rotate column x=1 by 1
rotate row y=0 by 4
*/

char Buffer[80];
int X, Y;

struct Operation {
    int rect_x, rect_y;
    int roCol, roRow;
    int step;
    int type;

    vector<vector<char>> Rect(vector<vector<char>>& input) {  //
        for (int i = 0; i < rect_x; ++i) {
            for (int j = 0; j < rect_y; ++j) {
                input[i][j] = '#';
            }
        }
        return input;
    }

    vector<vector<char>> RotateCol(vector<vector<char>>& input) {
        vector<char> next(int(input.size()), '.');
        // for (auto& i : next) {
        //     for (auto& j : i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < int(input.size()); ++i) {
            if (input[i][roCol] == '#') {
                int new_x = (i + step) % (int(input.size()));
                next[new_x] = '#';
            }
        }
        for (int i = 0; i < int(next.size()); ++i) {
            input[i][roCol] = next[i];
        }
        return input;
    }

    vector<vector<char>> RotateRow(vector<vector<char>>& input) {
        vector<char> next(int(input[0].size()), '.');
        for (int j = 0; j < int(input[0].size()); ++j) {
            if (input[roRow][j] == '#') {
                int new_y = (j + step) % int(input[0].size());
                next[new_y] = '#';
            }
        }
        for (int i = 0; i < int(next.size()); ++i) {
            input[roRow][i] = next[i];
        }
        return input;
    }

    Operation(const string& input) {
        if (sscanf(input.c_str(), "rect %dx%d",  //
                   &rect_y, &rect_x) == 2)
            type = 0;
        if (sscanf(input.c_str(), "rotate column x=%d by %d",  //
                   &roCol, &step) == 2)
            type = 1;
        if (sscanf(input.c_str(), "rotate row y=%d by %d",  //
                   &roRow, &step) == 2)
            type = 2;
    }
};

struct Solution {
    // vector<vector<char>> grid(6, vector<char>(50, '.'));
    // vector<vector<char>> grid;
    vector<Operation> Operations;

    void Solve() {
        int X = 6, Y = 50;
        vector<vector<char>> grid(X, vector<char>(Y, '.'));
        // memset(grid, '.', sizeof(grid));

        while (true) {
            if (scanf("%[^\n]\n", Buffer) < 1) break;
            Operations.emplace_back(Buffer);
        }

        for (auto i : Operations) {
            switch (i.type) {
                case 0:
                    grid = i.Rect(grid);
                    break;
                case 1:
                    grid = i.RotateCol(grid);
                    break;
                case 2:
                    grid = i.RotateRow(grid);
                    break;
            }
        }
        int ans1 = 0;

        for (auto& i : grid) {
            for (auto& j : i) {
                cout << j << " ";
                if (j == '#') ans1++;
            }
            cout << endl;
        }
        // AFBUPZBJPS
        printf("%d\n", ans1);
    }
};

int main() {
    Solution().Solve();
    return 0;
}