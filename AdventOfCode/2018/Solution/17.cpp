#include <cstdio>
#include <limits>
#include <unordered_map>
using namespace std;

struct Coordinate {
    int X, Y;

    bool operator==(const Coordinate& that) const {
        return X == that.X && Y == that.Y;
    }
};

struct CoordinateHash {
    size_t operator()(const Coordinate& c) const {
        return c.X * 9875321 + c.Y;
    }
};

struct Solution {
    enum Data { Empty, ActiveWater, DeadWater, Obstacle };
    unordered_map<Coordinate, Data, CoordinateHash> B;
    int Answer0 = 0, Answer1 = 0;
    int MinY = numeric_limits<int>::max(), MaxY = 0;

    bool VisitDead(const Coordinate& c) {
        switch (B[c]) {
            case Empty:
                break;
            case ActiveWater:
                return false;
            case DeadWater:
            case Obstacle:
                return true;
        }
        if (MaxY < c.Y) return false;
        if (MinY <= c.Y) ++Answer0;
        B[c] = DeadWater;
        Coordinate next{c.X, c.Y + 1};
        if (!VisitDead(next)) {
            MakeActive(next);
            return false;
        }
        Coordinate nextL{c.X - 1, c.Y}, nextR{c.X + 1, c.Y};
        return VisitDead(nextL) & VisitDead(nextR);
    }

    void MakeActive(const Coordinate& c) {
        if (B[c] != DeadWater) return;
        B[c] = ActiveWater;
        if (MinY <= c.Y) ++Answer1;
        MakeActive(Coordinate{c.X - 1, c.Y});
        MakeActive(Coordinate{c.X + 1, c.Y});
    }

    void Solve() {
        char c;
        int v, u1, u2;
        while (scanf("%c=%d, %*c=%d..%d ", &c, &v, &u1, &u2) == 4) {
            switch (c) {
                case 'x':
                    for (int i = u1; i <= u2; ++i) {
                        B[Coordinate{v, i}] = Obstacle;
                        if (i < MinY) MinY = i;
                        if (MaxY < i) MaxY = i;
                    }
                    break;
                case 'y':
                    for (int i = u1; i <= u2; ++i) {
                        B[Coordinate{i, v}] = Obstacle;
                        if (v < MinY) MinY = v;
                        if (MaxY < v) MaxY = v;
                    }
                    break;
            }
        }
        // map 默认为 0 即 Empty
        VisitDead(Coordinate{500, 0});
        printf("%d\n", Answer0);
        printf("%d\n", Answer0 - Answer1);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
