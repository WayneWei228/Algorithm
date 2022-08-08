#include <cstdio>
#include <unordered_set>
using namespace std;

int DX[4]{0, -1, 0, 1};
int DY[4]{1, 0, -1, 0};

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) {
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct Coordinate {
    int X, Y;

    bool operator==(const Coordinate& that) const {
        return X == that.X && Y == that.Y;
    }
};

struct CoordinateHash {
    size_t operator()(const Coordinate& c) const {
        return Fingerprint(c.X) + c.Y;
    }
};

typedef unordered_set<Coordinate, CoordinateHash> CoordinateSet;

struct Solution {
    int X = 0, Y = 0, Direction = 0;
    int TwiceX, TwiceY;
    bool Twice = false;
    CoordinateSet Visited;

    int Distance(int x, int y) {
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        return x + y;
    }

    void Solve() {
        while (true) {
            char turn;
            int x;
            if (scanf("%c%d, ", &turn, &x) < 2) break;
            switch (turn) {
                case 'L':
                    Direction = (Direction + 1) % 4;
                    break;
                case 'R':
                    Direction = (Direction + 3) % 4;
                    break;
            }
            for (int i = 0; i < x; ++i) {
                X += DX[Direction];
                Y += DY[Direction];
                if (!Twice && Visited.count(Coordinate{X, Y})) {
                    Twice = true;
                    TwiceX = X;
                    TwiceY = Y;
                } else {
                    Visited.emplace(Coordinate{X, Y});
                }
            }
        }
        printf("%d\n", Distance(X, Y));
        printf("%d\n", Distance(TwiceX, TwiceY));
    }
};

int main() {
    Solution().Solve();
    return 0;
}