#include <algorithm>
#include <cstdio>
#include <functional>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];

struct Box {
    int X1, Y1, X2, Y2;

    static Box Parse(const string& input) { // 不成功就不会刷新，所以一直保留成功的
        Box b;
        sscanf(input.c_str(),                   // 
               "toggle %d,%d through %d,%d",    //
               &b.X1, &b.Y1, &b.X2, &b.Y2);     //
        sscanf(input.c_str(),                   //
               "turn on %d,%d through %d,%d",   //
               &b.X1, &b.Y1, &b.X2, &b.Y2);     //
        sscanf(input.c_str(),                   //
               "turn off %d,%d through %d,%d",  //
               &b.X1, &b.Y1, &b.X2, &b.Y2);     //
        return b;
    }
};

const int N = 1000;

int ParseOpType(const string& input) {
    int nchars = 0;
    sscanf(input.c_str(), "toggle%n", &nchars);
    if (nchars != 0) return -1; // -1 表示 toggle
    sscanf(input.c_str(), "turn on%n", &nchars);
    return nchars != 0; // true false 只有 1, 0 表示
                        // 0 表示 false, 表示 turn off
                        // 1 表示 true, 表示 turn on
}

struct Op1 {
    int operator()(int type, int x) {
        switch (type) {
            case -1:
                return 1 - x; // 如果是-1 就是反转灯，0 变 1， 1 变 0
        }
        return type; // 如果是 0 就是关灯， 如果是 1 就是亮灯
    }
};

struct Op2 {
    int operator()(int type, int x) {
        switch (type) {
            case -1: // 如果是 -1 就 + 2
                return x + 2;
            case 1: // 如果是 1 就 + 1
                return x + 1;
        }
        return max(0, x - 1); // 如果是 -1 就 -1 但是不能比 0 
    }
};

struct Grid {
    int Light[N][N];

    Grid() : Light{} {}

    template <typename Op>
    void Operate(int type, const Box& box) {
        for (int i = box.X1; i <= box.X2; ++i) {
            for (int j = box.Y1; j <= box.Y2; ++j) {
                Light[i][j] = Op()(type, Light[i][j]);
            }
        }
    }

    int LightSum() {
        int answer = 0;
        for (const auto& i : Light) {
            for (const auto& j : i) {
                answer += j;
            }
        }
        return answer;
    }
};

struct Solution {
    vector<string> V;

    template <class Op>
    int Compute() {
        Grid grid;
        for (const string& i : V) {
            auto type = ParseOpType(i);
            auto box = Box::Parse(i);
            grid.Operate<Op>(type, box);
        }
        return grid.LightSum();
    }
    
    void Solve() {
        while (true) {
            if (scanf("%[^\n]\n", Buffer) < 1) break; // 输入整行
            V.push_back(Buffer);
        }
        printf("%d\n", Compute<Op1>());
        printf("%d\n", Compute<Op2>());
    }
};

int main() {
    freopen("/Users/wayne_tx/Desktop/algorithm/AdventOfCode/2015/题解/2015_6.txt", "r", stdin);
    Solution().Solve();
    fclose(stdin);
    return 0;
}
