#include <cstdio>
#include <limits>
#include <vector>
using namespace std;

typedef long long int64;

struct CoordinateAB {
    int A, B;
};

struct CoordinateXY {
    int X, Y;

    // 顺时针旋转45度
    CoordinateAB ToAB() const { return {X + Y, Y - X}; }
};

struct Obstacle {
    CoordinateAB C;
    int cost;
};

struct Array2D {
    int MinA, MinB, SizeA, SizeB;
    vector<int64> Data;

    int64& At(int a, int b) {
        return Data[(a - MinA) * SizeB + (b - MinB)];
    }

    int64 SafeAt(int a, int b) {
        if (a < MinA || b < MinB) return 0;
        return At(min(a, MinA + SizeA - 1), min(b, MinB + SizeB - 1));
    }
};

struct Solution {
    int W, H, D, N;
    vector<Obstacle> Ob;
    Array2D Cost;

    int64 CostIn(int minA, int maxA, int minB, int maxB) {
        int c00 = Cost.SafeAt(minA - 1, minB - 1);
        int c01 = Cost.SafeAt(minA - 1, maxB);
        int c10 = Cost.SafeAt(maxA, minB - 1);
        int c11 = Cost.SafeAt(maxA, maxB);
        return c11 - c01 - c10 + c00;
    }

    void Solve() {
        scanf("%d%d%d%d", &W, &H, &D, &N);
        Ob.resize(N);
        for (int i = 0; i < N; i++) {
            CoordinateXY c;
            scanf("%d%d%d", &c.X, &c.Y, &Ob[i].cost);
            Ob[i].C = c.ToAB();
        }
        int MinA = numeric_limits<int>::max();
        int MaxA = numeric_limits<int>::min();
        int MinB = numeric_limits<int>::max();
        int MaxB = numeric_limits<int>::min();
        for (int i = 0; i < N; i++) {
            if (Ob[i].C.A < MinA) MinA = Ob[i].C.A;
            if (Ob[i].C.A > MaxA) MaxA = Ob[i].C.A;
            if (Ob[i].C.B < MinA) MinA = Ob[i].C.B;
            if (Ob[i].C.B > MaxA) MaxA = Ob[i].C.B;
        }
        Cost.MinA = MinA;
        Cost.SizeA = MaxA - MinA + 1;
        Cost.MinB = MinB;
        Cost.SizeB = MaxB - MinB + 1;
        Cost.Data.resize(Cost.SizeA * Cost.SizeB);
        for (int i = 0; i < N; i++) {
            Cost.At(Ob[i].C.A, Ob[i].C.B) += Ob[i].cost;
        }
        for (int i = MinA; i <= MaxA; i++) {
            for (int j = MinB; j <= MaxB; j++) {
                Cost.At(i, j) += Cost.SafeAt(i - 1, j);
            }
        }
        for (int i = MinA; i <= MaxA; i++) {
            for (int j = MinB; j <= MaxB; j++) {
                Cost.At(i, j) += Cost.SafeAt(i, j - 1);
            }
        }
        int64 ans = numeric_limits<int>::max();
        for (int i = D; i <= W - D; i++) {
            for (int j = D; j <= H - D; j++) {
                CoordinateAB c = CoordinateXY{i, j}.ToAB();
                int64 cost = CostIn(c.A - D, c.A + D, c.B - D, c.B + D);
                if (cost < ans) ans = cost;
            }
        }
        printf("%lld\n", ans);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}