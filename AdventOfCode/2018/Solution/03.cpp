#include <cstdio>
#include <vector>
using namespace std;

struct Box {
    int X0, X1, Y0, Y1;
};

struct Solution {
    vector<Box> Input;
    vector<vector<int>> Board;

    int Solve1() {
        int answer = 0;
        for (const auto& i : Board) {
            for (int j : i) {
                if (2 <= j) ++answer;
            }
        }
        return answer;
    }

    bool IsClear(const Box& b) {
        for (int i = b.X0; i < b.X1; ++i) {
            for (int j = b.Y0; j < b.Y1; ++j) {
                if (1 < Board[i][j]) return false;
            }
        }
        return true;
    }

    int Solve2() {
        for (int i = 0; i < Input.size(); ++i) {
            if (IsClear(Input[i])) return i + 1;
        }
        return 0;
    }

    void Solve() {
        while (true) {
            Box b;
            if (scanf("#%*d @ %d,%d: %dx%d ",  //
                      &b.X0, &b.Y0, &b.X1, &b.Y1) < 4) {
                break;
            }
            b.X1 += b.X0;
            b.Y1 += b.Y0;
            Input.emplace_back(b);
        }
        Board.resize(1000);
        for (int i = 0; i < 1000; ++i) Board[i].resize(1000);
        for (const Box& i : Input) {
            for (int j = i.X0; j < i.X1; ++j) {
                for (int k = i.Y0; k < i.Y1; ++k) {
                    ++Board[j][k];
                }
            }
        }
        printf("%d\n", Solve1());
        printf("%d\n", Solve2());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
