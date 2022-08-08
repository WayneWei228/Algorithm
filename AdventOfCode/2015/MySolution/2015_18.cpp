#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

char Buffer[100];
struct Solution {
    vector<vector<char>> grid;
    int direction[8][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};
    int answer1 = 0, answer2 = 0;


    vector<vector<char>> calculate1(const vector<vector<char>>& input) {

        vector<vector<char>> newGrid;

        newGrid.resize(100); // 初始化
        for(int i = 0; i < input.size(); i++) {
            newGrid[i].resize(100);
        }

        for(int i = 0; i < input.size(); i++) {
            for(int j = 0; j < input[0].size(); j++) {
                int arround = 0;
                for(int k = 0; k < 8; k++) {
                    int next_x = i + direction[k][0];
                    int next_y = j + direction[k][1];
                    if(next_x < 0 || next_y < 0 || next_x >= 100 || next_y >= 100) continue;
                    if(input[next_x][next_y] == '#') arround++;
                }
                if(input[i][j] == '#' && (arround == 3 || arround == 2)) {
                    newGrid[i][j] = '#';
                } else if(input[i][j] == '.' && arround == 3) {
                    newGrid[i][j] = '#';
                } else {
                    newGrid[i][j] = '.';
                }
            }
        }
        return newGrid;
    }


    vector<vector<char>> calculate2 (const vector<vector<char>>& input) {

        vector<vector<char>> newGrid;

        newGrid.resize(100); // 初始化
        for(int i = 0; i < input.size(); i++) {
            newGrid[i].resize(100);
        }

        for(int i = 0; i < input.size(); i++) {
            for(int j = 0; j < input[0].size(); j++) {
                if((i == 0 && j == 0) || (i == 0 && j == 99) || (i == 99 && j == 0) || (i == 99 && j == 99)) {
                    newGrid[i][j] = '#';
                    continue;
                }
                int arround = 0;
                for(int k = 0; k < 8; k++) {
                    int next_x = i + direction[k][0];
                    int next_y = j + direction[k][1];
                    if(next_x < 0 || next_y < 0 || next_x >= 100 || next_y >= 100) continue;
                    if(input[next_x][next_y] == '#') arround++;
                }
                if(input[i][j] == '#' && (arround == 3 || arround == 2)) {
                    newGrid[i][j] = '#';
                } else if(input[i][j] == '.' && arround == 3) {
                    newGrid[i][j] = '#';
                } else {
                    newGrid[i][j] = '.';
                }
            }
        }
        return newGrid;
    }
    void Solve() {
        int i = 0;
        grid.resize(100);
        for(int i = 0; i < 100; i++) {
            grid[i].resize(100);
        }

        while(true) {
            if(scanf("%s", Buffer) < 1) break;
            for(int j = 0; j < 100; j++) {
                grid[i][j] = Buffer[j];
            }
            i++;
        }

        vector<vector<char>> question1(grid);
        for(int i = 0; i < 100; i++) {
            question1 = calculate1(question1);
        }

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(question1[i][j] == '#') {
                    answer1++;
                }
            }
        }

        printf("%d\n", answer1);

        vector<vector<char>> question2(grid);
        for(int i = 0; i < 100; ++i) {
            question2 = calculate2(question2);
        }

        for(int i = 0; i < question2.size(); i++) {
            for(int j = 0; j < question2[0].size(); ++j) {
                if(question2[i][j] == '#') {
                    answer2++;
                }
            }
        }

        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}