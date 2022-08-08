#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char Buffer[500];

// const char grid1[3][4] = {"123", {'4', '5', '6'}, {'7', '8', '9'}};

// string grid2[] = {"0000000", "0001000", "0023400", "0567890",
// "00ABC00", "000D000", "0000000"};

const char* grid2[7] = {"0000000", "0001000", "0023400", "0567890",
                        "00ABC00", "000D000", "0000000"};
// const char* 常量字符串
// char* 类似 string, 操作较烦, 但是作为常量没问题
// const char* a = "abcd";
// vector不好当全局变量
// 原因: vector 析构时机不确定
// 析构: 释放内存 delete()
// 局部变量出了范围域自动析构
// LURD

struct Instruction {
    int x, y;

    char Do1(const string& input) {
        for (int i = 0; i < input.size(); ++i) {
            switch (input[i]) {
                case 'L':
                    y = max(0, y - 1);
                    break;
                case 'U':
                    x = max(0, x - 1);
                    break;
                case 'R':
                    y = min(2, y + 1);
                    break;
                case 'D':
                    x = min(2, x + 1);
                    break;
            }
        }

        return x * 3 + y + '1';  // x * 3 + y + '1'
    }

    // char Do2(const string& input, const vector<string>& grid2) {
    //     for (int i = 0; i < input.size(); ++i) {
    //         switch (input[i]) {
    //             case 'L':
    //                 (grid2[x][y - 1] == '0') ? : --y;
    //                 break;
    //             case 'U':
    //                 (grid2[x - 1][y] == '0') ? : --x;
    //                 break;
    //             case 'R':
    //                 (grid2[x][y + 1] == '0') ? : ++y;
    //                 break;
    //             case 'D':
    //                 (grid2[x + 1][y] == '0') ? : ++x;
    //                 break;
    //         }
    //     }
    //     cout << "x " << x << " y " << y << endl;
    //     return grid2[x][y];
    // }
    char Do2(const string& input) {
        for (int i = 0; i < input.size(); ++i) {
            switch (input[i]) {
                case 'L':
                    (grid2[x][y - 1] == '0') ?: --y;
                    break;
                case 'U':
                    (grid2[x - 1][y] == '0') ?: --x;
                    break;
                case 'R':
                    (grid2[x][y + 1] == '0') ?: ++y;
                    break;
                case 'D':
                    (grid2[x + 1][y] == '0') ?: ++x;
                    break;
            }
        }
        return grid2[x][y];
    }
};

struct Solution {
    vector<Instruction> instructions1, instructions2;
    vector<string> Input;

    void Solve() {
        while (true) {
            if (scanf("%s", Buffer) < 1) break;
            Input.emplace_back(Buffer);
        }
        // vector<string> grid2;
        // grid2.emplace_back("0000000");
        // grid2.emplace_back("0001000");
        // grid2.emplace_back("0023400");
        // grid2.emplace_back("0567890");
        // grid2.emplace_back("00ABC00");
        // grid2.emplace_back("000D000");
        // grid2.emplace_back("0000000");

        instructions1.resize(Input.size());
        instructions2.resize(Input.size());
        instructions1[0].x = instructions1[0].y = 1;
        instructions2[0].x = 3;
        instructions2[0].y = 1;
        string answer1 = "";
        string answer2 = "";
        for (int i = 0; i < Input.size(); ++i) {
            answer1 += instructions1[i].Do1(Input[i]);
            // answer2 += instructions2[i].Do2(Input[i], grid2);
            answer2 += instructions2[i].Do2(Input[i]);
            if (i == Input.size() - 1) break;
            instructions1[i + 1].x = instructions1[i].x;
            instructions1[i + 1].y = instructions1[i].y;
            instructions2[i + 1].x = instructions2[i].x;
            instructions2[i + 1].y = instructions2[i].y;
        }
        printf("%s\n", answer1.c_str());
        printf("%s\n", answer2.c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}