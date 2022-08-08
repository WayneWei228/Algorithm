#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

struct CoordinateAB {
    int A, B;
};

struct CoordinateXY {
    int X, Y;

    CoordinateAB ToAB() const {
        CoordinateAB c = {X + Y, Y - X};
        return c;
    }
};

struct Obstacle {
    CoordinateAB C;
    int Cost;
};

struct Array2D {
    vector<int64> Data;
    int MinA, MinB, SizeA, SizeB;

    int64& At(int a, int b) {
        return Data[(a - MinA) * SizeB + (b - MinB)];
    }

    int64 SafeAt (int a, int b) { // 处理越界情况
        if(a < MinA) return 0;
        if(b < MinB) return 0;
        if(MinA + SizeA <= a) a = MinA + SizeA - 1; // inclusive
        if(MinB + SizeB <= b) b = MinB + SizeB - 1; 
        return At(a, b);
    }
};

struct Solution {
    int W, H, D, N;
    vector<Obstacle> Ob;
    Array2D Cost; // 二维地图

    int64 CostIn(int minA, int maxA, int minB, int maxB) {
        int c00 = Cost.SafeAt(minA - 1, minB - 1);
        int c01 = Cost.SafeAt(minA - 1, maxB);
        int c10 = Cost.SafeAt(maxA, minB - 1);
        int c11 = Cost.SafeAt(maxA, maxB);
        return c11 - c01 - c10 + c00;
    }

    void Sovle() {
        scanf("%d%d%d%d", &W, &H, &D, &N);
        Ob.resize(N);
        for(int i = 0; i < N; ++i) {
            CoordinateXY c;
            scanf("%d%d%d", &c.X, &c.Y, &Ob[i].Cost);
            Ob[i].C = c.ToAB();
        }
        int minA = numeric_limits<int>::max();
        int maxA = numeric_limits<int>::min();
        int minB = numeric_limits<int>::max();
        int maxB = numeric_limits<int>::min();

        for(int i = 0; i < N; i++) {  // 确定A，B
            if(Ob[i].C.A < minA) minA = Ob[i].C.A;
            if(maxA < Ob[i].C.A) maxA = Ob[i].C.A;
            if(Ob[i].C.B < minB) minB = Ob[i].C.B;
            if(maxB < Ob[i].C.B) maxB = Ob[i].C.B;
        }

        Cost.MinA = minA;
        Cost.SizeA = maxA - minA + 1;
        Cost.MinB = minB;
        Cost.SizeB = maxB - minB + 1;
        Cost.Data.resize(Cost.SizeA * Cost.SizeB); // 确定地图大小

        for(int i = 0; i < N; i++) {
            Cost.At(Ob[i].C.A, Ob[i].C.B) += Ob[i].Cost; // 惩罚地点加上惩罚
        }

        for(int i = Cost.MinA; i < Cost.MinA + Cost.SizeA; ++i) {
            for(int j = Cost.MinB; j < Cost.MinB + Cost.SizeB; ++j) {
                Cost.At(i, j) += Cost.SafeAt(i - 1, j);
            }
        }

        for(int i = Cost.MinA; i < Cost.MinA + Cost.SizeA; ++i) {
            for(int j = Cost.MinB; j < Cost.MinB + Cost.SizeB; ++j) {
                Cost.At(i, j) += Cost.SafeAt(i, j - 1);
            }
        }

        int64 answer = numeric_limits<int64>::max();
        for(int i = D; i <= W - D; i++) {
            for(int j = D; j <= H - D; j++) {
                CoordinateXY coordinate = {i, j};
                CoordinateAB c = coordinate.ToAB();
                int64 cost = CostIn(c.A - D, c.A + D, c.B - D, c.B + D);
                if (cost < answer) answer = cost;
            }
        }
        print("%lld\n", answer);
    }
};



int main () {
    Solution().Slove();
    return 0;
}