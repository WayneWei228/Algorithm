#include <cstdio>
#include <cstdlib>
#include <limits>
#include <vector>
using namespace std;

typedef long long int64;

struct Block {
    int X0, Y0, X1, Y1;
};

struct Plan {
    int64 Answer;
    int X, Y;

    bool operator<(const Plan& that) const {
        if (Answer != that.Answer) return Answer < that.Answer;
        if (X != that.X) return X < that.X;
        if (Y != that.Y) return Y < that.Y;
        return false;
    }
};

struct Solution {
    int B;
    Plan Answer{numeric_limits<int64>::max()};
    vector<Block> Blocks;

    void Solve(int caseNo) {
        scanf("%d", &B);
        Blocks.resize(B);
        for (Block& i : Blocks) {
            scanf("%d%d%d%d", &i.X0, &i.Y0, &i.X1, &i.Y1);
        }
        for (const Block& i : Blocks) {
            for (int x = i.X0; x <= i.X1; ++x) {
                for (int y = i.Y0; y <= i.Y1; ++y) {
                    // plan 所有点到此点的距离和
                    Plan plan{DistanceSum(x, y), x, y};
                    if (plan < Answer) Answer = plan;
                }
            }
        }
        printf("Case #%d: %d %d %lld\n",  //
               caseNo, Answer.X, Answer.Y, Answer.Answer);
    }

    int64 DistanceSum(int64 x, int64 y) {
        int64 answer = 0;
        for (const Block& i : Blocks) {
            // 该点横坐标到这一block的横轴距离之和 * 横数
            answer += Compute(i.X0, i.X1, x) * (i.Y1 - i.Y0 + 1);
            // 该点纵坐标到这一block的纵轴距离之和 * 列数
            answer += Compute(i.Y0, i.Y1, y) * (i.X1 - i.X0 + 1);
        }
        return answer;
    }

    int64 Compute(int64 c0, int64 c1, int64 c) {
        // 该block不符合条件，左边比右边大
        if (c1 < c0) return 0; // 可注释掉
        // 如果c在block外面，可直接计算, 外面包括两端
        if (c <= c0 || c1 <= c) return ComputeOut(c0, c1, c);
        // 在block里面，分成两部分
        return ComputeOut(c0, c, c) + ComputeOut(c + 1, c1, c);
    }

    // 一维上的点边之和
    // 点到点距离为整数，故点到边距离为整数
    // 所以不可能出现0.5的情况
    int64 ComputeOut(int64 c0, int64 c1, int64 c) {
        int64 count = c1 - c0 + 1;
        // 平均距离
        int64 average2 = abs(c0 + c1 - (c + c));
        return count * average2 / 2;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}